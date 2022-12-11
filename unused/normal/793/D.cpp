#include <bits/stdc++.h>
using namespace std;

int graph[88][88];
int dp[88][88][88];
bool v[88][88][88];

constexpr int INF = 1e9;

int D(int now, int lim, int rem)
{
    if (rem == 0) return 0;

    if (v[now][lim][rem] == false)
    {
        v[now][lim][rem] = true;
        dp[now][lim][rem] = INF;

        for (int i = now + 1; i <= lim; i++)
        {
            int dist = graph[now][i];
            if (dist == INF) continue;

            dp[now][lim][rem] = min(dp[now][lim][rem], dist + D(i, lim, rem - 1));
            dp[now][lim][rem] = min(dp[now][lim][rem], dist + D(i, now + 1, rem - 1));
        }

        for (int i = lim; i < now; i++)
        {
            int dist = graph[now][i];
            if (dist == INF) continue;

            dp[now][lim][rem] = min(dp[now][lim][rem], dist + D(i, lim, rem - 1));
            dp[now][lim][rem] = min(dp[now][lim][rem], dist + D(i, now - 1, rem - 1));
        }
    }

    return dp[now][lim][rem];
}

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int m;
    scanf("%d",&m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) graph[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b] = min(graph[a][b], c);
    }

    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, D(i, 1, k - 1));
        ans = min(ans, D(i, n, k - 1));
    }

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}