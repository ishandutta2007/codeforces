#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
vector<int>e[3010];
int fa[3010][3010];
int sz[3010][3010],d[3010][3010];
LL f[3010][3010];
bool vis[3010][3010];

void dfs(int x,int rt,int ff) {
    fa[rt][x] = ff;
    sz[rt][x] = 1;
    for (auto t:e[x]) {
        if (t != ff) {
            d[rt][t] = d[rt][x] + 1;
            dfs(t, rt, x);
            sz[rt][x] += sz[rt][t];
        } 
    }
}

void upd(LL &x,LL y) {
    x = max(x, y);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=N;i++) {
        d[i][i] = 0;
        dfs(i,i,0);
    }
    LL ans = 0;
    queue<pii>q;
    for (int u=1;u<=N;u++) {
        for (auto v:e[u]) {
            f[u][v] = 1LL * sz[u][v] * sz[v][u];
            vis[u][v] = true;
            q.push(pii(u,v));
        }
    }
    while(!q.empty()) {
        int u, v;
        auto pi = q.front();
        q.pop();
        u = pi.first, v = pi.second;
        ans = max(ans, f[u][v]);
        int D = d[u][v];
        for (auto t:e[u]) {
            if (t != fa[v][u]) {
                LL nxt = f[u][v] + 1LL * sz[u][v] * sz[v][t];
                upd(f[t][v], nxt);
                if (!vis[t][v]) {
                    vis[t][v] = true;
                    q.push(pii(t, v));
                }
            }
        }

        for (auto t:e[v]) {
            if (t != fa[u][v]) {
                LL nxt = f[u][v] + 1LL * sz[v][u] * sz[u][t];
                upd(f[u][t], nxt);
                if (!vis[u][t]) {
                    vis[u][t] = true;
                    q.push(pii(u, t));
                }
            }
        }

        vis[u][v] = true;
    }
    printf("%lld\n",ans);
}