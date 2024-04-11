#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

ll dp[300010], a[300010];
bool visited[300010];
vector<int> path[300010];

ll dfs(int v, ll b) {
    visited[v] = true;

    ll ret = 0;
    dp[v] = a[v];
    for (int sv : path[v]) {
        if (visited[sv]) continue;

        ret += dfs(sv, b);
        if (dp[sv] > 0) dp[v] += dp[sv];
    }

    if (dp[v] >= b) {
        ++ret;
        dp[v] = 0;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    dfs(0, INF);
    ll ans = -INF;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, dp[i]);
    }

    fill(visited, visited + N, false);
    ll g = dfs(0, ans);
    cout << ans * g << " " << g << endl;

    return 0;
}