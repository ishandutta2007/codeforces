#include <bits/stdc++.h>

const int N = 500010;
const int moder = int(1e9) + 7;

int fa[N];
std::vector<int> e[N];

int find(int u){
    return (fa[u] == u) ? u : (fa[u] = find(fa[u]));
}

bool unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return false;
    }
    if (e[u].size() > e[v].size()){
        std::swap(u, v);
    }
    fa[u] = v;
    for (auto w : e[u]){
        e[v].emplace_back(w);
    }
    return true;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i){
        fa[i] = i;
        e[i] = {i};
    }
    std::vector<int> ans;
    std::set <int> single;
    for (int i = 0; i < n; ++ i){
        int num;
        scanf("%d", &num);
        std::vector<int> vec;
        for (int j = 0; j < num; ++ j){
            int x;
            scanf("%d", &x);
            if (single.count(x)){
                continue;
            }
            vec.emplace_back(x);
        }
        if (vec.empty()){
            continue;
        }
        if (int(vec.size()) == 1){
            for (auto u : e[find(vec[0])]){
                single.insert(u);
            }
            ans.emplace_back(i);
        }
        else{
            if (unite(vec[0], vec[1])){
                ans.emplace_back(i);
            }
        }
    }
    int cnt = 1;
    for (auto u : ans){
        cnt = 2 * cnt % moder;
    }
    int sz = ans.size();
    printf("%d %d\n", cnt, sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i] + 1, " \n"[i == sz - 1]);
    }
    return 0;
}