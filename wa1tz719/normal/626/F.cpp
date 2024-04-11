#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int dp[205][205][1505];
int a[205];
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    dp[0][0][0]=1;
    for (i=0;i<n-1;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            int l;
            for (l=0;l<=k;l++)
            {
                if (l+j*(a[i+1]-a[i])<=k)
                {
                    dp[i+1][j][l+j*(a[i+1]-a[i])]+=dp[i][j][l];
                    dp[i+1][j][l+j*(a[i+1]-a[i])]%=modo;
                }
                if (l+(j+1)*(a[i+1]-a[i])<=k)
                {
                    dp[i+1][j+1][l+(j+1)*(a[i+1]-a[i])]+=dp[i][j][l];
                    dp[i+1][j+1][l+(j+1)*(a[i+1]-a[i])]%=modo;
                }
                if (l+j*(a[i+1]-a[i])<=k)
                {
                    dp[i+1][j][l+j*(a[i+1]-a[i])]+=(long long)dp[i][j][l]*j%modo;
                    dp[i+1][j][l+j*(a[i+1]-a[i])]%=modo;
                }
                if (j==0) continue;
                if (l+(j-1)*(a[i+1]-a[i])<=k)
                {
                    dp[i+1][j-1][l+(j-1)*(a[i+1]-a[i])]+=(long long)dp[i][j][l]*j%modo;
                    dp[i+1][j-1][l+(j-1)*(a[i+1]-a[i])]%=modo;
                }
            }
        }
    }
    int sum=0;
    int l;
    for (l=0;l<=k;l++)
    {
        sum+=dp[n-1][0][l];
        sum%=modo;
        sum+=dp[n-1][1][l];
        sum%=modo;
    }
    printf("%d\n",sum);
    return 0;
}