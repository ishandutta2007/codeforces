#include<bits/stdc++.h>

const int N = 10000010;
const int M = 100010;
const int K = 25;
const int moder = (int) 1e9 + 7;
typedef std::pair <int, int> pii;
typedef std::pair <pii, int> piii;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int min[N];
std::vector <int> prime;
std::vector <int> e[M];
std::vector <piii> vec[N];
std::vector <pii> vvec[K];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (int j = 0, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int in[M], out[M], cnt = 1;
int c[M << 1], a[M], fa[M][20];
int dep[M], ans[M], u[M], v[M], llca[M];

void dfs(int u, int fa){
    in[u] = cnt ++;
    ::fa[u][0] = fa;
    for (int i = 1; i < 20; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    out[u] = cnt ++;
}

int lca(int u, int v){
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < 20; ++ i){
        if ((dep[u] - dep[v]) >> i & 1){
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; -- i){
        if (fa[u][i] != fa[v][i]){
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

void add(int sit, int value){
    for ( ; sit < M << 1; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        int x = a[i];
        while (x > 1){
            int tmp = min[x], cnt = 0;
            while (x % tmp == 0){
                x /= tmp;
                ++ cnt;
            }
            vec[tmp].push_back({{cnt, 0}, i});
        }
    }
    int test;
    scanf("%d", &test);
    for (int i = 1, x; i <= test; ++ i){
        scanf("%d%d%d", &u[i], &v[i], &x);
        llca[i] = lca(u[i], v[i]);
        while (x > 1){
            int tmp = min[x], cnt = 0;
            while (x % tmp == 0){
                x /= tmp;
                ++ cnt;
            }
            vec[tmp].push_back({{cnt, 1}, i});
        }
        ans[i] = 1;
    }
    for (int i = 0; i < N; ++ i){
        if (vec[i].empty()) continue;
        for (int i = 0; i < K; ++ i){
            vvec[i].clear();
        }
        for (auto u : vec[i]){
            vvec[u.first.first].push_back({u.first.second, u.second});
        }
        for (int j = 0; j < K; ++ j){
            for (auto u : vvec[j]){
                if (u.first){
                    int id = u.second;
                    int exp = query(in[::u[id]]) + query(in[::v[id]]) - query(in[llca[id]]) - query(in[fa[llca[id]][0]]);
                    ans[id] = 1ll * ans[id] * powermod(i, exp) % moder;
                }
            }
            for (int k = j + 1; k < K; ++ k){
                for (auto u : vvec[k]){
                    if (!u.first){
                        int id = u.second;
                        add(in[id], 1);
                        add(out[id], -1);
                    }
                }
            }
        }
        for (int j = 0; j < K; ++ j){
            for (auto u : vvec[j]){
                if (!u.first){
                    int id = u.second;
                    add(in[id], -j);
                    add(out[id], j);
                }
            }
        }
    }
    for (int i = 1; i <= test; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}