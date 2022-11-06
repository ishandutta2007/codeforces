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

const int maxn=19;
char g[maxn][maxn];
long long dp[1<<maxn][maxn];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, k, l, n, m, a, b;
    long long ans;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a][b]=g[b][a]=1;
    }
    ans=0;
    for(i=n-1; i>0; i--)
    {
        for(k=0; k<i; k++)
            dp[(1<<i)|(1<<k)][k]=g[i][k];
        for(j=(1<<i)+1; j<(1<<(i+1)); j++)
            for(k=0; k<i; k++)
                if (j&(1<<k))
                {
                    for(l=0; l<i; l++)
                        if (!(j&(1<<l)))
                            dp[j|(1<<l)][l]+=g[k][l]*dp[j][k];
                    ans+=g[i][k]*dp[j][k];
                }
    }
    ans-=m;
    ans/=2; 
    printf("%I64d", ans);

}