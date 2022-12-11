#include<bits/stdc++.h>

const int N = 100010;

int deg[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        ++ deg[u], ++ deg[v];
    }
    for (int i = 1; i <= n; ++ i){
        if (deg[i] == 2){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}