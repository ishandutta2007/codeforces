#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[1005][1005][2];
bool h[1005][1005];
signed main()
{
	int n,m,q,ans=0,x,y,sx,sy,gj,hs=0;
	n=read();
	m=read();
	q=read();
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(i+1<=n)dp[i][j][0]=dp[i+1][j+1][0]+2;
			else dp[i][j][0]=1;
			if(j+1<=m)dp[i][j][1]=dp[i+1][j+1][1]+2;
			else dp[i][j][1]=1;
			ans+=dp[i][j][0]+dp[i][j][1];
		}
	}
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		if(h[x][y]==true)
		{
			h[x][y]=false;
			hs--;
			sx=x;
			sy=y;
			ans-=dp[x][y][0]+dp[x][y][1];
			if(x+1>n||h[x+1][y]==true)dp[x][y][0]=1;
			else dp[x][y][0]=dp[x+1][y+1][0]+2;
			if(y+1>m||h[x][y+1]==true)dp[x][y][1]=1;
			else dp[x][y][1]=dp[x+1][y+1][1]+2;
			ans+=dp[x][y][0]+dp[x][y][1];
			gj=0;
			while(sx>=1&&sy>=1)
			{
				if(gj==0)sx--;
				else sy--;
				if(sx<=0||sy<=0)break;
				if(h[sx][sy]==true)break;
				if(gj==0)
				{
				ans-=dp[sx][sy][0];
				if(h[sx+1][sy]==true)dp[sx][sy][0]=1;
				else dp[sx][sy][0]=dp[sx+1][sy+1][0]+2;
				ans+=dp[sx][sy][0];
				}
				else
				{
				ans-=dp[sx][sy][1];
				if(h[sx][sy+1]==true)dp[sx][sy][1]=1;
				else dp[sx][sy][1]=dp[sx+1][sy+1][1]+2;
				ans+=dp[sx][sy][1];
				}
				gj=1-gj;
			}
			gj=1;
			sx=x;
			sy=y;
			while(sx>=1&&sy>=1)
			{
				if(gj==0)sx--;
				else sy--;
				if(sx<=0||sy<=0)break;
				if(h[sx][sy]==true)break;
				if(gj==0)
				{
				ans-=dp[sx][sy][0];
				if(h[sx+1][sy]==true)dp[sx][sy][0]=1;
				else dp[sx][sy][0]=dp[sx+1][sy+1][0]+2;
				ans+=dp[sx][sy][0];
				}
				else
				{
				ans-=dp[sx][sy][1];
				if(h[sx][sy+1]==true)dp[sx][sy][1]=1;
				else dp[sx][sy][1]=dp[sx+1][sy+1][1]+2;
				ans+=dp[sx][sy][1];
				}
				gj=1-gj;
			}
			//printf("%lld\n",ans);
			printf("%lld\n",ans-n*m+hs);
		}
		else
		{
			h[x][y]=true;
			hs++;
			sx=x;
			sy=y;
			ans-=dp[x][y][0]+dp[x][y][1];
			dp[x][y][0]=dp[x][y][1]=0;
			gj=0;
			while(sx>=1&&sy>=1)
			{
				if(gj==0)sx--;
				else sy--;
				if(sx<=0||sy<=0)break;
				if(h[sx][sy]==true)break;
				if(gj==0)
				{
				ans-=dp[sx][sy][0];
				if(h[sx+1][sy]==true)dp[sx][sy][0]=1;
				else dp[sx][sy][0]=dp[sx+1][sy+1][0]+2;
				ans+=dp[sx][sy][0];
				}
				else
				{
				ans-=dp[sx][sy][1];
				if(h[sx][sy+1]==true)dp[sx][sy][1]=1;
				else dp[sx][sy][1]=dp[sx+1][sy+1][1]+2;
				ans+=dp[sx][sy][1];
				}
				gj=1-gj;
			}
			sx=x;
			sy=y;
			gj=1;
			while(sx>=1&&sy>=1)
			{
				if(gj==0)sx--;
				else sy--;
				if(sx<=0||sy<=0)break;
				if(h[sx][sy]==true)break;
				if(gj==0)
				{
				ans-=dp[sx][sy][0];
				if(h[sx+1][sy]==true)dp[sx][sy][0]=1;
				else dp[sx][sy][0]=dp[sx+1][sy+1][0]+2;
				ans+=dp[sx][sy][0];
				}
				else
				{
				ans-=dp[sx][sy][1];
				if(h[sx][sy+1]==true)dp[sx][sy][1]=1;
				else dp[sx][sy][1]=dp[sx+1][sy+1][1]+2;
				ans+=dp[sx][sy][1];
				}
				gj=1-gj;
			}
			//printf("%lld\n",ans);
			printf("%lld\n",ans-n*m+hs);
		}
		/*for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				printf("%lld %lld %lld %lld\n",j,k,dp[j][k][0],dp[j][k][1]);
			}
		}*/
	}
	return 0;
}