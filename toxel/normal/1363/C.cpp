#include <bits/stdc++.h>

const int N = 1010;

int deg[N];

void solve(){
    memset(deg, 0, sizeof(deg));
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        ++ deg[u], ++ deg[v];
    }
    if (deg[x] <= 1){
        puts("Ayush");
        return;
    }
    if (n % 2 == 1){
        puts("Ashish");
    }
    else{
        puts("Ayush");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}