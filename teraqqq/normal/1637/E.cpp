#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& x : a) cin >> x, cnt[x]++;

    vector<int> diff_sizes;
    for (auto [x, k] : cnt) diff_sizes.push_back(k);

    sort(diff_sizes.begin(), diff_sizes.end());
    diff_sizes.erase(unique(diff_sizes.begin(), diff_sizes.end()), diff_sizes.end());

    const int cs = size(diff_sizes);
    vector<vi> v(cs);
    for (auto [x, k] : cnt) v[lower_bound(diff_sizes.begin(), diff_sizes.end(), k) - diff_sizes.begin()].push_back(x);

    for (auto& u : v) sort(u.rbegin(), u.rend());

    set<pi> s;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        s.emplace(x, y);
        s.emplace(y, x);
    }

    ll ans = 0;
    for (int i = 0; i < cs; ++i)
    for (int j = 0; j < cs; ++j) {
        set<pi> was;
        queue<pi> q;
        q.emplace(0, 0);

        const ll cxy = diff_sizes[i] + diff_sizes[j];
        while (!q.empty()) {
            const auto [it, jt] = q.front(); q.pop();
            if (i == j && it > jt) continue;
            if (it == v[i].size()) continue;
            if (jt == v[j].size()) continue;
            if (was.count(pi { it, jt })) continue;
            was.emplace(it, jt);

            if (s.count(pi {v[i][it], v[j][jt]}) || v[i][it] == v[j][jt]) {
                q.emplace(it+1, jt);
                q.emplace(it, jt+1);
            } else {
                ckmax(ans, cxy * (v[i][it] + v[j][jt]));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}