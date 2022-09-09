#include <stdio.h>
#include <vector>
using namespace std;
const int N=300050;
vector<int> Tree[N];
int parent[N],ranks[N];
int Find(int u)
{
	if(parent[u]!=u)
		parent[u]=Find(parent[u]);
	return parent[u];
}
void Union(int u, int v)
{
	int x=Find(u);
	int y=Find(v);
	if(ranks[x]>ranks[y]) parent[y]=x;
	else if(ranks[x]<ranks[y]) parent[x]=y;
	else ranks[x]++,parent[y]=x;
}
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c){ return max(a,max(b,c));}
int ans;
bool visited[N];
int val[N];
int DFS(int cur, int prev, int depth)
{
	int tmp=depth;
	ans=max(ans,tmp);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			int t=DFS(v,cur,depth+1);
			ans=max(ans,t+tmp-2*depth);
			tmp=max(tmp,t);
		}
	}
	return tmp;
}
int main()
{
	int n,m,q,i,u,v,t;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) parent[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%i %i",&u,&v);
		Union(u,v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		u=Find(i);
		if(!visited[u])
		{
			ans=0;
			DFS(u,0,0);
			val[u]=ans;
			visited[u]=true;
		}
	}
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i",&u);
			printf("%i\n",val[Find(u)]);
		}
		if(t==2)
		{
			scanf("%i %i",&u,&v);
			u=Find(u);
			v=Find(v);
			if(u!=v)
			{
				val[u]=val[v]=max(val[u],val[v],(val[u]+1)/2+(val[v]+1)/2+1);
				Union(u,v);
			}
		}
	}
	return 0;
}