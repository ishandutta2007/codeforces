#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
std::vector <int> stack, path;
bool in_path[N], ok[N];
int dep[N];

void get_path(int u, int fa, int b){
    stack.emplace_back(u);
    if (u == b){
        path = stack;
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        get_path(v, u, b);
    }
    stack.pop_back();
}

bool dfs(int u, int fa, int len){
    bool ok = false;
    int max = -1, cnt = 0;
    for (auto v : e[u]){
        if (v == fa || in_path[v]){
            continue;
        }
        if (dfs(v, u, len)){
            ok = true;
        }
        max = std::max(max, dep[v]);
        if (dep[v] + 1 >= len - 1){
            ++ cnt;
        }
    }
    dep[u] = max + 1;
    if (cnt >= 2){
        return true;
    }
    return ok;

}

void solve(){
    for (int i = 0; i <= N; ++ i){
        e[i].clear();
    }
    memset(in_path, 0, sizeof(in_path));
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    get_path(a, 0, b);
    for (auto u : path){
        in_path[u] = true;
    }
    int sz = path.size();
    for (auto u : path){
        ok[u] = dfs(u, 0, sz);
    }
    int dep_l = 0, dep_r = sz - 1;
    int l = 0, r = sz - 1;
    while (l <= r){
        bool flag = false;
        while (l <= r && dep_l + sz - 1 <= r){
            if (ok[path[r]]){
                puts("YES");
                return;
            }
            if (dep[path[r]] >= sz - 1 && dep_r - r + 1 >= sz){
                puts("YES");
                return;
            }
            dep_r = std::max(dep_r, r + dep[path[r]]);
            flag = true;
            -- r;
        }
        while (l <= r && dep_r - sz + 1 >= l){
            if (ok[path[l]]){
                puts("YES");
                return;
            }
            if (dep[path[l]] >= sz - 1 && l - dep_l + 1 >= sz){
                puts("YES");
                return;
            }
            dep_l = std::min(dep_l, l - dep[path[l]]);
            flag = true;
            ++ l;
        }
        if (!flag){
            break;
        }
    }
    puts("NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}