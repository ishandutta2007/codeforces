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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        m = min(m, n + 1);
        while (m--) {
            string t = s;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    int a = 0;
                    if (i == 0 || s[i - 1] == '0') {
                        a++;
                    }
                    if (i == n - 1 || s[i + 1] == '0') {
                        a++;
                    }
                    if (a == 1) {
                        t[i] = '1';
                    }
                }
            }
            swap(s, t);
        }
        cout << s << '\n';
    }
    return 0;
}