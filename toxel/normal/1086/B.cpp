#include<bits/stdc++.h>

const int N = 100010;

int deg[N];

int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        ++ deg[u], ++ deg[v];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        cnt += deg[i] == 1;
    }
    printf("%.15f\n", 2.0 * s / cnt);
    return 0;
}