#include <bits/stdc++.h>

const int N = 200010;

std::set<int> set[N];
int ans[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        int x;
        scanf("%d", &x);
        set[x].insert(i);
    }
    for (int i = 0; i < m - 1; ++ i){
        int a, b;
        scanf("%d%d", &a, &b);
        if (set[a].size() < set[b].size()){
            set[a].swap(set[b]);
        }
        for (auto u : set[b]){
            if (set[a].count(u + 1)){
                ++ ans[i];
            }
            if (set[a].count(u - 1)){
                ++ ans[i];
            }
        }
        for (auto u : set[b]){
            set[a].insert(u);
        }
    }
    for (int i = m - 2; i >= 0; -- i){
        ans[i] += ans[i + 1];
    }
    for (int i = 0; i < m; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}