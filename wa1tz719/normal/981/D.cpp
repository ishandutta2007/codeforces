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
bool dp[55][55];
long long a[55];
long long sum[55];
int n,k;
long long ans=0;
bool check()
{
    int i;
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for (i=1;i<=n;i++)
    {
        int j;
        for (j=1;j<=k;j++)
        {
            int k;
            for (k=0;k<i;k++)
            {
                if (dp[k][j-1])
                {
                    if (((sum[i]-sum[k])&ans)==ans)
                    {
                        dp[i][j]=true;
                        break;
                    }
                }
            }
        }
    }
    return dp[n][k];
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    int i;
    sum[0]=0;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    for (i=56;i>=0;i--)
    {
        ans^=(1ll<<i);
        if (check())
        {
            continue;
        }
        else
        {
            ans^=(1ll<<i);
        }
    }
    cout<<ans<<endl;
    return 0;
}