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

int next_st[4005][4005], st[4005], d[4005], bi=1000000000;

int main()
{   
    int n, k, i, j, ans=0, lim, max_time=86401;
    scanf("%d %d", &n, &k);
    for(i=1; i<=n; i++)
        scanf("%d %d", &st[i], &d[i]);
    for(i=0; i<=n; i++)
        for(j=0; j<=k; j++)
            next_st[i][j]=bi;
    next_st[0][0]=1;
    for(i=1; i<=n; i++)
    {
        lim=min(i, k);
        for(j=0; j<=lim; j++)
        {
            if (next_st[i-1][j]<st[i]) 
            {
                ans=max(ans, st[i]-next_st[i-1][j]);
                next_st[i][j]=st[i]+d[i];
            }
            else
            {next_st[i][j]=next_st[i-1][j]+d[i];}
            if (j)
            {
                next_st[i][j]=min(next_st[i][j], next_st[i-1][j-1]);
            }
        }
    }
    for(j=0; j<=k; j++)
        if (next_st[n][j]<max_time)
            ans=max(ans, max_time-next_st[n][j]);
    printf("%d", ans);
}