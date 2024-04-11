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
        int n;
        string s;
        cin >> n >> s;
        if (s[0] == '0' || s.back() == '0') {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> c;
        string a(n, 'a'), b(n, 'b');
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                c.emplace_back(i);
            }
        }
        if ((int)c.size() % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        string t = "()";
        if (c.empty()) {
            for (int i = 0; i < n; i++) {
                a[i] = b[i] = t[i % 2];
            }
        } else {
            int x = n - (int)c.size();
            int cnt = 0;
            int d = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    a[i] = t[d % 2];
                    b[i] = t[(d + 1) % 2];
                    d ^= 1;
                } else {
                    if (cnt * 2 < x) {
                        cnt++;
                        a[i] = b[i] = '(';
                    } else {
                        a[i] = b[i] = ')';
                    }
                }
            }
        }
        cout << a << '\n';
        cout << b << '\n';
    }
    return 0;
}