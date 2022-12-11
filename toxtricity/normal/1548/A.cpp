#include <bits/stdc++.h>

const int N = 200010;

std::set <int> set[N];
bool ans[N];
int cnt = 0;

void check(int id){
    cnt -= ans[id];
    if (set[id].empty() || *std::prev(set[id].end()) < id){
        ans[id] = true;
    }
    else{
        ans[id] = false;
    }
    cnt += ans[id];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        set[u].insert(v);
        set[v].insert(u);
    }
    for (int i = 1; i <= n; ++ i){
        check(i);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int u, v;
            scanf("%d%d", &u, &v);
            set[u].insert(v);
            set[v].insert(u);
            check(u);
            check(v);
        }
        else if (type == 2){
            int u, v;
            scanf("%d%d", &u, &v);
            set[u].erase(v);
            set[v].erase(u);
            check(u);
            check(v);
        }
        else{
            printf("%d\n", cnt);
        }
    }
    return 0;
}