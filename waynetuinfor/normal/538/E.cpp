#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int leaf, dpmax[maxn], dpmin[maxn], sz[maxn];
vector<int> G[maxn];

void getsize(int now, int fa) {
    int c = 0;
    for (int u : G[now]) if (u != fa) {
        getsize(u, now);
        sz[now] += sz[u];
        ++c;
    }
    if (c == 0) sz[now] = 1;
}

void dfs(int now, int fa) {
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        dpmax[now] = max(dpmax[now], dpmin[u] + sz[now] - sz[u]);
        dpmin[now] += dpmax[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    getsize(1, 0); dfs(1, 0);
    cout << dpmax[1] + 1  << ' ' << sz[1] - dpmin[1] << endl;
    return 0;
}