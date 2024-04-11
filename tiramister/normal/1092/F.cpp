#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> path[200010];
ll ans, cost;
ll psum[200010], a[200010];
bool visited[200010];

ll calc_sum(int v) {
    psum[v] = a[v];
    visited[v] = true;

    for (auto sv : path[v]) {
        if (visited[sv]) continue;
        psum[v] += calc_sum(sv);
    }

    visited[v] = false;
    return psum[v];
}

ll calc_cost(int v) {
    ll ret = 0;
    visited[v] = true;

    for (auto sv : path[v]) {
        if (visited[sv]) continue;
        ret += calc_cost(sv) + psum[sv];
    }

    visited[v] = false;
    return ret;
}

void dfs(int v) {
    visited[v] = true;

    for (auto sv : path[v]) {
        if (visited[sv]) continue;

        cost -= psum[sv];
        psum[v] -= psum[sv];
        cost += psum[v];
        psum[sv] += psum[v];

        ans = max(ans, cost);
        dfs(sv);

        cost -= psum[v];
        psum[sv] -= psum[v];
        cost += psum[sv];
        psum[v] += psum[sv];
    }

    visited[v] = false;
}


int main() {
    int N;
    cin >> N;

    for (int v = 0; v < N; ++v) {
        cin >> a[v];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    calc_sum(0);
    cost = calc_cost(0);
    ans = cost;
    dfs(0);

    cout << ans << endl;
    return 0;
}