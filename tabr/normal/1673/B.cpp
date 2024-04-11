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
        vector<vector<int>> a(n + 1, vector<int>(26));
        auto t = s;
        sort(t.begin(), t.end());
        t.resize(unique(t.begin(), t.end()) - t.begin());
        t = s.substr(0, t.size());
        string ans = "YES";
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] != t[i % t.size()]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}