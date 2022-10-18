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
        string s, t;
        cin >> s >> t;
        if (s == t) {
            cout << "=" << '\n';
        } else if (s.back() < t.back()) {
            cout << ">" << '\n';
        } else if (s.back() > t.back()) {
            cout << "<" << '\n';
        } else if (s.back() == 'S') {
            if (s.size() > t.size()) {
                cout << "<" << '\n';
            } else {
                cout << ">" << '\n';
            }
        } else {
            if (s.size() < t.size()) {
                cout << "<" << '\n';
            } else {
                cout << ">" << '\n';
            }
        }
    }
    return 0;
}