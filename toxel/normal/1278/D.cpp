#include <bits/stdc++.h>

const int N = 500010;

using pii = std::pair <int, int>;

pii p[N];
std::vector <int> e[N];
bool vis[N];

void dfs(int u){
    if (vis[u]){
        return;
    }
    vis[u] = true;
    for (auto v : e[u]){
        dfs(v);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    std::sort(p, p + n);
    int ecnt = 0;
    std::set <pii> set;
    for (int i = 0; i < n; ++ i){
        while (!set.empty() && set.begin() -> first < p[i].first){
            set.erase(set.begin());
        }
        auto u = set.lower_bound({p[i].second, INT_MIN});
        while (u != set.begin()){
            u = std::prev(u);
            ++ ecnt;
            if (ecnt >= n){
                puts("NO");
                return 0;
            }
            e[i].emplace_back(u -> second);
            e[u -> second].emplace_back(i);
        }
        set.emplace(p[i].second, i);
    }
    if (ecnt != n - 1){
        puts("NO");
        return 0;
    }
    dfs(0);
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}