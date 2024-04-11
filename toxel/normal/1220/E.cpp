#include <bits/stdc++.h>

const int N = 200010;
typedef long long ll;

std::vector <int> e[N], _e[N];
int w[N];
int dfn[N], low[N], dfncnt;
std::vector <int> stack;
bool instack[N];
int bccno[N], bcccnt;
ll dp[N][2], value[N], sz[N];

void dfs(int u, int fa){
    dfn[u] = low[u] = ++ dfncnt;
    stack.push_back(u);
    instack[u] = true;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (dfn[v]){
            low[u] = std::min(low[u], dfn[v]);
            continue;
        }
        dfs(v, u);
        low[u] = std::min(low[u], low[v]);
    }
    if (low[u] == dfn[u]){
        while (true){
            int x = stack.back();
            stack.pop_back();
            instack[x] = false;
            bccno[x] = bcccnt;
            if (x == u){
                break;
            }
        }
        ++ bcccnt;
    }
}

bool flag[N];

void solve(int u, int fa){
    for (auto v : _e[u]){
        if (v == fa){
            continue;
        }
        solve(v, u);
    }
    ll sum = 0;
    for (auto v : _e[u]){
        if (v == fa){
            continue;
        }
        sum += flag[v] ? dp[v][1] : 0;
        if (flag[v]){
            flag[u] = true;
        }
    }
    if (sz[u] > 1){
        flag[u] = true;
    }
    dp[u][1] = value[u] + sum;
    for (auto v : _e[u]){
        if (v == fa){
            continue;
        }
        if (!flag[v]){
            dp[u][0] = std::max(dp[u][0], sum + dp[v][0]);
        }
        else{
            dp[u][0] = std::max(dp[u][0], sum - dp[v][1] + dp[v][0]);
        }
    }
    dp[u][0] += value[u];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int s;
    scanf("%d", &s);
    dfs(s, 0);
    for (int i = 1; i <= n; ++ i){
        for (auto v : e[i]){
            if (bccno[i] != bccno[v]){
                _e[bccno[i]].push_back(bccno[v]);
            }
        }
        value[bccno[i]] += w[i];
        ++ sz[bccno[i]];
    }
    solve(bccno[s], -1);
    printf("%lld\n", std::max(dp[bccno[s]][0], dp[bccno[s]][1]));
    return 0;
}