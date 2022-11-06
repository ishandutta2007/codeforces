#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
vector<pair<int, int>> graph[maxn];
int a[maxn], ans[maxn];
bool v[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c); graph[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i], ans[i] = a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; ++i) pq.emplace(ans[i], i);
    while (pq.size()) {
        int cost, now; tie(cost, now) = pq.top(); pq.pop();
        if (v[now]) continue;
        v[now] = true;
        for (auto j : graph[now]) ans[j.first] = min(ans[j.first], ans[now] + 2 * j.second), pq.emplace(ans[j.first], j.first);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
}