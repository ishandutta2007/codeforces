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

const int maxn=100005, inf=1000000000;
int x[maxn], y[maxn];
int dp[maxn][2], good[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, y0, y1, ans;
    cin >> n >> m >> y0 >> y1;
    if (!m)
    {
        cout << n;
        return 0;
    }
    for(i=1; i<=n; i++)
        cin >> x[i];
    for(j=1; j<=m; j++)
        cin >> y[j];
    y[0]=-inf;
    y[m+1]=inf;
    i=j=1;
    for(; i<=n; i++)
    {
        while(y[j]<x[i]) j++;
        good[i]=j;
    }
    for(i=0; i<=n; i++)
        dp[i][0]=dp[i][1]=inf;
    dp[0][0]=0;
    for(i=0; i<n; i++)
    {
        if (dp[i][0]<inf)
        {
            if (good[i+1]>1 && y[good[i+1]]-x[i+1]>=x[i+1]-y[good[i+1]-1])
            {
                if (good[i+1]!=good[i])
                    dp[i+1][0]=min(dp[i+1][0], dp[i][0]);
                else dp[i+1][0]=min(dp[i+1][0], dp[i][0]+1);
            }
            if (good[i+1]!=m+1 && y[good[i+1]]-x[i+1]<=x[i+1]-y[good[i+1]-1])
                dp[i+1][1]=min(dp[i+1][1], dp[i][0]);
        }
        if (dp[i][1]<inf)
        {
            if (good[i+1]>=good[i]+1 && y[good[i+1]]-x[i+1]>=x[i+1]-y[good[i+1]-1])
            {
                if (good[i+1]!=good[i]+1 || x[i+1]-y[good[i+1]-1]==y[good[i+1]-1]-x[i])
                    dp[i+1][0]=min(dp[i+1][0], dp[i][1]);
                else dp[i+1][0]=min(dp[i+1][0], dp[i][1]+1);
            }
            if (good[i+1]!=m+1 && y[good[i+1]]-x[i+1]<=x[i+1]-y[good[i+1]-1])
            {
                if (good[i+1]==good[i])
                    dp[i+1][1]=min(dp[i+1][1], dp[i][1]+1);
                else 
                    dp[i+1][1]=min(dp[i+1][1], dp[i][1]);
            }
        }
    }
    ans=min(dp[n][0], dp[n][1]);
    cout << ans;
}