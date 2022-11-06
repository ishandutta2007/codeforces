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

double dp[202][202][602];
int pr[205], sum[205];

int main()
{   
    int i, j, k, m, l, n, lim=600, tmp, tmp1;
    double ans=0., dd, dd1;
    scanf("%d %d %d", &n, &l, &m);
    for(i=0; i<n; i++)
        scanf("%d", &pr[i]);
    for(i=0; i<n; i++)
        scanf("%d", &sum[i]);
    dp[0][0][m+200]=1;
    for(i=0; i<n; i++)
        for(j=0; j<=i; j++)
        {
            dd=pr[i]/100.;
            dd1=1.-dd;
            for(k=0; k<=lim; k++)
            {
                dp[i+1][j][k]+=dp[i][j][k]*dd1;
                tmp=k+sum[i];
                if (tmp>=lim) tmp=lim;
                if (tmp<0) tmp=0;
                dp[i+1][j+1][tmp]+=dp[i][j][k]*dd;
            }
        }
    for(j=l; j<=n; j++)
        for(k=200; k<=lim; k++)
            ans+=dp[n][j][k];
    printf("%.12lf", ans);
}