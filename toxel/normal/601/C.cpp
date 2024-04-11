#include<bits/stdc++.h>

const int N = 100010;

double a[2][N], pre[N];
int x[N];

double fetch(double *a, int sit){
    return sit < 0 ? 0 : a[sit];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &x[i]);
        sum += x[i];
    }
    if (m == 1){
        printf("%.10lf\n", 1.0);
        return 0;
    }
    a[0][0] = 1;
    int now = 0;
    for (int i = 1; i < n; ++ i){
        int sz = std::min(N, i * m + 1);
        for (int j = 0; j < sz; ++ j){
            pre[j] = j ? pre[j - 1] + a[now][j] : a[now][0];
        }
        for (int j = 0; j < sz; ++ j){
            a[now ^ 1][j] = fetch(pre, j - 1) - fetch(pre, j - m - 1);
            a[now ^ 1][j] -= fetch(a[now], j - x[i]);
            a[now ^ 1][j] /= m - 1;
        }
        now ^= 1;
    }
    double ans = 0;
    for (int i = 1; i <= m; ++ i){
        if (i == x[0]) continue;
        for (int j = 0; j < N; ++ j){
            if (i + j >= sum) break;
            ans += a[now][j];
        }
    }
    printf("%.10lf\n", ans + 1);
    return 0;
}