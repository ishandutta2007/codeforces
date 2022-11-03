#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int Case, n, a[N], la[N], fn[N];
int f[N][N];
int main() {
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) fn[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if (a[i] == a[i - 1]) {
                --i; --n;
            } else {
                la[i] = fn[a[i]];
                fn[a[i]] = i;
            }
        }
        for (int i = n; i; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = f[i][j - 1];
                for (int k = la[j]; k >= i; k = la[k]) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j - 1] + 1);
                }
            }
        }
        printf("%d\n", n - 1 - f[1][n]);
    }
    return 0;
}