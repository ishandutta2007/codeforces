#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int s[111];
int dp[3000000];
int n, m;
char act[30];
int team[30];
char w;
int INF = (int)1e9;
int ans;
int q[3000000][2];
int k;

bool cmp(int x, int y)
{
    return (x > y);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n, cmp);
    scanf("%d%c", &m, &w);
    for (int i = 0; i < m; i++)
        scanf("%c%c%d%c", &act[i], &w, &team[i], &w);

    for (int i = 0; i < (1 << m); i++)
        dp[i] = INF;
    k = 0;
    dp[0] = 0;
    q[0][0] = 0;
    q[0][1] = m - 1;
    //printf("%d\n", (1 << m));
    for (int h = 0; h < (1 << m) - 1; h++)
    {
        for (int i = 0; i < m; i++)
        {
            //printf("%d %d %d\n", i, h, q[h][0]);
            if (((1 << i) & q[h][0]) == 0)
            {
                int x = (1 << i) ^ q[h][0];
                //printf("%d\n", x);
                if (team[q[h][1]] == 1)
                {
                    if (dp[x] == INF)
                    {
                        k++;
                        q[k][0] = x;
                        q[k][1] = q[h][1] - 1;
                    }
                    if (act[q[h][1]] == 'p')
                    {
                        dp[x] = min(dp[x], dp[q[h][0]] - s[i]);
                    }
                    else
                    {
                        dp[x] = min(dp[x], dp[q[h][0]]);
                    }
                }
                else
                {
                    if (dp[x] == INF)
                    {
                        dp[x] = -INF;
                        k++;
                        q[k][0] = x;
                        q[k][1] = q[h][1] - 1;
                    }
                    if (act[q[h][1]] == 'p')
                    {
                        dp[x] = max(dp[x], dp[q[h][0]] + s[i]);
                    }
                    else
                    {
                        dp[x] = max(dp[x], dp[q[h][0]]);
                    }
                }
                //printf("%d %d\n", x, dp[x]);
            }
        }
        //printf("%d %d %d\n", h, k, dp[h]);
    }
    //printf("%d\n", k);
    printf("%d\n", -dp[(1 << m) - 1]);
    //cin >> n;
    return 0;
}