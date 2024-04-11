#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int lon, fur;
bool v[maxn];

void dfs(int now, int dis) {
    if (dis > lon) lon = dis, fur = now;
    v[now] = true;
    for (int u : G[now]) if (!v[u]) {
        dfs(u, dis + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    int p = fur; lon = 0; fur = 0;
    memset(v, false, sizeof(v));
    dfs(p, 0);
    cout << lon << endl;
    return 0;
}