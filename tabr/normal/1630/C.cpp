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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]].emplace_back(i);
    }
    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        if (b[i].size() >= 2) {
            d.emplace_back(b[i][0], b[i].back());
        }
    }
    sort(d.begin(), d.end());
    vector<pair<int, int>> e;
    for (auto p : d) {
        if (e.empty()) {
            e.emplace_back(p);
        } else if (e.back().second < p.second) {
            if (e.size() == 1) {
                e.emplace_back(p);
            } else {
                auto q = e.back();
                e.pop_back();
                if (e.back().second < p.first) {
                    e.emplace_back(q);
                }
                e.emplace_back(p);
            }
        }
    }
    swap(d, e);
    debug(d);
    int ans = 0;
    for (int i = 0; i < (int) d.size(); i++) {
        if (i == 0 || d[i - 1].second < d[i].first) {
            ans += d[i].second - d[i].first - 1;
        } else {
            ans--;
            ans += d[i].second - d[i - 1].second;
        }
    }
    cout << ans << '\n';
    return 0;
}