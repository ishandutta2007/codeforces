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
int dp[5005][2505][3];
int a[5005];
const int inf=1999999999;
//dp [i][j][0] : normal
//dp [i][j][1] : Hill
//do [i][j][2] : Being Killed
inline int min(int x,int y,int z)
{
    return min(min(x,y),z);
}
int ans[5005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[0]=-1;
    a[n+1]=-1;
    int j,k;
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=(n+1)/2;j++)
        {
            for (k=0;k<3;k++)
            {
                dp[i][j][k]=inf;
            }
        }
        ans[i]=inf;
    }
    dp[0][0][0]=0;
    for (i=1;i<=n;i++)
    {
        for (j=0;j<=(i+1)/2;j++)
        {
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]);
            if (i==1)
            {
                dp[i][j][1]=max(0,a[2]-(a[1]-1));
            }
            else
            {
                dp[i][j][1]=max(0,a[i+1]-(a[i]-1))+min(max(0,a[i-1]-(a[i]-1))+dp[i-1][j-1][0],max(0,min(a[i-1],a[i-2]-1)-(a[i]-1))+dp[i-1][j-1][2]);
            }
            ans[j]=min(ans[j],dp[i][j][1]);
            dp[i][j][2]=dp[i-1][j][1];
        }
    }
    for (i=1;i<=(n+1)/2;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}