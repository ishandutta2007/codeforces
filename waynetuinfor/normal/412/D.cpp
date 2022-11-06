#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e4 + 10;
vector<int> G[maxn], topo;
bool v[maxn];

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) {
        if (!v[u]) dfs(u);
    }
    cout << now << ' ';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) dfs(i);
    }
    cout << endl;
    return 0;
}