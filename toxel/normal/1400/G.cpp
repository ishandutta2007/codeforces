#include <bits/stdc++.h>

const int N = 600010;
const int moder = 998244353;
const int M = 22;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void addmult(int &u, int v, int w){
    u = (u + 1ll * v * w) % moder;
}

struct Mobius{
    std::vector<int> a[M];

    explicit Mobius(const std::vector<int> &edge){
        int n = edge.size();
        for (int i = 0; i <= n; ++ i){
            a[i].resize(1 << n);
        }
        for (int i = 0; i < 1 << n; ++ i){
            bool flag = true;
            int bitcnt = 0;
            for (int j = 0; j < n; ++ j){
                if (i >> j & 1){
                    if (edge[j] & i){
                        flag = false;
                        break;
                    }
                    ++ bitcnt;
                }
            }
            if (flag){
                a[bitcnt][i] = 1;
            }
        }
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < 1 << n; ++ j){
                if (j >> i & 1){
                    for (int k = 0; k <= n; ++ k){
                        a[k][j] += a[k][j ^ (1 << i)];
                    }
                }
            }
        }
    }
};

int fac[N], inv[N], invf[N];
int l[N], r[N];
std::vector<int> in[N], out[N], e[N];
bool vis[N];
std::vector<int> component[N];
std::vector<Mobius> mobius;
int id[N];
int dp[M][M];

void dfs(int u, std::vector<int> &vec){
    if (vis[u]){
        return;
    }
    vec.emplace_back(u);
    vis[u] = true;
    for (auto v : e[u]){
        dfs(v, vec);
    }
}

int comb(int n, int m){
    if (m < 0 || n < m) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
        in[l[i]].emplace_back(i);
        out[r[i]].emplace_back(i);
    }
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int num = 0;
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            continue;
        }
        std::vector <int> vec;
        dfs(i, vec);
        if (int(vec.size()) > 1){
            component[num ++] = vec;
        }
    }
    memset(id, -1, sizeof(id));
    for (int i = 0; i < num; ++ i){
        std::sort(component[i].begin(), component[i].end());
        int sz = component[i].size();
        for (int j = 0; j < sz; ++ j){
            id[component[i][j]] = j;
        }
        std::vector<int> edge(sz);
        for (auto u : component[i]){
            for (auto v : e[u]){
                edge[id[u]] |= 1 << id[v];
            }
        }
        mobius.emplace_back(Mobius(edge));
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        for (auto u : in[i]){
            vis[u] = true;
            ++ cnt;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int bad = 0;
        for (int j = 0; j < num; ++ j){
            int mask = 0;
            for (auto u : component[j]){
                if (vis[u]){
                    mask |= 1 << id[u];
                    ++ bad;
                }
            }
            int sz = component[j].size();
            for (int k = 0; k < M; ++ k){
                if (!dp[j][k]){
                    continue;
                }
                for (int u = 0; u <= sz; ++ u){
                    if (k + u >= M){
                        break;
                    }
                    addmult(dp[j + 1][k + u], dp[j][k], mobius[j].a[u][mask]);
                }
            }
        }
        int good = cnt - bad;
        for (int j = 0; j < M; ++ j){
            int need_good = i - j;
            addmult(ans, dp[num][j], comb(good, need_good));
        }
        for (auto u : out[i]){
            vis[u] = false;
            -- cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}