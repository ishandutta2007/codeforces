#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

bool visited[300010];
ll w[300010];
vector<pair<int, ll>> path[300010];
ll ans = 0;

ll dfs(int v) {
    visited[v] = true;

    priority_queue<ll> cost;
    for (int i = 0; i < 2; ++i) {
        cost.push(0);
    }

    for (auto p : path[v]) {
        int sv;
        ll c;
        tie(sv, c) = p;
        if (visited[sv]) continue;

        cost.push(dfs(sv) - c);
    }

    ll c[2];
    for (int i = 0; i < 2; ++i) {
        c[i] = cost.top();
        cost.pop();
    }

    ans = max(ans, c[0] + c[1] + w[v]);
    return c[0] + w[v];
}


int main() {
    int N;
    cin >> N;

    for (int v = 0; v < N; ++v) {
        cin >> w[v];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        path[u].push_back(make_pair(v, c));
        path[v].push_back(make_pair(u, c));
    }

    dfs(0);
    cout << ans << endl;

    return 0;
}