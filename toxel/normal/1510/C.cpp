#include <bits/stdc++.h>

const int N = 500010;
const int INF = 0x3f3f3f3f;

std::vector <int> e[N], e1[N];
std::vector <int> stack;
int dfn[N], low[N], dfncnt;
int ncnt, mcnt;
bool vis[N];
int u[N], v[N];

struct DP{
    int st1, st2;
};

struct State{
    DP dp1, dp2;
    int edge;
};

void addedge(int u, int v){
    e1[u].emplace_back(mcnt);
    e1[v].emplace_back(mcnt);
    ::u[mcnt] = u;
    ::v[mcnt] = v;
    ++ mcnt;
}

void tarjan(int u, int fa){
    dfn[u] = low[u] = ++ dfncnt;
    stack.emplace_back(u);
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (dfn[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
        else{
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if (dfn[u] == low[v]){
                ++ ncnt;
                while (true){
                    int x = stack.back();
                    stack.pop_back();
                    if (x == v) break;
                }
            }
            else if (dfn[u] < low[v]){
                addedge(u, v);
                stack.pop_back();
            }
        }
    }
}

using pii = std::pair <int, int>;

std::vector <pii> output;
DP status[N];
State trans[N][2][2];
int dp[N][2][2], tmp[2][2];
int choose[N];

void dfs(int u, int fa){
    memset(dp[u], 0x3f, sizeof(dp[u]));
    dp[u][0][0] = 0;
    vis[u] = true;
    for (auto edge : e1[u]){
        int v = ::u[edge] ^ ::v[edge] ^ u;
        if (v == fa){
            continue;
        }
        dfs(v, u);
        memset(tmp, 0x3f, sizeof(tmp));
        for (int s1 = 0; s1 < 2; ++ s1){
            for (int t1 = 0; t1 < 2; ++ t1){
                for (int e = 0; e < 2; ++ e){
                    if (s1 + (1 - e) > 1){
                        continue;
                    }
                    if (t1 + (1 - e) > 1){
                        continue;
                    }
                    int n1 = e == 0 ? 1 : s1;
                    for (int s2 = 0; s2 < 2; ++ s2){
                        for (int t2 = 0; t2 < 2; ++ t2){
                            int delta = 0;
                            if (!e && t2){
                                ++ delta;
                            }
                            if (s2 && e){
                                ++ delta;
                            }
                            int n2 = s2 ^ e;
                            int val = dp[u][s1][s2] + dp[v][t1][t2] + delta;
                            if (val < tmp[n1][n2]){
                                tmp[n1][n2] = val;
                                trans[edge][n1][n2] = {{s1, s2}, {t1, t2}, e};
                            }
                        }
                    }
                }
            }
        }
        memcpy(dp[u], tmp, sizeof(tmp));
    }
}

void dfs1(int u, int fa){
    int sz = e1[u].size();
    for (int i = sz - 1; i >= 0; -- i){
        int edge = e1[u][i];
        int v = ::u[edge] ^ ::v[edge] ^ u;
        if (v == fa){
            continue;
        }
        int s1 = status[u].st1;
        int s2 = status[u].st2;
        status[u] = trans[edge][s1][s2].dp1;
        status[v] = trans[edge][s1][s2].dp2;
        choose[edge] = trans[edge][s1][s2].edge;
        dfs1(v, u);
    }
}

int dfs2(int u, int fa){
    int bottomu = -1;
    for (auto edge : e1[u]){
        int v = ::u[edge] ^ ::v[edge] ^ u;
        if (v == fa){
            continue;
        }
        int bottomv = dfs2(v, u);
        if (bottomv != -1){
            if (!choose[edge]){
                output.emplace_back(bottomv, v);
                bottomv = -1;
            }
        }
        if (bottomv == -1){
            if (choose[edge]){
                bottomv = v;
            }
        }
        if (bottomu != -1 && bottomv != -1){
            output.emplace_back(bottomu, bottomv);
            bottomu = -1;
        }
        else{
            bottomu = bottomu == -1 ? bottomv : bottomu;
        }
    }
    return bottomu;
}

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(int n, int m){
    for (int i = 0; i <= 3 * n; ++ i){
        e[i].clear();
        e1[i].clear();
        dfn[i] = low[i] = vis[i] = 0;
    }
    stack.clear();
    dfncnt = 0;
    output.clear();
    mcnt = 0;
    ncnt = n;

    for (int i = 0; i < m; ++ i){
        int sz;
        scanf("%d", &sz);
        // sz = 2;
        std::vector <int> vec(sz);
        for (int j = 0; j < sz; ++ j){
            scanf("%d", &vec[j]);
        }
        // vec[0] = rnd() % (i + 1) + 1;
        // vec[1] = i + 2;
        // printf("%d %d\n", vec[0], vec[1]);
        for (int j = 0; j < sz - 1; ++ j){
            e[vec[j]].emplace_back(vec[j + 1]);
            e[vec[j + 1]].emplace_back(vec[j]);
        }
    }

    tarjan(1, 0);
    int sum = 0;
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            dfs(i, 0);
            int ans = INF;
            for (int s1 = 0; s1 < 2; ++ s1){
                for (int s2 = 0; s2 < 2; ++ s2){
                    int value = dp[i][s1][s2] + s2;
                    if (value < ans){
                        ans = value;
                        status[i] = {s1, s2};
                    }
                }
            }
            dfs1(i, 0);
            int bottom = dfs2(i, 0);
            if (bottom != -1){
                output.emplace_back(i, bottom);
            }
            sum += ans;
        }
    }
    assert(sum == int(output.size()));
    printf("%d\n", sum);
    for (auto p : output){
        printf("%d %d\n", p.first, p.second);
    }
}

int main(){
    int n, m;
    while (scanf("%d%d", &n, &m), n || m){
        solve(n, m);
    }
    return 0;
}