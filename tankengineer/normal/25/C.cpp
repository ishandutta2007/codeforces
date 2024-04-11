//25C
#include<cstdio>
#include<algorithm>

using namespace std;

int n, t, g[305][305], u, v, l, t1;
long long sum;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            if (i < j) sum = sum + g[i][j];
        }
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &u, &v, &l);
        if (g[u][v] <= l) {
            printf("%I64d\n", sum);
            continue;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                t1 = min(g[j][k], min(g[j][u] + l + g[v][k], g[j][v] + l + g[u][k]));
                if (t1 < g[j][k]) {
                    sum = sum - g[j][k] + t1;
                    g[j][k] = g[k][j] = t1;
                }
            }
        }
        printf("%I64d\n", sum);
    }
    return 0;
}