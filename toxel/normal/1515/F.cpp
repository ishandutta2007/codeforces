#include <bits/stdc++.h>

const int N = 300010;
using ll = long long;
using pii = std::pair <ll, ll>;

ll a[N];
std::queue <int> e[N];
int u[N], v[N];
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
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    std::set <pii> set;
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        set.emplace(a[i], i);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        e[u[i]].emplace(i);
        e[v[i]].emplace(i);
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    std::vector <int> ans;
    for (int i = 0; i < n - 1; ++ i){
        auto it = std::prev(set.end());
        int nd = it -> second;
        set.erase(it);
        int to_add = -1, e_id = -1;
        while (!e[nd].empty()){
            e_id = e[nd].front();
            int next = find(find(u[e_id]) ^ find(v[e_id]) ^ nd);
            e[nd].pop();
            if (find(nd) == find(next)){
                continue;
            }
            if (a[nd] + a[next] < x){
                puts("NO");
                return 0;
            }
            to_add = find(next);
            break;
        }
        if (to_add == -1){
            puts("NO");
            return 0;
        }
        unite(to_add, nd);
        a[nd] = a[nd] + a[to_add] - x;
        ans.emplace_back(e_id + 1);
        set.erase({a[to_add], to_add});
        set.emplace(a[nd], nd);
        if (e[nd].size() < e[to_add].size()){
            e[nd].swap(e[to_add]);
        }
        while (!e[to_add].empty()){
            e[nd].emplace(e[to_add].front());
            e[to_add].pop();
        }
    }
    puts("YES");
    for (auto u : ans){
        printf("%d\n", u);
    }
    return 0;
}