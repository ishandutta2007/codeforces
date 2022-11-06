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

int m[105][105], st[105], top[105];
int dp[105][10005];

int main()
{   

    int n, lim, i, j, k, val, n1, sum1, sum2;
    scanf("%d %d", &n, &lim);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &n1);
        top[i]=n1;
        for(j=0; j<n1; j++)
            scanf("%d", &st[j]);
        m[i][0]=0;
        for(j=1; j<=n1; j++)
        {
            sum1=sum2=0;
            for(k=0; k<j; k++) sum2+=st[n1-1-k];
            m[i][j]=sum1+sum2;
            for(k=0; k<j; k++)
            {
                sum1+=st[k];
                sum2-=st[n1-j+k];
                m[i][j]=max(m[i][j], sum1+sum2);                
            }
        }
    }
    /*for(k=0; k<=n; k++)
        for(val=0; val<=10000; val++)
            dp[k][val]=0;*/
    dp[0][0]=1;
    for(k=1; k<=n; k++)
        for(val=0; val<=lim; val++)
        {
            for(i=0; i<=top[k] && i<=val; i++)
            {
                
                if (dp[k-1][val-i])
                    dp[k][val]=max(dp[k-1][val-i]+m[k][i], dp[k][val]);
            }
        }
    printf("%d", dp[n][lim]-1);
}