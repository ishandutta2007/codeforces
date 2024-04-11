#include<bits/stdc++.h>

const int N = 100010;
const int M = 310;
const int BIT = 18;
const int moder = (int) 1e9 + 7;

std::vector <int> e[N], _e[N];
int dep[N], euler[N << 2], dfn[N], rdfn[N], dfncnt;
std::set <int> set[N];
int st[N << 2][BIT];
int high[N << 2];
int end[N];
bool real[N];
int dp[N][M];
int comb[M][M], inv[M], invf[M];

void dfs(int u, int fa){
    dfn[u] = end[u] = dfncnt;
    euler[dfncnt ++] = u;
    for (auto v : e[u]){
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        end[u] = dfncnt;
        euler[dfncnt ++] = u;
    }
}

void addedge(auto e, int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

int min(int u, int v){
    return dep[u] < dep[v] ? u : v;
}

int lca(int u, int v){
    int sit1 = end[u], sit2 = dfn[v];
    if (sit1 > sit2) std::swap(sit1, sit2);
    int bit = high[sit2 - sit1 + 1];
    return min(st[sit1][bit], st[sit2 - (1 << bit) + 1][bit]);
}

int lca(int u, int v, int root){
    if (u == root || v == root){
        return root;
    }
    if (u == v) return u;
    if (lca(u, v) == v){
        std::swap(u, v);
    }
    if (lca(u, v) == u){
        if (lca(u, root) == u){
            return lca(v, root);
        }
        return u;
    }
    int llca = lca(u, v);
    if (lca(llca, root) == llca){
        int x = lca(u, root);
        if (x != llca){
            return x;
        }
        return lca(v, root);
    }
    return llca;
}

void solve(int u, int fa, int m){
    for (auto v : _e[u]){
        if (v != fa){
            solve(v, u, m);
        }
    }
    for (int i = 0; i <= m; ++ i){
        dp[u][i] = real[u] ? i : 1;
    }
    for (int i = real[u]; i <= m; ++ i){
        for (auto v : _e[u]){
            if (v == fa) continue;
            dp[u][i] = 1ll * dp[u][i] * dp[v][i - real[u]] % moder;
        }
    }
}

int main(){
    for (int i = 0; i < M; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i -1][j]) % moder;
        }
    }
    invf[0] = 1;
    for (int i = 1; i < M; ++ i){
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    for (int i = 2; i < N << 2; ++ i){
        high[i] = high[i >> 1] + 1;
    }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        addedge(e, u, v);
    }
    dfs(1, 0);
    for (int i = 0; i < dfncnt; ++ i){
        st[i][0] = euler[i];
    }
    for (int j = 1; j < BIT; ++ j){
        for (int i = 0; i < dfncnt; ++ i){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = dfncnt; i < dfncnt << 1; ++ i){
        euler[i] = euler[i - dfncnt];
    }
    for (int i = 0; i < dfncnt << 1; ++ i){
        set[euler[i]].insert(i);
    }
    while (q --){
        int k, m, r;
        scanf("%d%d%d", &k, &m, &r);
        std::vector <int> a(k);
        std::vector <int> rollback;
        for (int i = 0; i < k; ++ i){
            scanf("%d", &a[i]);
            rollback.push_back(a[i]);
            real[a[i]] = true;
        }
        auto getdfn = [&](int u){return *(set[u].lower_bound(dfn[r]));};
        for (int i = 0; i < k; ++ i){
            rdfn[a[i]] = getdfn(a[i]);
        }
        std::sort(a.begin(), a.end(), [&](const int &u, const int &v){return rdfn[u] < rdfn[v];});
        std::vector <int> stack;
        for (int i = 0; i < k; ++ i){
            if (!stack.empty()){
                int llca = lca(stack.back(), a[i], r);
                rollback.push_back(llca);
                int ldfn = getdfn(llca);
                while ((int) stack.size() >= 2){
                    int x = stack[stack.size() - 2];
                    if (ldfn <= getdfn(x)){
                        addedge(_e, x, stack.back());
                        stack.pop_back();
                    }
                    else{
                        break;
                    }
                }
                if (llca != stack.back()){
                    addedge(_e, llca, stack.back());
                    stack.pop_back();
                    stack.push_back(llca);
                }
            }
            stack.push_back(a[i]);
        }
        while ((int) stack.size() >= 2){
            addedge(_e, stack[stack.size() - 2], stack.back());
            stack.pop_back();
        }
        int root = stack[0];
        solve(root, 0, m);
        int ans = 0;
        for (int i = m; i >= 0; -- i){
            for (int j = 0; j < i; ++ j){
                dp[root][i] = (dp[root][i] + ((i - j) & 1 ? -1ll : 1ll) * comb[i][j] * dp[root][j]) % moder;
            }
            ans = (ans + 1ll * dp[root][i] * invf[i]) % moder;
        }
        ans += ans < 0 ? moder : 0;
        printf("%d\n", ans);
        for (auto u : rollback){
            _e[u].clear();
        }
        for (auto u : a){
            real[u] = false;
        }
    }
}