#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
vector<pair<int,int> > edges[M];
void AddEdge(int &c, int ss, int se, int qs, int qe, int u, int v)
{
	if(qs>se || ss>qe || qs>qe) return;
	//if(se==N) printf("%i %i %i %i\n",qs,qe,u,v);
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ edges[c].pb(mp(u,v));return;}
	int mid=ss+se>>1;
	AddEdge(ls[c],ss,mid,qs,qe,u,v);
	AddEdge(rs[c],mid+1,se,qs,qe,u,v);
}
int p[N],c[N],w[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i,c[i]=1;}
int Find(int x){ return p[x]==x?x:Find(p[x]);}
int FindPath(int x){ return p[x]==x?0:w[x]+FindPath(p[x]);}
vector<int> bck,del;
int bad;
void AddEdge(int u, int v)
{
	//printf("Add Edge (%i %i)\n",u,v);
	if(Find(u)==Find(v))
	{
		if(!((FindPath(u)+FindPath(v))&1)) bck.pb(1),bad++;
		else bck.pb(0);
		del.pb(0);
	}
	else
	{
		bck.pb(0);
		int d1=FindPath(u),d2=FindPath(v);
		u=Find(u);v=Find(v);
		if(c[u]>c[v])
		{
			c[u]+=c[v];
			p[v]=u;
			w[v]=1-d2+d1;
			del.pb(v);
		}
		else
		{
			c[v]+=c[u];
			p[u]=v;
			w[u]=1-d1+d2;
			del.pb(u);
		}
	}
}
void DelEdge()
{
	//printf("Delete Edge\n");
	bad-=bck.back();
	bck.pop_back();
	int u=del.back();
	del.pop_back();
	if(u)
	{
		c[p[u]]-=c[u];
		p[u]=u;
		w[u]=0;
	}
}
int m;
bool sol[N];
void Solve(int c, int ss, int se)
{
	//if(se<=m) printf("%i %i\n",ss,se);
	int i;
	for(i=0;i<edges[c].size();i++) AddEdge(edges[c][i].first,edges[c][i].second);
	if(ss==se)
	{
		if(m>=ss)
		{
			//printf("%i\n",ss);
			//for(i=1;i<=3;i++) printf("p:%i w:%i\n",p[i],w[i]);
			sol[ss]=!bad;
		}
		for(i=0;i<edges[c].size();i++) DelEdge();
		return;
	}
	int mid=ss+se>>1;
	Solve(ls[c],ss,mid);
	Solve(rs[c],mid+1,se);
	for(i=0;i<edges[c].size();i++) DelEdge();
}
map<pair<int,int> ,int> was;
map<pair<int,int> ,int>::iterator it;
int main()
{
	Init();
	int n,u,v,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		if(u>v) u^=v,v^=u,u^=v;
		if(was[mp(u,v)]) AddEdge(root,1,N,was[mp(u,v)],i-1,u,v),was[mp(u,v)]=0;
		else was[mp(u,v)]=i;
	}
	for(it=was.begin();it!=was.end();it++)
	{
		if(it->second) AddEdge(root,1,N,it->second,m,it->first.first,it->first.second);
	}
	Solve(root,1,N);
	for(i=1;i<=m;i++)
	{
		if(sol[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}