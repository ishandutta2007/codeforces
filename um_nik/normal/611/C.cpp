#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 600;
int n, m;
char s[N][N];
int a[N][N], b[N][N];

void read()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(" %s ", s[i]);
    for (int x = 0; x < n - 1; x++)
        for (int y = 0; y < m; y++)
            a[x + 1][y + 1] = (s[x][y] == '.' && s[x + 1][y] == '.');
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m - 1; y++)
            b[x + 1][y + 1] = (s[x][y] == '.' && s[x][y + 1] == '.');
    for (int x = 1; x < N; x++)
        for (int y = 1; y < N; y++)
        {
            a[x][y] += a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1];
            b[x][y] += b[x - 1][y] + b[x][y - 1] - b[x - 1][y - 1];
        }
    return;
}

int main()
{
    read();
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--;
        y1--;
        int ans = 0;
        ans += a[x2 - 1][y2] - a[x2 - 1][y1] - a[x1][y2] + a[x1][y1];
        ans += b[x2][y2 - 1] - b[x2][y1] - b[x1][y2 - 1] + b[x1][y1];
        printf("%d\n", ans);
    }

    return 0;
}