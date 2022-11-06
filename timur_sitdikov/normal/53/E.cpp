#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

const int maxn=10;
char g[maxn][maxn];
long long dp[1<<maxn][1<<maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, mask1, mask2, i, j, m, k, a, b, count;
    long long ans;
    cin >> n >> m >> k;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a][b]=g[b][a]=1;
        dp[(1<<a)|(1<<b)][(1<<a)|(1<<b)]=2;
    }
    for(mask1=0; mask1<(1<<n); mask1++)
        for(mask2=mask1; mask2; mask2=(mask1&(mask2-1)))
        {
            if (!dp[mask1][mask2])
                continue;
            count=0;
            for(i=0; i<n; i++)
                if (mask2&(1<<i))
                    count++;
            dp[mask1][mask2]/=count;
            for(i=0; i<n; i++)
                if (mask1&(1<<i))
                    for(j=0; j<n; j++)
                        if (g[i][j] && !(mask1&(1<<j)))
                        {
                            if (mask2&(1<<i))
                                dp[mask1^(1<<j)][mask2^(1<<i)^(1<<j)]+=dp[mask1][mask2];
                            else
                                dp[mask1^(1<<j)][mask2^(1<<j)]+=dp[mask1][mask2];
                        }

        }
    ans=0;
    for(i=0; i<(1<<n); i++)
    {
        count=0;
        for(j=0; j<n; j++)
            if (i&(1<<j))
                count++;
        if (count==k)
            ans+=dp[(1<<n)-1][i];
    }
    cout << ans;
}