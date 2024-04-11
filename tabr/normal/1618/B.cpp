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
        cin >> n;
        string t = "";
        for (int i = 0; i < n - 2; i++) {
            string s;
            cin >> s;
            if (t.empty() || t.back() != s[0]) {
                t += s;
            } else {
                t += s[1];
            }
        }
        if ((int) t.size() != n) {
            t += "a";
        }
        cout << t << '\n';
    }
    return 0;
}