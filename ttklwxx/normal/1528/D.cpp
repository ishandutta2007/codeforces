#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mod 1000000007
#define int long long
#define inf 1121131433448687LL
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
int dp[1000005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
vector<int>v[605],bq[605];
int dis[605];
bool vis[605];
int a[500005],b[500005],c[500005];
signed main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		a[i]=read()+1;
		b[i]=read()+1;
		c[i]=read();
		v[a[i]].push_back(b[i]);
		bq[a[i]].push_back(c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)dis[j]=inf,vis[j]=false;
		//dis[i]=0;
		//vis[i]=true;
		for(int j=0;j<v[i].size();j++)dis[v[i][j]]=min(dis[v[i][j]],bq[i][j]);
		for(int j=1;j<=n;j++)
		{
			int minn=inf,mpos=0;
			for(int sth=1;sth<=n;sth++)
			{
				if(vis[sth]==false&&dis[sth]<minn)
				{
					minn=dis[sth];
					mpos=sth;
				}
			}
			vis[mpos]=true;
			dis[mpos%n+1]=min(dis[mpos%n+1],dis[mpos]+1);
			for(int sth=0;sth<v[mpos].size();sth++)
			{
				//if(mpos==i&&(v[mpos][sth]+n+dis[mpos]-1)%n+1==mpos)dis[mpos%n+1]=min(dis[mpos%n+1],dis[i]+bq[mpos][sth]+1);
				dis[(v[mpos][sth]+n+dis[mpos]-1)%n+1]=min(dis[(v[mpos][sth]+n+dis[mpos]-1)%n+1],dis[mpos]+bq[mpos][sth]);
			}
		}
		for(int j=1;j<=n;j++){if(j!=i)printf("%lld ",dis[j]);else printf("0 ");}
		printf("\n");
	}
	return 0;
}