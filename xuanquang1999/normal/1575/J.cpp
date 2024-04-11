#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, m, k, a[MAXN][MAXN];

int main() {
//    freopen("input.txt", "r", stdin);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    while (k--) {
        int c; scanf("%d", &c);

        for(int i = 1; i <= n; ++i) {
            while (a[i][c] != 2) {
//                printf("%d %d %d\n", i, c, a[i][c]);
                if (a[i][c] == 1) {
                    a[i][c] = 2;
                    ++c;
                } else if (a[i][c] == 3) {
                    a[i][c] = 2;
                    --c;
                }
            }
        }

        printf("%d ", c);
    }

    return 0;
}