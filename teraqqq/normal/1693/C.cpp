#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> go(n), rv(n);
    vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        go[a].push_back(b);
        rv[b].push_back(a);
        cnt[a]++;
    }

    vector<int> dp(n, -1);

    pq_min<pi> q;
    q.emplace(0, n-1);

    while (!q.empty()) {
        auto [d, v] = q.top(); q.pop();
        if (dp[v] != -1) continue;
        dp[v] = d;

        for (int x : rv[v]) {
            cnt[x]--;
            q.emplace(cnt[x] + d + 1, x);
        }
    }

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}