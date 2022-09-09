#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const int mod=1e9+7;
vector<int> Tree[N];
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x)
		p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	if(r[x]>r[y]) p[y]=x;
	if(r[y]>r[x]) p[x]=y;
	if(r[y]==r[x]) r[x]++,p[y]=x;
}
int par[N],Depth[N];
bool vis[N];
void DFS(int cur, int prev, int depth)
{
	par[cur]=prev;
	vis[cur]=true;
	Depth[cur]=depth;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(!vis[v]) DFS(v,cur,depth+1);
	}
}
void Set(int u, int v)
{
	if(Depth[u]>Depth[v])
	{
		int tmp=u;
		u=v;
		v=tmp;
	}
	int i;
	while(Depth[v]>Depth[u])
	{
		vis[v]=true;
		//for(i=0;i<Tree[v].size();i++)
		//{
		//	int h=Tree[v][i];
		//	vis[h]=true;
		//}
		v=par[v];
	}
	while(v!=u)
	{
		vis[v]=true;
		//for(i=0;i<Tree[v].size();i++)
		//{
		//	int h=Tree[v][i];
		//	vis[h]=true;
		//}
		vis[u]=true;
		//for(i=0;i<Tree[u].size();i++)
		//{
		//	int h=Tree[u][i];
		//	vis[h]=true;
		//}
		v=par[v];
		u=par[u];
	}
	//for(i=0;i<Tree[v].size();i++)
	//{
	//	int h=Tree[v][i];
	//	vis[h]=true;
	//}
}
vector< pair<int,int> > loops;
int ans;
long long sol=1;
void DFS(int cur)
{
	vis[cur]=1;
	ans++;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(!vis[v]) DFS(v);
		
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=2*n;i++) p[i]=i;
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		//if(u==v) vis[u]=1;
		//else
		//{
		int x=Find(u);
		int y=Find(v);
		if(x==y && u==v) loops.push_back(make_pair(u,v));
		else if(x==y) loops.push_back(make_pair(u,v)),sol=sol*2%mod;
		else Tree[u].push_back(v),Tree[v].push_back(u),Union(x,y);
		//}
	}
	for(i=1;i<=2*n;i++)
	{
		if(!vis[i]) DFS(i,0,1);
	}
	for(i=1;i<=2*n;i++) vis[i]=0;
	for(i=0;i<loops.size();i++)
	{
		//printf("%i %i\n",loops[i].first,loops[i].second);
		//Set(loops[i].first,loops[i].second);
		DFS(loops[i].first);
		//sol=sol*2%mod;
	}
	for(i=1;i<=2*n;i++)
	{
		ans=0;
		if(!vis[i])
		{
			//printf("%i\n",i);
			DFS(i);
			sol=sol*ans%mod;
		}
	}
	printf("%lld\n",sol);
}