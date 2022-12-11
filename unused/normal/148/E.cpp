#include <bits/stdc++.h>
using namespace std;

vector<int> dat[105];
int dp[105][10005];
bool v[105][10005];
int csum[105];
int val[105][105];
int n;

int D(int idx, int rem)
{
    if (csum[n] - csum[idx - 1] < rem) return -1e9;
    if (rem == 0) return 0;

    if (v[idx][rem] == false)
    {
        v[idx][rem] = true;

        for (int i = 0; i <= min(rem, (int)dat[idx].size()); i++)
        {
            dp[idx][rem] = max(dp[idx][rem],
                D(idx + 1, rem - i) + val[idx][i]);
        }
    }

    return dp[idx][rem];
}

int tmp[105];

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d",&t);
        dat[i].resize(t);
        for (int j = 0; j < t; j++) scanf("%d",&dat[i][j]);

        csum[i] = csum[i - 1] + t;

        val[i][0] = 0;
        for (int j = 0; j < t; j++) tmp[j + 1] = tmp[j] + dat[i][j];

        for (int j = 1; j <= t; j++)
        {
            val[i][j] = 0;
            for (int k = 0; k <= j; k++)
            {
                val[i][j] = max(val[i][j],
                    tmp[k] + tmp[t] - tmp[t - (j - k)]);
            }
        }
    }

    printf("%d\n", D(0, m));
}