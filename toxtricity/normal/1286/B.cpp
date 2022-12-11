#include <bits/stdc++.h>

const int N = 2010;

std::vector <int> e[N];
int c[N], sz[N];
int n;

std::vector <int> dfs(int u){
    sz[u] = 1;
    int offset = 0;
    std::vector <int> ret(n + 1);
    for (auto v : e[u]){
        std::vector <int> tmp = dfs(v);
        for (auto &u : tmp){
            if (u > 0){
                u += offset;
            }
        }
        for (int i = 0; i <= n; ++ i){
            ret[i] = std::max(ret[i], tmp[i]);
        }
        sz[u] += sz[v];
        offset += sz[v];
    }
    if (c[u] >= sz[u]){
        puts("NO");
        exit(0);
    }
    for (int i = 0; i <= n; ++ i){
        if (ret[i] > c[u]){
            ++ ret[i];
        }
    }
    ret[u] = c[u] + 1;
    return ret;
}

int main(){
    scanf("%d", &n);
    int root = 0;
    for (int i = 1; i <= n; ++ i){
        int p;
        scanf("%d%d", &p, &c[i]);
        if (p == 0){
            root = i;
        }
        else{
            e[p].emplace_back(i);
        }
    }
    std::vector <int> ret = dfs(root);
    puts("YES");
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ret[i], " \n"[i == n]);
    }
    return 0;
}