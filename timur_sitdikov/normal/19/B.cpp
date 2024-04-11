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
using namespace std;

long long dp[2005][4005], cost[2005], bi=1000000000000000;
int time[2005];

int main()
{   
    int n, i, j, mn;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %I64d", &time[i+1], &cost[i+1]);
        time[i+1]++;
    }
    for(i=0; i<=n; i++) 
        for(j=0; j<=2*n; j++)
            dp[i][j]=bi;
    dp[0][0]=0;
    for(i=1; i<=n; i++)
        for(j=0; j<=2*n; j++)
            if (j-time[i]>=0) 
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-time[i]]+cost[i]);
            else dp[i][j]=dp[i-1][j];
    mn=n;
    for(i=n+1; i<=2*n; i++)
        if (dp[n][i]<dp[n][mn]) mn=i;
    printf("%I64d", dp[n][mn]);
}