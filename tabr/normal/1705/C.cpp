#include <bits/stdc++.h>
using namespace std;
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
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<long long> l(c), r(c);
        for (int i = 0; i < c; i++) {
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;
        }
        vector<long long> sz(c + 1);
        sz[0] = (int) s.size();
        for (int i = 0; i < c; i++) {
            sz[i + 1] = sz[i] + r[i] - l[i] + 1;
        }
        while (q--) {
            long long k;
            cin >> k;
            k--;
            for (int i = c - 1; i >= 0; i--) {
                if (k >= sz[i]) {
                    k -= sz[i];
                    k += l[i];
                }
            }
            cout << s[k] << '\n';
        }
    }
    return 0;
}