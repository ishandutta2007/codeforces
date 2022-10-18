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
        for (int i = n - 1; i >= 0; i--) {
            char c = (char) ('a' + i);
            if (s[0] == c) {
                s.erase(s.begin());
            } else if (s.back() == c) {
                s.pop_back();
            } else {
                cout << "NO" << '\n';
                break;
            }
            if (i == 0) {
                cout << "YES" << '\n';
            }
        }
    }
    return 0;
}