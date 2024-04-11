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
        string s;
        cin >> s;
        int n = (int) s.size();
        int bal = 0;
        vector<int> q;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                bal++;
            } else if (s[i] == ')') {
                bal--;
            } else {
                q.emplace_back(i);
            }
        }
        auto t = s;
        auto u = s;
        int sz = (int) q.size();
        if (n % 2 == 1 || abs(bal) > sz) {
            cout << "NO" << '\n';
            continue;
        }
        int c0 = (sz - bal) / 2;
        int c1 = sz - c0;
        for (int i = 0; i < c0; i++) {
            t[q[i]] = '(';
            u[q[i]] = '(';
        }
        for (int i = 0; i < c1; i++) {
            t[q[sz - 1 - i]] = ')';
            u[q[sz - 1 - i]] = ')';
        }
        if (c0 > 0 && c1 > 0) {
            swap(u[q[c0 - 1]], u[q[c0]]);
        }
        auto Check = [&](string x) {
            int z = 0;
            for (int i = 0; i < n; i++) {
                if (x[i] == '(') {
                    z++;
                } else {
                    z--;
                }
                if (z < 0) {
                    return false;
                }
            }
            return true;
        };
        if (Check(t) && (min(c0, c1) == 0 || !Check(u))) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}