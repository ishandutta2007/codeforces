#include <bits/stdc++.h>

const int N = 1010;

std::vector <int> e[N];
int deg[N];
bool vis[N];

int ask(int u, int v){
    printf("? %d %d\n", u, v);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

void dfs(int u, int fa, std::vector <int> &vec){
    if (!vis[u]){
        return;
    }
    vec.emplace_back(u);
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u, vec);
    }
}

void ddfs(int u, int fa){
    if (!vis[u]){
        return;
    }
    for (auto v : e[u]){
        if (v == fa || !vis[v]){
            continue;
        }
        ++ deg[u], ++ deg[v];
        ddfs(v, u);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        vis[i] = true;
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        ++ deg[u];
        ++ deg[v];
    }
    while (true){
        std::vector <int> vec;
        for (int i = 1; i <= n; ++ i){
            if (vis[i] && deg[i] <= 1){
                vec.emplace_back(i);
            }
        }
        if (vec.size() == 1){
            printf("! %d\n", vec[0]);
            break;
        }
        int lca = ask(vec[0], vec[1]);
        if (lca == vec[0] || lca == vec[1]){
            printf("! %d\n", lca);
            break;
        }
        for (auto v : e[lca]){
            std::vector <int> vvec;
            dfs(v, lca, vvec);
            bool has = false;
            for (auto u : vvec){
                if (u == vec[0] || u == vec[1]){
                    has = true;
                    break;
                }
            }
            if (has){
                for (auto u : vvec){
                    vis[u] = false;
                }
            }
        }
        memset(deg, 0, sizeof(deg));
        ddfs(lca, 0);
    }
    return 0;
}