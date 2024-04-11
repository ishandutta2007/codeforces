#include <bits/stdc++.h>
using namespace std;
const int Maxn=1e6+5;
int a[Maxn],cnt[Maxn],dp[Maxn][6][6],ans,n,m;
int main()
{
	scanf("%d%d",&n,&m);
        memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
	for(int i=0;i<3;i++)
    {
        for(int j=0;j<6;j++)
        {
            int x=cnt[1]-i;
            int y=cnt[2]-j;
            if(x>=0&&y>=0) dp[2][i][j]=x/3+y/3;
        }
    }
	for(int i=3;i<=m;i++)
	{
		for(int j=0;j<3;j++)
        {
            for(int k=0;k<6;k++)
            {
                for(int l=0;l<6;l++)
				{
				    if(l>cnt[i]) break;
				    int tt;
				    if(cnt[i]-l<min(j,k)) tt=cnt[i]-l;
				    else tt=min(j,k);
				    int x=(cnt[i]-l-tt)/3;
					dp[i][k-tt][l]=max(dp[i-1][j][k]+tt+x,dp[i][k-tt][l]);
				}
            }
        }
	}
	for(int i=0;i<6;i++)
       for(int j=0;j<6;j++)
           ans=max(ans,dp[m][i][j]);
	printf("%d",ans);
    return 0;
}