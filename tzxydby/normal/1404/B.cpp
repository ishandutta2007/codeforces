#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,sa,sb,da,db,d[N];
vector<int>e[N];
void dfs(int u,int f)
{
	d[u]=d[f]+1;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&sa,&sb,&da,&db);
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(db<=2*da)
		{
			puts("Alice");
			continue;
		}
		dfs(sa,0);
		if(d[sb]-1<=da)
		{
			puts("Alice");
			continue;
		}
		int x=1,y=1;
		for(int i=1;i<=n;i++)
			if(d[i]>d[x])
				x=i;
		dfs(x,0);
		for(int i=1;i<=n;i++)
			if(d[i]>d[y])
				y=i;
		if(d[y]-1>2*da)
			puts("Bob");
		else
			puts("Alice");
	}
	return 0;
}