#include <bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
int u[N], v[N];
int ans[N];
int n;

void print(){
    for (int i = 0; i < n - 1; ++ i){
        printf("%d\n", ans[i]);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        e[u[i]].emplace_back(i);
        e[v[i]].emplace_back(i);
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; ++ i){
        if (e[i].size() >= 3){
            for (int j = 0; j < 3; ++ j){
                ans[e[i][j]] = j;
            }
            int cur = 3;
            for (int j = 0; j < n - 1; ++ j){
                if (ans[j] == -1){
                    ans[j] = cur ++;
                }
            }
            print();
            return 0;
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        ans[i] = i;
    }
    print();
    return 0;
}