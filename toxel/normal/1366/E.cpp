#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;

int a[N], b[N];
int left1[N], left2[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = m, j = n; i >= 1; -- i){
        while (j > 0 && a[j] >= b[i]){
            -- j;
        }
        left1[i] = j;
    }
    for (int i = m, j = n; i >= 1; -- i){
        while (j > 0 && a[j] != b[i]){
            -- j;
        }
        left2[i] = j;
    }
    if (left1[1] != 0 || left2[1] == 0){
        puts("0");
        return 0;
    }
    int ans = 1;
    for (int i = 2; i <= m; ++ i){
        if (left2[i] == 0 || left1[i] >= left2[i]){
            puts("0");
            return 0;
        }
        ans = 1ll * ans * (left2[i] - left1[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}