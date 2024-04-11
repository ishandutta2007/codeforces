//26D
#include<cstdio>

int n, m, k;
double ans;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    ans = 1;
    for (int  i = 0; i <= k; i++) ans = ans * (m - i) / (n + 1 + i);
    ans = 1 - ans;
    if (ans < 0) ans = 0;
    printf("%lf\n", ans);
    return 0;
}