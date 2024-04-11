#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int W=1e9;
const int M=64*N;
int x[M],ls[M],rs[M],clock;
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+1;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int min(int a, int b){ return a>b?b:a;}
vector<pair<int,int> > E[N];
bool vis[N];
int sz[N];
void DFS(int u, int p, int &n)
{
	n++;sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v]) DFS(v,u,n),sz[u]+=sz[v];
	}
}
int Find(int u, int p, int n)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v] && sz[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
vector<pair<int,pair<int,int> > > lzy;
vector<pair<int,int> > bck[N];
vector<vector<int> > root;
void Process(int u, int p, int s, int d, int path)
{
	while(root[0].size()<=d) root[0].pb(0);
	while(root[s].size()<=d) root[s].pb(0);
	bck[0].pb(mp(d,path));
	bck[s].pb(mp(d,path));
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		if(v!=p && !vis[v]) Process(v,u,s,d+1,path+w);
	}
}
int len,val;
ll sol;
void Decompose(int u)
{
	u=Find(u);vis[u]=1;
	clock=0;
	root.clear();
	root.pb(vector<int>(0));
	bck[0].pb(mp(0,0));
	bck[0].pb(mp(0,0));
	int i,j,k;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		if(!vis[v])
		{
			root.push_back(vector<int>(0));
			Process(v,u,root.size()-1,1,w);
		}
	}
	for(i=0;i<root.size();i++)
	{
		sort(bck[i].begin(),bck[i].end());
		k=0;
		for(j=0;j<root[i].size();j++)
		{
			if(j) root[i][j]=root[i][j-1];
			for(;k<bck[i].size() && bck[i][k].first==j;k++)
			{
				Set(root[i][j],root[i][j],0,W,bck[i][k].second);
			}
		}
	}
	//printf("R:%i:",root.size());
	for(i=1;i<root.size();i++)
	{
		for(k=0;k<bck[i].size();k++)
		{
			int L=min(root[0].size()-1,len-bck[i][k].first);
			if(L<0) continue;
			sol+=Get(root[0][L],0,W,0,val-bck[i][k].second);
			L=min(root[i].size()-1,len-bck[i][k].first);
			if(L<0) continue;
			sol-=Get(root[i][L],0,W,0,val-bck[i][k].second);
		}
		//printf(":%lld:",sol);
	}
	for(i=0;i<root.size();i++) bck[i].clear();
	root.clear();
	//printf("U:%i:%lld\n",u,sol);
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Decompose(v);
	}
}
int main()
{
	int n,i,u,v,w;
	scanf("%i %i %i",&n,&len,&val);
	for(u=2;u<=n;u++) scanf("%i %i",&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	Decompose(1);
	printf("%lld\n",sol/2);
	return 0;
}