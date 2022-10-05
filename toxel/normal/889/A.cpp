#include<bits/stdc++.h>

const int N = 200010;

int deg[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        ++ deg[x];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += !deg[i];
    }
    printf("%d\n", ans);
    return 0;
}