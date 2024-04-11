#include <bits/stdc++.h>
using namespace std;

bool a[1001], b[1001];
short sa[1001], sb[1001];
short cnt[1001][1001];
short dp[1001][1001][51][2];
int n, p, k, r;

short D(int idx, int rem, int dist, bool isa)
{
    if (rem == 0)
    {
        auto ar = isa ? sb : sa;
        return ar[idx + dist - 1] - ar[idx - 1];
    }
    if (idx == n + 1) return 0;

    if (dist == 0) isa = false;
    short &ans = dp[idx][rem][dist][isa];

    if (ans == -1)
    {
        if (dist == 0)
        {
            ans = D(idx + 1, rem, 0, false);

            int maxdist = min(k, n - idx + 1);

            // a idx  
            ans = max(ans, D(idx, rem - 1, maxdist, true));
            ans = max(ans, D(idx, rem - 1, maxdist, false));
        }
        else
        {
            int maxdist = min(k, n - idx + 1);
            ans = max<short>(
                D(idx + 1, rem, dist - 1, isa) + (isa ? b : a)[idx],
                cnt[idx][idx + dist - 1] +
                D(idx + dist, rem - 1, maxdist - dist, !isa)
            );
        }
    }

    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d%d",&n,&p,&k,&r);
    for (int i = 1; i <= r; i++)
    {
        int t; scanf("%d",&t); a[t] = 1;
    }
    int s;
    scanf("%d",&s);
    for (int i = 1; i <= s; i++)
    {
        int t; scanf("%d",&t); b[t] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1] + a[i];
        sb[i] = sb[i - 1] + b[i];
        for (int j = i; j <= n; j++)
        {
            cnt[i][j] = cnt[i][j - 1] + (a[j] | b[j]);
        }
    }

    printf("%d\n", D(1, p, 0, false));
}