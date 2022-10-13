#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()

const int block_sz = sqrt(200001); //ch for testing
vector<long long> pref(300001);
vector<int> pref_num(300001);
vector<int> to_upd;
vector<bool> vis(300001);

vector<long long> naive(vector<int> &x) {
    int n = (int) x.size();
    vector<long long> ans(n);
    for(int k = 0; k < n; k++) {
        long long curr = 0;
        for(int j = 0; j <= k; j++)
            for(int i = 0; i <= k; i++)
                curr += x[i] % x[j];
        ans[k] = curr;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    vector<bool> take(300001, false);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mx = 300000;
    vector<long long> p(n);
    vector<int> sq(n);
    for(int i = 0; i < n; i++) sq[i] = sqrt(a[i]);
    p[0] = 0;
    long long sum = 0LL;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        to_upd.push_back(a[i]);
        if(i % block_sz == 0) {
            for(int j = 0; j <= 300000; j++)
                pref[j] = 0, pref_num[j] = 0;
            for(int j = 0; j <= i; j++) {
                pref[a[j]] += a[j];
                pref_num[a[j]]++;
            }
            for(int j = 1; j <= 300000; j++) {
                pref[j] = pref[j - 1] + pref[j];
                pref_num[j] = pref_num[j - 1] + pref_num[j];
            }
            to_upd.clear();
        }
        if(i > 0)
            p[i] = p[i - 1];
        p[i] += sum;
        for(int j = 1; j <= mx / a[i]; j++) {
            int st = j * a[i], en = (j + 1) * a[i] - 1;
            en = min(en, 300000), st = min(st, 300000);
            long long x = ((pref_num[en] - pref_num[st - 1]) * 1LL * j) * 1LL * a[i];
            p[i] -= x;
        }
        
        p[i] += a[i] * 1LL * (i + 1);
        //replace below with sqrt
        for(int div = 1; div <= sq[i]; div++) {
            int st = (a[i] + div + 1) / (div + 1), en = a[i] / div;
            if(st > en) continue;
            p[i] -= pref[en] * 1LL * div;
            if(st > 0) p[i] += pref[st - 1] * 1LL * div;
        }
        for(int x = 1; x <= sq[i]; x++) {
            if(a[i] / x <= sq[i]) break;
            int st = x, en = x;
            p[i] -= (pref_num[en] - pref_num[st - 1]) * 1LL * (a[i] / x) * 1LL * x;
        }
        for(int x : to_upd) {
            p[i] -= (a[i] / x) * 1LL * x;
            p[i] -= (x / a[i]) * 1LL * a[i];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}