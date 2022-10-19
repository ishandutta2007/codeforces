#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define inf 112131433448687000LL
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
struct sth
{
	int x,y,id;
}s[400005];
int dp[400005];
bool bi(struct sth c,struct sth d)
{
	if(c.x!=d.x)return c.x<d.x;
	return c.y<d.y;
}
int dx[400005];
int h[400005];
int dy[400005];
signed main()
{
	int t,n,m,k,r,minn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=n;i++)dx[i]=read();
		for(int i=1;i<=k;i++)
		{
			s[2*i-1].x=read();
			s[2*i-1].y=read();
			s[2*i-1].id=2*i-1;
			s[2*i].x=read();
			s[2*i].y=read();
			s[2*i].id=2*i;
			h[i]=read();
		}
		s[2*k+1].x=s[2*k+1].y=1;
		s[2*k+1].id=2*k+1;
		s[2*k+2].x=n;
		s[2*k+2].y=m;
		s[2*k+2].id=2*k+2;
		sort(s+1,s+2*k+3,bi);
		for(int i=1;i<=2*k+2;i++)
		{
			dy[s[i].id]=i;
			if(s[i].id==2*k+1)dp[i]=0;
			else dp[i]=inf;
		}
		for(int i=1;i<=2*k+2;i=r+1)
		{
			r=i;
			while(r+1<=2*k+2&&s[r+1].x==s[i].x)r++;
			for(int j=i;j<=r;j++)
			{
				if(s[j].id%2==1||s[j].id==2*k+2)continue;
				dp[j]=dp[dy[s[j].id-1]]-h[s[j].id/2];
			}
			minn=dp[i]-s[i].y*dx[s[i].x];
			for(int j=i+1;j<=r;j++)
			{
				dp[j]=min(dp[j],minn+s[j].y*dx[s[j].x]);
				minn=min(minn,dp[j]-s[j].y*dx[s[j].x]);
			}
			minn=dp[r]+s[r].y*dx[s[r].x];
			for(int j=r-1;j>=i;j--)
			{
				dp[j]=min(dp[j],minn-s[j].y*dx[s[j].x]);
				minn=min(minn,dp[j]+s[j].y*dx[s[j].x]);
			}
			//for(int j=i;j<=r;j++)printf("%lld %lld %lld\n",s[j].x,s[j].y,dp[j]);
		}
		for(int i=1;i<=2*k+2;i++)
		{
			if(s[i].id==2*k+2)
			{
				if(dp[i]>=inf/2)
				{
					printf("NO ESCAPE\n");
					break;
				}
				else
				{
					printf("%lld\n",dp[i]);
					break;
				}
			}
		}
	}
	return 0;
}