#include <bits/stdc++.h>

const int moder = int(1e9) + 7;
const int N = 100010;
const int M = 410;
using pii = std::pair <int, int>;
const int BIT = 18;

inline void add(int &a, int b){a += b, a -= a >= moder ? moder : 0;}

std::vector <pii> e[N];
bool vis[N], vis1[N], vis2[N];
int fa[N][BIT], value[N][BIT], dep[N];
int value1[N];
int dp[M], tmp[M];

void addedge(int u, int v, int w){
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
}

void dfs(int u, int fa, int value, std::vector <int> &vec){
    vis1[u] = true;
    vec.emplace_back(u);
    ::fa[u][0] = fa, ::value[u][0] = value;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
        ::value[u][i] = ::value[::fa[u][i - 1]][i - 1] ^ ::value[u][i - 1];
    }
    for (auto p : e[u]){
        int v = p.first;
        if (vis[v] || vis1[v]){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u, p.second, vec);
    }
}

std::vector <int> fetch(int root){
    std::vector <int> vec;
    dfs(root, 0, 0, vec);
    std::vector <int> ret;
    for (auto u1 : vec){
        for (auto p : e[u1]){
            int v1 = p.first;
            int u = u1, v = v1;
            if (vis[u] && vis[v]){
                continue;
            }
            if (u >= v){
                continue;
            }
            if (dep[u] < dep[v]){
                std::swap(u, v);
            }
            if (fa[u][0] == v){
                continue;
            }
            int w = p.second;
            for (int i = 0; i < BIT; ++ i){
                if ((dep[u] - dep[v]) >> i & 1){
                    w ^= value[u][i];
                    u = fa[u][i];
                }
            }
            if (u != v){
                for (int i = BIT - 1; i >= 0; -- i){
                    if (fa[u][i] != fa[v][i]){
                        w ^= value[u][i] ^ value[v][i];
                        u = fa[u][i];
                        v = fa[v][i];
                    }
                }
                w ^= value[u][0] ^ value[v][0];
                u = fa[u][0];
                v = fa[v][0];
            }
            ret.emplace_back(w);
        }
    }
    return ret;
}

std::map <std::vector <int>, int> map;
std::vector <std::vector <int>> matrices;

int getid(std::vector <int> vec){
    int n = vec.size();
    if (n > 5){
        return -1;
    }
    int cur = 0;
    for (int i = 0; i < 5 && cur < n; ++ i){
        for (int j = cur; j < n; ++ j){
            if (vec[j] >> i & 1){
                std::swap(vec[cur], vec[j]);
                break;
            }
        }
        if (!(vec[cur] >> i & 1)){
            continue;
        }
        for (int j = 0; j < n; ++ j){
            if (j == cur){
                continue;
            }
            if (vec[j] >> i & 1){
                vec[j] ^= vec[cur];
            }
        }
        ++ cur;
    }
    if (!vec.empty() && vec.back() == 0){
        return -1;
    }
    auto u = map.find(vec);
    if (u != map.end()){
        return u -> second;
    }
    int id = map.size();
    matrices.emplace_back(vec);
    return map[vec] = id;
}

int trans[M][M];

int calc(int id1, int id2){
    if (id1 == -1 || id2 == -1){
        return -1;
    }
    if (trans[id1][id2] != -2){
        return trans[id1][id2];
    }
    std::vector <int> vec = matrices[id1];
    std::copy(matrices[id2].begin(), matrices[id2].end(), std::back_inserter(vec));
    return trans[id1][id2] = trans[id2][id1] = getid(vec);
}

void solve(int p1, int p2, int w){
    memset(tmp, 0, sizeof(tmp));
    std::vector <int> ids;
    std::vector <int> vec1 = fetch(p1);
    if (p2 == 0){
        ids.emplace_back(getid(vec1));
    }
    else{
        std::vector <int> vec2 = fetch(p2);
        std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
        ids.emplace_back(getid(vec2));
        ids.emplace_back(ids.back());
        vec2.emplace_back(w);
        ids.emplace_back(getid(vec2));
    }
    for (int i = 0; i < int(map.size()); ++ i){
        for (auto id : ids){
            int value = calc(i, id);
            if (value == -1){
                continue;
            }
            add(tmp[value], dp[i]);
        }
    }
    for (int i = 0; i < M; ++ i){
        add(dp[i], tmp[i]);
    }
}

int main(){
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < M; ++ j){
            trans[i][j] = -2;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
    }
    vis[1] = true;
    for (auto p : e[1]){
        vis[p.first] = true;
        value1[p.first] = p.second;
    }
    dp[getid({})] = 1;
    for (auto p : e[1]){
        int u = p.first;
        for (auto pp : e[u]){
            int v = pp.first;
            if (v != 1 && vis[v] && u < v){
                solve(u, v, value1[u] ^ value1[v] ^ pp.second);
                vis2[u] = vis2[v] = true;
                break;
            }
        }
    }
    for (auto p : e[1]){
        if (!vis2[p.first]){
            solve(p.first, 0, 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < M; ++ i){
        add(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}