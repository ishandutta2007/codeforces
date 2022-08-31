#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)1e8;
const int N = 420;
int n;
int g[N][N];

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = (i == j ? 0 : INF);
    while(m--)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v][u] = g[u][v] = 1;
    }
    if (g[0][n - 1] == 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i != j) g[i][j] = INF + 1 - g[i][j];
            }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    if (g[0][n - 1] == INF)
        printf("-1\n");
    else
        printf("%d\n", g[0][n - 1]);

    return 0;
}