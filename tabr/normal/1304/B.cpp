#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t, u;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) {
        if (s[i].empty()) continue;
        rep(j, i + 1, n) {
            if (s[j].empty()) continue;
            string tt = s[j];
            reverse(tt.begin(), tt.end());
            if (s[i] == tt) {
                t.emplace_back(s[i]);
                t.emplace_back(s[j]);
                s[i] = s[j] = "";
                break;
            }
        }
    }
    rep(i, 0, n) {
        if (s[i].empty()) continue;
        string tt = s[i];
        reverse(tt.begin(), tt.end());
        if (s[i] == tt) u.emplace_back(s[i]);
    }
    int ans = m * t.size();
    if (!u.empty()) ans += m;
    cout << ans << endl;
    string x;
    for (int i = 0; i < t.size(); i += 2) {
        cout << t[i];
    }
    if (!u.empty()) cout << u[0];
    for (int i = t.size() - 1; i > 0; i -= 2) {
        cout << t[i];
    }
    return 0;
}