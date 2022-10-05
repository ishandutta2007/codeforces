#include<bits/stdc++.h>

const int N = 1010;

int a[N], b[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
    }
    int sit = 0, ans = 0;
    for (int i = 0; i < n && sit < m; ++ i){
        if (a[i] <= b[sit]){
            ++ ans;
            ++ sit;
        }
    }
    printf("%d\n", ans);
    return 0;
}