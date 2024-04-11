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
        deque<char> c;
        for (int i = 0; i < n; i++) {
            c.emplace_back(s[i]);
        }
        while (c.size() && c.front() == c.back()) {
            c.pop_front();
            c.pop_back();
        }
        string ans = "Draw";
        int m = (int) c.size();
        for (int i = 0; i < m; i += 2) {
            if (c[i] != c[i + 1]) {
                ans = "Alice";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}