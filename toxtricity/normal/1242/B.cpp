#include <bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::set <int> set;
    for (int i = 1; i < n; ++ i){
        set.insert(i);
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        if ((int) e[i].size() == n - 1){
            continue;
        }
        e[i].push_back(0);
        e[i].push_back(n + 1);
        std::sort(e[i].begin(), e[i].end());
        for (int j = 0, sz = e[i].size(); j < sz - 1; ++ j){
            int l = e[i][j] + 1, r = e[i][j + 1] - 1;
            if (l > r){
                continue;
            }
            auto u = set.lower_bound(l);
            while (u != set.end() && *u <= r - 1){
                unite(*u, (*u) + 1);
                u = set.erase(u);
            }
            unite(i, l);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (find(i) == i){
            ++ ans;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}