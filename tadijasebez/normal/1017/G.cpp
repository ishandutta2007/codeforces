#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
const int S=317;
vector<int> E[N];
vector<pair<pair<int,int> ,int> > G[N];
bool bl[N],pbl[N],mark[N],cl[N];
int lzy[N];
void DFS1(int u, int p, int w, int d)
{
	pbl[u]=bl[u];
	cl[u]=lzy[u]=0;
	G[u].clear();
	if(mark[u])
	{
		if(p) G[p].pb(mp(mp(u,w),d));
		for(int i=0;i<E[u].size();i++) DFS1(E[u][i],u,0,0);
	}
	else
	{
		if(!bl[u]) w++;
		for(int i=0;i<E[u].size();i++) DFS1(E[u][i],p,w,d+1);
	}
}
void DFS2(int u, int d, bool c)
{
	if(mark[u]) d=lzy[u],c|=cl[u];
	else
	{
		bl[u]=pbl[u];
		if(c) bl[u]=0;
		if(!bl[u] && d) d--,bl[u]=1;
	}
	mark[u]=0;
	for(int i=0;i<E[u].size();i++) DFS2(E[u][i],d,c);
}
void SetBlack(int u)
{
	if(!bl[u]){ bl[u]=1;return;}
	lzy[u]++;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i].first.second<lzy[u]) SetBlack(G[u][i].first.first);
	}
}
void SetWhite(int u)
{
	bl[u]=lzy[u]=0;
	cl[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		G[u][i].first.second=G[u][i].second;
		SetWhite(G[u][i].first.first);
	}
}
int t[N],v[N];
int main()
{
	int n,q,i,j,x;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i",&x),E[x].pb(i);
	for(i=1;i<=q;i++) scanf("%i %i",&t[i],&v[i]);
	for(i=1;i<=q;i+=S)
	{
		for(j=i;j<i+S && j<=q;j++) mark[v[j]]=1;
		DFS1(1,0,0,0);
		for(j=i;j<i+S && j<=q;j++)
		{
			if(t[j]==1) SetBlack(v[j]);
			if(t[j]==2) SetWhite(v[j]);
			if(t[j]==3)
			{
				if(bl[v[j]]) printf("black\n");
				else printf("white\n");
			}
		}
		DFS2(1,0,0);
	}
	return 0;
}