#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k = 1e9;
        cin >> n;
        vector<int> p(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<bool> used(n);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            vector<int> t(1, i);
            while (p[t.back()] != i) {
                t.emplace_back(p[t.back()]);
                used[t.back()] = true;
            }
            int mx = t.size();
            vector<int> pp(1, 1);
            for (int j = 2; j * j <= mx; j++) {
                if (mx % j == 0) {
                    pp.emplace_back(j);
                    if (j * j != mx) {
                        pp.emplace_back(mx / j);
                    }
                }
            }
            sort(pp.begin(), pp.end());
            for (int j : pp) {
                if (mx % j != 0) continue;
                vector<int> s(j, -1);
                for (int l = 0; l < mx; l++) {
                    int x = t[l];
                    if (s[l % j] == -1) {
                        s[l % j] = c[x];
                    } else if (s[l % j] != c[x]) {
                        s[l % j] = -2;
                    }
                }
                bool ok = false;
                for (int l = 0; l < j; l++) {
                    if (s[l] >= 0) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    k = min(k, j);
                    break;
                }
            }
            k = min(k, mx);
        }
        cout << k << endl;
    }
    return 0;
}