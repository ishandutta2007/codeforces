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

char c[100005], cc[100005], g[50];
int dp[100005][30];

int main()
{   
    int i, j, n, l, d=26, bi=1000000, mn;
    char c1[5];
    for(i=0; i<d; i++)
        g[i]=40;
    scanf("%s %d", &c, &n);
    l=strlen(c);
    for(i=0; i<l; i++)
        c[i]-='a';
    for(i=1; i<=l; i++) cc[i]=c[i-1];
    for(i=0; i<n; i++)
    {
        scanf("%s", &c1);
        g[c1[0]-'a']=c1[1]-'a';
        g[c1[1]-'a']=c1[0]-'a';
    }
    for(i=0; i<=l; i++)
        for(j=0; j<d; j++)
            dp[i][j]=bi;
    dp[1][cc[1]]=0;
    for(i=2; i<=l; i++)
    {
        dp[i][cc[i]]=min(dp[i][cc[i]], i-1);
        for(j=0; j<d; j++)
            dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
        for(j=0; j<d; j++)
            if (g[cc[i]]!=j)
                dp[i][cc[i]]=min(dp[i][cc[i]], dp[i-1][j]);
    }
    mn=0;
    for(j=1; j<d; j++)
        if (dp[l][j]<dp[l][mn])
            mn=j;
    printf("%d", dp[l][mn]);
}