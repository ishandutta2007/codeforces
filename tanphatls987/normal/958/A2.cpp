#include <cstdio>

#define long long long

const int N = 2000 + 2;
const int M = 200 + 2;
const int BASE1 = 29;
const int BASE2 = 31;

int n, m;
char a[N][M], b[M][N];
long ha[N][N], hb[M][N];
long pw1[N], pw2[N];

long Get(long h[][N], int x1, int y1, int x2, int y2)
{
    return h[x2][y2] - h[x1 - 1][y2] * pw2[x2 - x1 + 1] - h[x2][y1 - 1] * pw1[y2 - y1 + 1]
         + h[x1 - 1][y1 - 1] * pw2[x2 - x1 + 1] * pw1[y2 - y1 + 1];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
    for (int i = 1; i <= m; ++i) scanf("%s", b[i] + 1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ha[i][j] = ha[i][j - 1] * BASE1 + a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ha[i][j] += ha[i - 1][j] * BASE2;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            hb[i][j] = hb[i][j - 1] * BASE1 + b[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            hb[i][j] += hb[i - 1][j] * BASE2;

    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        pw1[i] = pw1[i - 1] * BASE1;
        pw2[i] = pw2[i - 1] * BASE2;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (Get(ha, i, 1, i + m - 1, m) == Get(hb, 1, j, m, j + m - 1))
            {
                printf("%d %d", i, j);
                return 0;
            }
    return 0;
}