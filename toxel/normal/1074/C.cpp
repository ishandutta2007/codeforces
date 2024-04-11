#include<bits/stdc++.h>

const int N = 300010;

int x[N], y[N], xx[N], yy[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
        xx[i] = x[i], yy[i] = y[i];
    }
    std::sort(xx, xx + n);
    std::sort(yy, yy + n);
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        int sum = std::max(xx[n - 1] - x[i], x[i] - xx[0]) + std::max(yy[n - 1] - y[i], y[i] - yy[0]);
        ans = std::max(sum, ans);
    }
    printf("%d", ans << 1);
    for (int i = 4; i <= n; ++ i){
        printf(" %d", (xx[n - 1] - xx[0] + yy[n - 1] - yy[0]) << 1);
    }
    puts("");
    return 0;
}