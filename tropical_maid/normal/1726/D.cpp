#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> E[200005];
int U[200005], V[200005];
bool vis[200005], used[200005];
int dep[200005];
int par[200005];
int idx[200005];
int col[200005];
int cnt[200005];
int ans[200005];

void dfs(int x) {
    vis[x] = 1;
    for (int i : E[x]) {
        int c = U[i] ^ V[i] ^ x;
        if (vis[c]) continue;
        used[i] = 1;
        dep[c] = dep[x] + 1;
        par[c] = x;
        idx[c] = i;
        dfs(c);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            col[i] = 0;
            cnt[i] = 0;
            E[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            cin >> U[i] >> V[i];
            E[U[i]].push_back(i);
            E[V[i]].push_back(i);
            used[i] = 0;
            ans[i] = 0;
        }
        dfs(1);
        vector<int> rem;
        for (int i = 1; i <= m; ++i) {
            if (used[i]) continue;
            rem.push_back(i);
        }
        int o = 0;
        if (rem.size() > 0) {
            int e = rem[0];
            int x = U[e], y = V[e];
            while (x != y) {
                if (dep[x] < dep[y]) swap(x, y);
                col[x] = 1;
                o = idx[x];
                x = par[x];
            }
        }
        for (int i : rem) {
            if (i != rem[0]) ans[i] = 1;
        }
        if (rem.size() > 2) {
            int e = rem[1], f = rem[2];
            ++cnt[U[e]];
            ++cnt[V[e]];
            ++cnt[U[f]];
            ++cnt[V[f]];
            bool go = false;
            if (cnt[U[e]] == 2) go = true;
            if (cnt[V[e]] == 2) go = true;
            if (cnt[U[f]] == 2) go = true;
            if (cnt[V[f]] == 2) go = true;
            if (go) for (int i = 1; i <= n; ++i) {
                if (!col[i]) continue;
                if (cnt[i] == 1 && cnt[par[i]] == 1) continue;
                o = idx[i];
                break;
            }
        }
        ans[o] = 1;
        for (int i = 1; i <= m; ++i) printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}