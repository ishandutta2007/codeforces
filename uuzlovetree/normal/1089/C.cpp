#include<bits/stdc++.h>
#define maxn 505
using namespace std;
int n,m;
int head[maxn],p;
struct edge
{
	int to,next;
}e[maxn*maxn*2];
void addedge(int u,int v)
{
	e[++p].to=v;e[p].next=head[u];head[u]=p;
	e[++p].to=u;e[p].next=head[v];head[v]=p;
}
bool ban[maxn];
int dis1[maxn],dis2[maxn],res;
int bfs(int s,int *d)
{
	queue<int> q;
	for(int i=1;i<=n;++i)d[i]=0;
	d[s]=1;q.push(s);
	int res=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		res+=d[u]-1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(ban[v]||d[v])continue;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int k,lst=0,x;
		cin>>k;
		while(k--)
		{
			cin>>x;
			if(lst)addedge(x,lst);
			lst=x;
		}
	}
	for(int T=1;T<=n;++T)
	{
		memset(ban,0,sizeof(ban));
		while(1)
		{
			int id=0,minv=(n+1)*(n+1);
			for(int i=1;i<=n;++i)if(!ban[i])
			{
				int t=bfs(i,dis1);
				if(t<minv)minv=t,id=i;
			}
			cout<<id<<endl;
			fflush(stdout);
			string opt;
			int x;
			cin>>opt;
			if(opt=="FOUND")break;
			else cin>>x;
			bfs(id,dis1);
			bfs(x,dis2);
			for(int i=1;i<=n;++i)if(dis1[i]<=dis2[i])ban[i]=1;
		}
	}
}