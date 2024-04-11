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
        string s, t;
        cin >> s >> t;
        if (s.size() < t.size()) {
            cout << "NO" << '\n';
            continue;
        }
        while (!t.empty() && !s.empty() && t.back() == s.back()) {
            t.pop_back();
            s.pop_back();
        }
        if (t.size() > 1) {
            cout << "NO" << '\n';
            continue;
        }
        if (t.empty()) {
            cout << "YES" << '\n';
        } else {
            if (find(s.begin(), s.end(), t[0]) != s.end()) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}