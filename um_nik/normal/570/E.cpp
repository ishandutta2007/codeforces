#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 502;
int n, m;
int k;
char s[N][N];
int dp[2][N][N];

const int MOD = (int)1e9 + 7;
void add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(int len)
{
    for (int y1 = 0; y1 < m; y1++)
    {
        int x1 = len - y1;
        if (x1 < 0 || x1 >= n) continue;
        for (int y2 = y1; y2 < m; y2++)
        {
            int x2 = n + m - 2 - len - y2;
            if (x2 < x1 || x2 >= n) continue;
            if (dp[0][y1][y2] == 0) continue;
            if (check(x1 + 1, y1))
            {
                if (check(x2 - 1, y2) && s[x1 + 1][y1] == s[x2 - 1][y2])
                    add(dp[1][y1][y2], dp[0][y1][y2]);
                if (check(x2, y2 - 1) && s[x1 + 1][y1] == s[x2][y2 - 1])
                    add(dp[1][y1][y2 - 1], dp[0][y1][y2]);
            }
            if (check(x1, y1 + 1))
            {
                if (check(x2 - 1, y2) && s[x1][y1 + 1] == s[x2 - 1][y2])
                    add(dp[1][y1 + 1][y2], dp[0][y1][y2]);
                if (check(x2, y2 - 1) && s[x1][y1 + 1] == s[x2][y2 - 1])
                    add(dp[1][y1 + 1][y2 - 1], dp[0][y1][y2]);
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            dp[0][i][j] = dp[1][i][j];
            dp[1][i][j] = 0;
        }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(" %s ", s[i]);
    if (s[0][0] != s[n - 1][m - 1])
    {
        printf("0\n");
        return 0;
    }
    k = (n + m - 2) / 2;
    dp[0][0][m - 1] = 1;
    for (int i = 0; i < k; i++)
        solve(i);

    if ((n + m) & 1)
    {
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            add(ans, dp[0][i][i]);
            if (i < m - 1)
                add(ans, dp[0][i][i + 1]);
        }
        printf("%d\n", ans);
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < m; i++)
            add(ans, dp[0][i][i]);
        printf("%d\n", ans);
    }

    return 0;
}