#include <bits/stdc++.h>

const int N = 500010;

std::set <int> e[N], e1[N];
int p[N], q[N];
int cur;

void dfs(int u){
    if (int(e1[u].size()) == 1){
        u = *(e1[u].begin());
    }
    bool has_leaf = false;
    std::vector <int> sons;
    for (auto v : e1[u]){
        if (int(e1[v].size()) == 1){
            has_leaf = true;
        }
        sons.emplace_back(v);
    }
    if (has_leaf){
        std::vector <int> leaves;
        for (auto v : sons){
            if (int(e1[v].size()) == 1){
                leaves.emplace_back(v);
                e1[u].erase(v);
                e1[v].erase(u);
            }
            else{
                e1[u].erase(v);
                e1[v].erase(u);
                dfs(v);
            }
        }
        int sz = leaves.size();
        p[u] = cur;
        for (int i = 0; i < sz; ++ i){
            p[leaves[i]] = cur - i - 1;
        }
        q[u] = cur - sz;
        for (int i = 0; i < sz; ++ i){
            q[leaves[i]] = cur - i;
        }
        cur -= sz + 1;
        return;
    }
    int first = sons.front();
    for (auto v : sons){
        if (v == first){
            continue;
        }
        e1[u].erase(v);
        e1[v].erase(u);
        dfs(v);
    }
    dfs(u);
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
        e1[i].clear();
    }
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace(v);
        e[v].emplace(u);
    }
    std::vector <int> full, not_full;
    for (int i = 1; i <= n; ++ i){
        if (int(e[i].size()) == n - 1){
            full.emplace_back(i);
        }
        else{
            not_full.emplace_back(i);
        }
    }
    cur = n;
    for (auto u : full){
        p[u] = q[u] = cur --;
        for (auto v : e[u]){
            e[v].erase(u);
        }
        e[u].clear();
    }
    for (auto u : not_full){
        if (!e1[u].empty()){
            continue;
        }
        for (auto v : not_full){
            if (v == u){
                continue;
            }
            if (!e[u].count(v)){
                e1[u].insert(v);
                e1[v].insert(u);
                break;
            }
        }
    }
    for (auto u : not_full){
        if (!e1[u].empty()){
            dfs(u);
        }
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", p[i], " \n"[i == n]);
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", q[i], " \n"[i == n]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}