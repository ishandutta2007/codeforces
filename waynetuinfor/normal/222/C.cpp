#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
int dv[maxn], a[maxn], b[maxn];
vector<int> ca, cb, lim;
bool v[maxn];
vector<int> pr;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) v[i] = true, dv[i] = pr.size(), pr.push_back(i);
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            dv[i * pr[j]] = j;
            if (i % pr[j] == 0) break;
        }
    } 
}

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a *= a) if (n & 1) ret *= a;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    ca.resize(pr.size()); cb.resize(pr.size());
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> a[i]; tmp = a[i];
        while (tmp > 1) {
            int d = dv[tmp];
            while (tmp % pr[d] == 0) tmp /= pr[d], ++ca[d];
        }
    }
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> b[i]; tmp = b[i];
        while (tmp > 1) {
            int d = dv[tmp];
            while (tmp % pr[d] == 0) tmp /= pr[d], ++cb[d];
        }
    }
    for (int i = 0; i < pr.size(); ++i) {
        int d = min(ca[i], cb[i]);
        ca[i] -= d; cb[i] -= d;
    }
    vector<int> va, vb;
    for (int i = 0; i < n; ++i) {
        int t = 1;
        while (a[i] > 1) {
            int d = dv[a[i]];
            while (a[i] % pr[d] == 0) {
                if (ca[d] > 0) --ca[d], t *= pr[d];
                a[i] /= pr[d];
            }
        }
        va.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        int t = 1;
        while (b[i] > 1) {
            int d = dv[b[i]];
            while (b[i] % pr[d] == 0) {
                if (cb[d] > 0) --cb[d], t *= pr[d];
                b[i] /= pr[d];
            }
        }
        vb.push_back(t);
    }
    if (va.size() == 0) va.push_back(1); if (vb.size() == 0) vb.push_back(1);
    sort(va.begin(), va.end()); sort(vb.begin(), vb.end());
    cout << va.size() << ' ' << vb.size() << endl;
    for (int i : va) cout << i << ' '; cout << endl;
    for (int i : vb) cout << i << ' '; cout << endl;
    return 0;
}