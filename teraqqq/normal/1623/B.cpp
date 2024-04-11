#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

void solve(const int n, const vector<pi>& v) {
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    sort(begin(p), end(p), [&](int a, int b) {
        return v[a].second - v[a].first < v[b].second - v[b].first;
    });

    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);

    for (int i : p) {
        auto it = s.lower_bound(v[i].first);
        cout << v[i].first << " " << v[i].second << " " << *it << '\n';
        s.erase(it);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pi> v(n);
        for (auto& [a, b] : v) cin >> a >> b;
        solve(n, v);
    }
}