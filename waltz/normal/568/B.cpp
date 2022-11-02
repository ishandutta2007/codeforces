#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[4005];
int dp2[4005];
int c[4005][4005];
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<=n;i++)
    {
        int j;
        c[i][0]=1;
        for (j=1;j<=i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=modo;
        }
    }
    dp[0]=0;
    dp2[0]=1;
    for (i=1;i<=n;i++)
    {
        int j;
        for (j=1;j<n;j++)
        {
            dp[i]=(dp[i]+(long long)dp[j]*c[i-1][i-j-1])%modo;
            dp2[i]=(dp2[i]+(long long)dp2[j]*c[i-1][i-j-1])%modo;
        }
        dp2[i]+=dp2[i-1];
        dp2[i]++;
        dp2[i]%=modo;
        dp[i]+=dp2[i-1];
        dp[i]%=modo;
        //printf("dp[%d] = %d               dp2[%d] = %d\n",i,dp[i],i,dp2[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}