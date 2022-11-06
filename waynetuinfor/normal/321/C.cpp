#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn], cur;
char ans[maxn];
bool v[maxn];
int sz[maxn], mx[maxn];

void dfssz(int now) {
    v[now] = true;
    sz[now] = 1; mx[now] = 0;
    cur.push_back(now);
    for (int u : G[now]) if (!v[u]) {
        dfssz(u);
        mx[now] = max(sz[u], mx[now]);
        sz[now] += sz[u];
    }
}

void dfs(int now, int fa, char lev) {
    assert(lev >= 'A' && lev <= 'Z');
    dfssz(now);
    int c = -1;
    for (int u : cur) {
        if (max(mx[u], (int)cur.size() - sz[u]) <= (int)cur.size() / 2) c = u;
        v[u] = false;
    }
    cur.clear();
    v[c] = true;
    ans[c] = lev;
    for (int u : G[c]) if (u != fa && !v[u]) {
        dfs(u, c, lev + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 'A');
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}