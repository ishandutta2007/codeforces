#include <bits/stdc++.h>
using namespace std;

constexpr double PI = 3.14159265358979323846;
int x[1005], y[1005], r[1005];
double dp[1005][2][2], ep[1005][2][2];
bool p[1005];
vector<int> graph[1005];

void dfs(int t)
{
    dp[t][0][0] = dp[t][0][1] = dp[t][1][0] = dp[t][1][1] = -1e100;
    ep[t][0][0] = ep[t][0][1] = ep[t][1][0] = ep[t][1][1] = 1e100;

    for (int nxt : graph[t])
    {
        dfs(nxt);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            double x = 1ll * r[t] * r[t] * PI;

            // put left
            double res1 = (i == 0) ? x : -x;
            double res2 = res1;
            for (int nxt : graph[t])
            {
                res1 += dp[nxt][!i][j];
                res2 += ep[nxt][!i][j];
            }

            dp[t][i][j] = max(dp[t][i][j], res1);
            ep[t][i][j] = min(ep[t][i][j], res2);

            // put right
            res1 = (j == 0) ? x : -x;
            res2 = (j == 0) ? x : -x;
            for (int nxt : graph[t])
            {
                res1 += dp[nxt][i][!j];
                res2 += ep[nxt][i][!j];
            }

            dp[t][i][j] = max(dp[t][i][j], res1);
            ep[t][i][j] = min(ep[t][i][j], res2);
        }
    }
}

int main()
{
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);

    for (int i = 0; i < n; i++)
    {
        int p = -1;

        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if ((x[i]-x[j])*1ll*(x[i]-x[j]) + (y[i]-y[j])*1ll*(y[i]-y[j]) <= (r[i]-r[j])*1ll*(r[i]-r[j]) &&
                r[i] < r[j])
            {
                if (p == -1 || r[p] > r[j]) p = j;
            }
        }

        if (p != -1)
        {
            graph[p].push_back(i);
            ::p[i] = true;
        }
    }

    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i]) continue;
        dfs(i);
        ans += dp[i][0][0];
    }

    printf("%.9f\n", ans);
}