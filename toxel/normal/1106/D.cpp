#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::set <int> set;
    set.insert(1);
    while (!set.empty()){
        int x = *(set.begin());
        printf("%d ", x);
        vis[x] = true;
        set.erase(x);
        for (auto v : e[x]){
            if (!vis[v]){
                set.insert(v);
            }
        }
    }
    puts("");
    return 0;
}