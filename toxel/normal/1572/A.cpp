#include <bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
int deg[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
        deg[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        int sz;
        scanf("%d", &sz);
        for (int j = 1; j <= sz; ++ j){
            int x;
            scanf("%d", &x);
            e[x].emplace_back(i);
            ++ deg[i];
        }
    }
    std::set <int> possible;
    for (int i = 1; i <= n; ++ i){
        if (deg[i] == 0){
            possible.emplace(i);
        }
    }
    int round = 0;
    int cur = 0, solved = 0;
    while (solved < n){
        ++ round;
        auto it = possible.upper_bound(cur);
        if (it == possible.end()){
            break;
        }
        while (it != possible.end()){
            cur = *it;
            possible.erase(it);
            ++ solved;
            for (auto v : e[cur]){
                -- deg[v];
                if (deg[v] == 0){
                    possible.emplace(v);
                }
            }
            it = possible.upper_bound(cur);
        }
        cur = 0;
    }
    if (solved < n){
        puts("-1");
        return;
    }
    printf("%d\n", round);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}