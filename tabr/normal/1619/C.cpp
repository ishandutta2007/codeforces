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
        string a, s;
        cin >> a >> s;
        string b;
        while (!a.empty() || !s.empty()) {
            // debug(a, s);
            if (s.empty()) {
                b = "-1";
                break;
            } else if (a.empty()) {
                b = s + b;
                break;
            } else if (a.back() <= s.back()) {
                b = to_string(s.back() - a.back()) + b;
                a.pop_back();
                s.pop_back();
            } else {
                b = to_string(10 + s.back() - a.back()) + b;
                a.pop_back();
                s.pop_back();
                if (s.empty() || s.back() != '1') {
                    b = "-1";
                    break;
                }
                s.pop_back();
            }
        }
        while (b[0] == '0') {
            b = b.substr(1);
        }
        cout << b << '\n';
    }
    return 0;
}