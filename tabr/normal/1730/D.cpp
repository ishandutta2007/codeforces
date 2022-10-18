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
    /*
    int n;
    cin >> n;
    set<vector<int>> a;
    queue<vector<int>> b;
    vector<int> c(2 * n);
    iota(c.begin(), c.end(), 0);
    a.emplace(c);
    b.emplace(c);
    while (!b.empty()) {
        auto d = b.front();
        b.pop();
        for (int i = 0; i < n; i++) {
            auto e = d;
            for (int j = 0; j <= i; j++) {
                swap(e[j], e[2 * n - 1 - i + j]);
            }
            if (!a.count(e)) {
                a.emplace(e);
                b.emplace(e);
            }
        }
    }
    debug(a.size());
    for (auto v : a) {
        debug(v);
    }
    */
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        reverse(t.begin(), t.end());
        map<pair<char, char>, int> cnt;
        for (int i = 0; i < n; i++) {
            if (s[i] > t[i]) {
                swap(s[i], t[i]);
            }
            cnt[make_pair(s[i], t[i])]++;
        }
        string ans = "YES";
        int u = 0;
        for (auto p : cnt) {
            if (p.second % 2 == 1) {
                u++;
                if (p.first.first != p.first.second) {
                    ans = "NO";
                }
            }
        }
        if (u > 1) {
            ans = "NO";
        }
        cout << ans << '\n';
    }
    return 0;
}