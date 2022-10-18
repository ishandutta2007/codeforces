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
        int a = 0;
        for (char c : s) {
            a += c - 'a' + 1;
        }
        if (s.size() % 2 == 0) {
            cout << "Alice " << a << '\n';
        } else {
            int b = min(s[0], s.back()) - 'a' + 1;
            a -= b;
            if (a >= b) {
                cout << "Alice " << a - b << '\n';
            } else {
                cout << "Bob " << b - a << '\n';
            }
        }
    }
    return 0;
}