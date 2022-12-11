#include<bits/stdc++.h>
#define maxn 100005 
using namespace std;
int n;
vector< pair<int,int> > g[maxn];
bool vis[maxn];
int d[maxn];
int Ans[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
		d[u]++;d[v]++;
	}
	queue<int> q;
	for(int i=1;i<=n;++i)if(d[i]==1)q.push(i),vis[i]=1;
	int cnt=0;
	memset(Ans,-1,sizeof(Ans));
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(pair<int,int> x:g[u])
		{
			int v=x.first,id=x.second;
			if(Ans[id]==-1)Ans[id]=cnt++;
			if(!vis[v])q.push(v),vis[v]=1;
		}
	}
	for(int i=1;i<n;++i)printf("%d\n",Ans[i]);
}