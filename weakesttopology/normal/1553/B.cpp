#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = (int)size(s), m = (int)size(t);
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[0]) continue;
            for (int len = 1; len <= m && i + len <= n; ++len) {
                auto pref = s.substr(i, len);
                auto suff = t.substr(len, m - len);
                reverse(begin(suff), end(suff));
                int idx = i + len - (m - len) - 1;
                if (idx < 0 || idx + m - len > n) continue;
                if (pref == t.substr(0, len) && suff == s.substr(idx, m - len)) {
                    good = true;
                }
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}