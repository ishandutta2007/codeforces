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

double dp[1<<18];
double g[20][20];

int main()
{   

    int i, j, k, n, m[20], c;
    double curv;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &g[i][j]);
    dp[0]=1.;
    for(k=0; k<(1<<n); k++)
    {
        for(i=c=0; i<n; i++)
            if (!(k&(1<<i))) m[c++]=i;
        curv=2./(double)(c*(c-1));
        for(i=0; i<c; i++)
            for(j=i+1; j<c; j++)
            {
                dp[k|(1<<m[i])]+=g[m[j]][m[i]]*curv*dp[k];
                dp[k|(1<<m[j])]+=g[m[i]][m[j]]*curv*dp[k];
            }
    }
    for(i=0; i<n; i++)
        printf("%.9lf ", dp[((1<<n)-1)^(1<<i)]);
}