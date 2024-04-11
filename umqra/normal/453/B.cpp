#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int INF = (int)1e9;
int dp[102][(1 << 17)];
int par[102][(1 << 17)];
int maskNum[100];
int listP[100];
int indP = 0;
int used[100];
int a[102];

void printAns(int n, int mask)
{
    if (n == 0)
        return;
    int v = par[n][mask];
    printAns(n - 1, mask ^ maskNum[v]);
    printf("%d ", v);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 2; i < 61; i++)
    {
        if (!used[i])
        {
            listP[indP++] = i;
            for (int s = i; s < 61; s += i)
                used[s] = 1;
        }
    }
    for (int i = 1; i < 61; i++)
    {
        for (int s = 0; s < indP; s++)
        {
            if ((i % listP[s]) == 0)
                maskNum[i] |= (1 << s);
        }
    }
    for (int i = 0; i <= n; i++)
        for (int s = 0; s < (1 << indP); s++)
            dp[i][s] = INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int s = 0; s < (1 << indP); s++)
        {
            if (dp[i][s] == INF)
                continue;
            for (int val = 1; val < 61; val++)
            {
                if ((maskNum[val] & s) == 0)
                {
                    dp[i + 1][s | maskNum[val]] = min(dp[i + 1][s | maskNum[val]], dp[i][s] + abs(val - a[i]));
                    if (dp[i + 1][s | maskNum[val]] == dp[i][s] + abs(val - a[i]))
                        par[i + 1][s | maskNum[val]] = val;
                }
            }
        }
    int ans = INF;
    int ms = 0;
    for (int i = 0; i < (1 << indP); i++)
    {
        if (dp[n][i] < ans)
        {
            ans = dp[n][i];
            ms = i;
        }
    }
    printAns(n, ms);
    return 0;
}