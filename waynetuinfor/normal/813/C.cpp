#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> T[maxn];
int d[maxn], low[maxn], dis[2][maxn];

int dfs(int, int, int);
void precal(int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        T[a].push_back(b); T[b].push_back(a);
    }
    dfs(1, 0, 0);
    precal(1, 0, 0, 0);
    precal(x, 0, 0, 1);
    int ans = 0;
    // for (int i = 1; i <= n; ++i) cout << "dep = " << d[i] << " low = " << low[i] << " dis[0] = " << dis[0][i] << " dis[1] = " << dis[1][i] << endl;
    for (int i = 1; i <= n; ++i) if (dis[1][i] < dis[0][i]) {
        ans = max(ans, 2 * low[i]);
    }
    cout << ans << endl;
    return 0;
}

int dfs(int x, int fa, int dep) {
    d[x] = dep;
    low[x] = d[x];
    for (int u : T[x]) if (u != fa) {
        low[x] = max(low[x], dfs(u, x, dep + 1));
    }
    return low[x];
}

void precal(int x, int fa, int cnt, int id) {
    dis[id][x] = cnt;
    for (int u : T[x]) if (u != fa) {
        precal(u, x, cnt + 1, id);
    }
}