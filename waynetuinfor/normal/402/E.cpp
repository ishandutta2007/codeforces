#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
int a[maxn][maxn];
vector<int> G[maxn], R[maxn], topo;
bool v[maxn];

void rdfs(int now) {
    v[now] = true;
    for (int u : R[now]) if (!v[u]) rdfs(u);
    topo.push_back(now);
}

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) if (!v[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
        if (a[i][j]) G[i].push_back(j), R[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) rdfs(i);
    reverse(topo.begin(), topo.end());
    memset(v, false, sizeof(v));
    dfs(topo[0]);
    for (int i = 1; i <= n; ++i) if (!v[i]) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}