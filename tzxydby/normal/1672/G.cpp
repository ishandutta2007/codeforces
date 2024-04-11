#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=998244353;
int n,m,p[N*N],f,g,vis[N*2],x,b[N*2];
char a[N][N];
vector<int>e[N*2];
void dfs(int u,int fr)
{
	f++;
	vis[u]=1;
	x^=b[u];
	for(auto v:e[u])
	{
		if(v==fr)
			continue;
		if(!vis[v])
			dfs(v,u);
		else
			g++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	p[0]=1;
	for(int i=1;i<=n*m;i++)
		p[i]=2*p[i-1]%mod;
	if(n%2==0&&m%2==0)
	{
		int c=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				c+=a[i][j]=='?';
		printf("%d\n",p[c]);
	}
	if(n%2==0&&m%2==1)
	{
		int t=0;
		for(int v=0;v<2;v++)
		{
			int s=1;
			for(int i=1;i<=n;i++)
			{
				int c=0,w=0;
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]=='1')
						w^=1;
					if(a[i][j]=='?')
						c++;
				}
				if(c==0&&w!=v)
					s=0;
				else if(c)
					s=1ll*s*p[c-1]%mod;
			}
			t=(t+s)%mod;
		}
		printf("%d\n",t);
	}
	if(n%2==1&&m%2==0)
	{
		int t=0;
		for(int v=0;v<2;v++)
		{
			int s=1;
			for(int i=1;i<=m;i++)
			{
				int c=0,w=0;
				for(int j=1;j<=n;j++)
				{
					if(a[j][i]=='1')
						w^=1;
					if(a[j][i]=='?')
						c++;
				}
				if(c==0&&w!=v)
					s=0;
				else if(c)
					s=1ll*s*p[c-1]%mod;
			}
			t=(t+s)%mod;
		}
		printf("%d\n",t);
	}
	if(n%2==1&&m%2==1)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='1')
					b[i]^=1,b[j+n]^=1;
				if(a[i][j]=='?')
					e[i].push_back(j+n),e[j+n].push_back(i);
			}
		}
		for(int v=0;v<2;v++)
		{
			int s=1;
			for(int i=1;i<=n+m;i++)
				vis[i]=0;
			for(int i=1;i<=n+m;i++)
			{
				if(vis[i])
					continue;
				f=g=x=0;
				dfs(i,0);
				g>>=1;
				if(f%2==0)
				{
					if(x)
						s=0;
					else
						s=1ll*s*p[g]%mod;
				}
				if(f%2==1)
				{
					if(v!=x)
						s=0;
					else
						s=1ll*s*p[g]%mod;
				}
			}
			t=(t+s)%mod;
		}	
		printf("%d\n",t);
	}
	return 0;
}