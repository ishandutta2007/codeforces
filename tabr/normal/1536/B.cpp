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
    vector<string> a;
    for (char c = 'a'; c <= 'z'; c++) {
        a.emplace_back(string(1, c));
    }
    for (int _ = 0; _ < 2; _++) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                string s;
                if (_) {
                    s += 'a';
                }
                s += c;
                s += d;
                a.emplace_back(s);
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        for (string s : a) {
            int l = (int) s.size();
            bool ok = true;
            for (int i = 0; i <= n - l; i++) {
                if (x.substr(i, l) == s) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << s << '\n';
                break;
            }
        }
    }
    return 0;
}