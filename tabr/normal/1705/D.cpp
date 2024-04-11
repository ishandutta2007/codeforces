#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<pair<char, int>> RLE(string s) {
    vector<pair<char, int>> res;
    for (char c : s) {
        if (res.empty() || res.back().first != c) {
            res.emplace_back(c, 1);
        } else {
            res.back().second++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        auto x = RLE(s);
        auto y = RLE(t);
        if (x.size() != y.size() || x[0].first != y[0].first) {
            cout << -1 << '\n';
            continue;
        }
        long long ans = 0;
        int a = 0, b = 0;
        for (int i = 0; i < (int) x.size(); i++) {
            a += x[i].second;
            b += y[i].second;
            ans += abs(a - b);
        }
        cout << ans << '\n';
    }
    return 0;
}