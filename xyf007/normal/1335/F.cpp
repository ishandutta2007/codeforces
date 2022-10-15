#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define id(x, y) m * (x - 1) + y
using namespace std;
int t, n, m, nxt[1000001][21];
char col[1000001], s[1000001];
bool vis[1000001][2];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d\n", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &col[id(i, j)]);
            }
            getchar();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int pos = id(i, j);
                scanf("%c", &s[pos]);
                switch (s[pos])
                {
                case 'U':
                    nxt[pos][0] = id(i - 1, j);
                    break;
                case 'R':
                    nxt[pos][0] = id(i, j + 1);
                    break;
                case 'D':
                    nxt[pos][0] = id(i + 1, j);
                    break;
                default:
                    nxt[pos][0] = id(i, j - 1);
                    break;
                }
            }
            getchar();
        }
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= n * m; j++)
            {
                nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                vis[nxt[id(i, j)][20]][col[id(i, j)] - '0'] = 1;
            }
        }
        int ans = 0, maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[id(i, j)][0])
                {
                    ans++;
                    maxx++;
                    vis[id(i, j)][0] = vis[id(i, j)][1] = 0;
                }
                else
                {
                    if (vis[id(i, j)][1])
                    {
                        ans++;
                        vis[id(i, j)][0] = vis[id(i, j)][1] = 0;
                    }
                }
            }
        }
        printf("%d %d\n", ans, maxx);
    }
    return 0;
}