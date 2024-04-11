#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005][11][2];
bool v[1005][1005][11][2];
char s1[1005], s2[1005];

int D(int a, int b, int k, bool f)
{
    if (k == 0) return 0;
    if (a < 0 || b < 0)
    {
        return k == 1 && f ? 0 : -1e9;
    }

    if (v[a][b][k][f] == false)
    {
        v[a][b][k][f] = true;

        if (f) dp[a][b][k][f] = D(a,b,k-1,false);
        else dp[a][b][k][f] = max(D(a-1,b,k,false),D(a,b-1,k,false));

        if (s1[a] == s2[b])
        {
            dp[a][b][k][f] = max(dp[a][b][k][f], 1 + D(a-1,b-1,k,true));
        }
    }
    return dp[a][b][k][f];
}

int main()
{
    int n, m, k;
    scanf("%d%d%d%s%s",&n,&m,&k,s1,s2);

    printf("%d\n", D(strlen(s1) - 1, strlen(s2) - 1, k, false));
}