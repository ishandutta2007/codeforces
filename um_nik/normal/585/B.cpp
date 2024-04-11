#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 111;
int n;
char t[3][N];
bool dp[N][3];
bool g[N][3][N];

void read()
{
    int z;
    scanf("%d%d", &n, &z);
    for (int i = 0; i < 3; i++)
        scanf(" %s ", t[i]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            dp[j][i] = false;
    for (int i = 0; i < 3; i++)
        if (t[i][0] == 's')
        {
            dp[0][i] = true;
            t[i][0] = '.';
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            g[0][i][j] = (t[i][j] == '.');
    for (int i = 1; i < n; i++)
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < n; y++)
            {
                int ny = y + 2 * i;
                g[i][x][y] = ny >= n || g[0][x][ny];
            }
    for (int i = 0; i < n - 1; i++)
        for (int x = 0; x < 3; x++)
        {
            if (!dp[i][x]) continue;
            if (!g[i][x][i + 1]) continue;
            for (int nx = x - 1; nx <= x + 1; nx++)
            {
                if (nx < 0 || nx >= 3) continue;
                if (!g[i][nx][i + 1]) continue;
                if (!g[i + 1][nx][i + 1]) continue;
                dp[i + 1][nx] = true;
            }
        }
    bool ans = false;
    for (int i = 0; i < 3; i++)
        ans |= dp[n - 1][i];
    if (ans)
        printf("YES\n");
    else
        printf("NO\n");
    return;
}

void solve()
{
    read();
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();

    return 0;
}