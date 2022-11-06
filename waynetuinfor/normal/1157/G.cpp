#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5;
int a[maxn][maxn], b[maxn][maxn];
int c[maxn], r[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }

    for (int cnt = 0; cnt <= n * m; ++cnt) {
        for (int p = 0; p < 2; ++p) {
            r[0] = p;
            for (int i = 0; i < m; ++i) {
                int s = (i >= cnt);
                c[i] = (s ^ r[0] ^ a[0][i]);
            }
            for (int i = 1; i < n; ++i) {
                int s = (i * m >= cnt);
                r[i] = (s ^ c[0] ^ a[i][0]);
            }
            bool valid = true;
            for (int i = 0; i < n && valid; ++i) {
                for (int j = 0; j < m && valid; ++j) {
                    valid &= (a[i][j] ^ r[i] ^ c[j]) == (i * m + j >= cnt);
                }
            }

            if (valid) {
                puts("YES");
                for (int i = 0; i < n; ++i) printf("%d", r[i]);
                puts("");
                for (int i = 0; i < m; ++i) printf("%d", c[i]);
                puts("");
                return 0;
            }
        }
    }

    puts("NO");
    return 0;
}