#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int parity = 0;
    for(int i = 0; i < n; ++i) {
        parity = (parity + a[i]) % 2;
    }
    auto chk = [&](int p) {
        if(p > n) return -1;
        if(p < 0) return 1;
        assert(p % 2 == parity);
        vector<int> b = a;
        int ins = 0;
        for(int i = 0; i < n; ++i) {
            if(b[i] <= p) {
                b.insert(b.begin() + i, p);
                ins = 1;
                break;
            }
        }
        if(!ins) b.push_back(p);
        int ok = 1;
        ll sum = 0;

        ll res = 0;
        int j = n;
        for(int i = 0; i <= n; ++i) {
            // \sum min(i + 1, d[j]) , j > i
            while(j > i && b[j] <= i) {
                res += b[j];
                --j;
            }
            ll suf = res + 1ll * (i + 1) * max(0, j - i);
            sum += b[i];
            if(sum > 1ll * i * (i + 1) + suf) {
                if(b[i] > p) return 1;
                else return -1;
            }
        }
        return 0;
    };
    int lo = 0, hi = n / 2;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        int tmp = chk(2 * mid + parity);
        if(tmp <= 0) hi = mid;
        else lo = mid + 1;
    }
    if(chk(2 * lo + parity)) return cout << -1 << endl, 0;
    int l = lo * 2 + parity;
    lo = 0, hi = n / 2;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int tmp = chk(2 * mid + parity);
        if(tmp >= 0) lo = mid;
        else hi = mid - 1;
    }
    int r = lo * 2 + parity;
    for(int i = l; i <= r; i += 2) {
        cout << i << " ";
    }
    cout << endl;
}