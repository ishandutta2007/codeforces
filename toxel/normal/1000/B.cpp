#include<bits/stdc++.h>

const int N = 100010;

int a[N];
int suf[2][N], pre[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    a[n] = m;
    suf[0][n - 1] = 0;
    suf[1][n - 1] = m - a[n - 1];
    for (int i = n - 2; i >= 0; -- i){
        suf[0][i] = suf[1][i + 1];
        suf[1][i] = a[i + 1] - a[i] + suf[1][i + 2];
    }
    for (int i = 0; i <= n; ++ i){
        pre[i] = i ? pre[i - 1] : 0;
        if (i % 2 == 0){
            pre[i] += i ? a[i] - a[i - 1] : a[0];
        }
    }
    int ans = pre[n];
    if (a[0] > 1){
        ans = std::max(ans, a[0] - 1 + suf[1][0]);
    }
    for (int i = 0; i < n; ++ i){
        if (a[i + 1] - a[i] == 1) continue;
        ans = std::max(ans, pre[i] + a[i + 1] - a[i] - 1 + suf[i & 1][i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}