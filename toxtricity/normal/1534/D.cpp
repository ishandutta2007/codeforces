#include <bits/stdc++.h>

const int N = 2010;

std::set <int> e[N];

std::vector <int> ask(int n, int node){
    printf("? %d\n", n);
    fflush(stdout);
    std::vector <int> ans(node + 1);
    for (int i = 1; i <= node; ++ i){
        scanf("%d", &ans[i]);
        if (ans[i] == 1){
            e[n].insert(i);
            e[i].insert(n);
        }
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <int> dis = ask(1, n);
    int cnt[2] = {};
    for (int i = 2; i <= n; ++ i){
        ++ cnt[dis[i] % 2];
    }
    int type = cnt[0] < cnt[1] ? 0 : 1;
    for (int i = 2; i <= n; ++ i){
        if (dis[i] % 2 == type){
            ask(i, n);
        }
    }
    puts("!");
    for (int i = 1; i <= n; ++ i){
        for (auto u : e[i]){
            if (i < u){
                printf("%d %d\n", i, u);
            }
        }
    }
    fflush(stdout);
    return 0;
}