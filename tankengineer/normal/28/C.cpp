//28C
#include<cstdio>

int n, m, cnt[55];
double q, f[55][55][55], c[55][55], ans;

int main() {
  scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cnt[i]);
    }
    c[0][0] = 1;
    for (int i = 1; i <= 50; i++) {
        c[i][0] = 1; c[i][i] = 1;
        for (int j = 1; j < i; j++) {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    f[0][0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= i; k++) {
                q = 1;
                for (int l = 1; l <= n - i; l++) {
                    q = q * (m - j - 1) / (m - j);
                }
                if (j == m - 1) q = 1;
                for (int l = 0; l <= n - i; l++) {
                  if (l / cnt[j + 1] + (l % cnt[j + 1] ? 1 : 0) > k) {
                      f[i + l][j + 1][l / cnt[j + 1] + (l % cnt[j + 1] ? 1 : 0)] += f[i][j][k] * q * c[n - i][l];
                    } else {
                        f[i + l][j + 1][k] += f[i][j][k] * q * c[n - i][l];
                    }
                    if (j != m - 1) q = q / (m - j - 1);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) ans = ans + f[n][m][i] * i;
    printf("%.12lf\n", ans);
    return 0;
}