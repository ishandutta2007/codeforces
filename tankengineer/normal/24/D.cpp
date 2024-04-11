//24D
#include<cstdio>

int n, m, x, y;
double z[1005], a[1005], b[1005], c[1005], t1;

int main() {
  scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);
    if (m == 1) {
        printf("%.12lf\n", 2.0 * (n - x));
        return 0;
    }
    for (int i = 1; i <= m; i++) z[i] = 0;
    for (int i = n - 1; i >= x; i--) {
      z[1] = z[1] / 3 + 1;
        z[m] = z[m] / 3 + 1;
        for (int j = 2; j < m; j++) z[j] = z[j] / 4 + 1;
    b[1] = b[m] = 2.0 / 3.0;
        c[1] = a[m] = -1.0 / 3.0;
        for (int j = 2; j < m; j++) {
            a[j] = -1.0 / 4.0;
            b[j] = 3.0 / 4.0;
            c[j] = -1.0 / 4.0;
        }
        for (int j = 2; j <= m; j++) {
      t1 = a[j] / b[j - 1];
      a[j] -= t1 * b[j - 1];
            b[j] -= t1 * c[j - 1];
            z[j] -= t1 * z[j - 1];
        }
        for (int j = m - 1; j >= 1; j--) {
            t1 = c[j] / b[j + 1];
            c[j] -= t1 * b[j + 1];
            z[j] -= t1 * z[j + 1];
        }
        for (int j = 1; j <= m; j++) {
            z[j] /= b[j];
            b[j] = 1;
        }
    }
    printf("%.12lf\n", z[y]);
    return 0;
}