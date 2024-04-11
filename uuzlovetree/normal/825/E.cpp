#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
vector<int> g[maxn];
int ind[maxn],Ans[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
		ind[u]++;
	}
	priority_queue<int> q;
	for(int i=1;i<=n;++i)if(!ind[i])q.push(i);
	int id=n;
	while(!q.empty())
	{
		int u=q.top();q.pop();
		Ans[u]=id--;
		for(int v:g[u])
		{
			ind[v]--;
			if(!ind[v])q.push(v);
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",Ans[i]);
}