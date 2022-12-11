#include<bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=1e6+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],deg[max_n],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e,++deg[x];
	End[++e]=x,Next[e]=Last[y],Last[y]=e,++deg[y];
}
int dis[max_n],ans=1;
void dfs(int x,int fa)
{
	vector<int> d;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			d.push_back(dis[y]+1);
		}
	}
	if(d.empty())
		dis[x]=0;
	else
	{
		sort(d.begin(),d.end());
		while((int)d.size()>=2&&d[(int)d.size()-2]+d.back()>k)
		{
			d.pop_back();
			++ans;
		}
		dis[x]=d.back();
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	int rt=0;
	for(int i=1;i<=n;++i)
	{
		if(deg[i]>1)
		{
			rt=i;
			break;
		}
	}
	dfs(rt,0);
	printf("%d\n",ans);
	return 0;
}