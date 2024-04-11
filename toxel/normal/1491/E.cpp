#include <bits/stdc++.h>

const int N = 200010;
const int MAX = 30;
using pii = std::pair <int, int>;

int fib[N];
std::set <int> e[N];
int sz[N];
pii found = {};

void get_sz(int u, int fa, int type){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        get_sz(v, u, type);
        sz[u] += sz[v];
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (sz[v] == fib[type - 2]){
            found = {u, v};
        }
        else if (sz[v] == fib[type - 1]){
            found = {v, u};
        }
    }
}

void dfs(int u, int type){
    if (type <= 3){
        return;
    }
    found = {0, 0};
    get_sz(u, 0, type);
    if (found.first == 0){
        puts("NO");
        exit(0);
    }
    int x = found.first, y = found.second;
    e[x].erase(y);
    e[y].erase(x);
    dfs(x, type - 1);
    dfs(y, type - 2);
}

int main(){
    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAX; ++ i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    /*for (int i = 0; i < MAX; ++ i){
        for (int j = i + 1; j < MAX; ++ j){
            for (int k = j + 1; k < MAX; ++ k){
                if (fib[i] + fib[j] == fib[k]){
                    printf("%d %d %d\n", fib[i], fib[j], fib[k]);
                }
            }
        }
    }*/
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].insert(v);
        e[v].insert(u);
    }
    int type = 0;
    for (int i = 1; i < MAX; ++ i){
        if (fib[i] == n){
            type = i;
            break;
        }
    }
    if (type == 0){
        puts("NO");
        return 0;
    }
    dfs(1, type);
    puts("YES");
    return 0;
}