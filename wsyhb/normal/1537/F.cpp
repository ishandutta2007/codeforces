#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int col[max_n];
bool flag_odd_cycle;
void dfs(int x,int fa)
{
	col[x]=col[fa]^1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			if(col[y]==2)
			{
				dfs(y,x);
				if(flag_odd_cycle)
					return;
			}
			else if(col[x]==col[y])
			{
				flag_odd_cycle=true;
				return;
			}
		}
	}
}
int v[max_n],t[max_n];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			Last[i]=0;
		e=0;
		for(int i=1;i<=n;++i)
			scanf("%d",v+i);
		for(int i=1;i<=n;++i)
			scanf("%d",t+i);
		for(int i=1;i<=m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		int d=0;
		for(int i=1;i<=n;++i)
			d^=(v[i]^t[i])&1;
		if(d)
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;++i)
			col[i]=2;
		flag_odd_cycle=false;
		dfs(1,0);
		if(flag_odd_cycle)
			puts("YES");
		else
		{
			long long delta=0;
			for(int i=1;i<=n;++i)
				delta+=(col[i]==1?1:-1)*(v[i]-t[i]);
			puts(delta?"NO":"YES");
		}
	}
	return 0;
}