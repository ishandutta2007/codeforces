#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
const int L=17;
vector<int> E[N];
int par[N][L],dep[N];
void DFS(int u)
{
	dep[u]=dep[par[u][0]]+1;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u]) DFS(v);
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
const int M=2*N;
int ls[M],rs[M],tsz,root,id[M],mx[M],lca[N];
bool comp(int i, int j){ return dep[i]<dep[j];}
void Pull(int c)
{
	if(comp(mx[ls[c]],mx[rs[c]])) mx[c]=mx[ls[c]],id[c]=id[ls[c]];
	else mx[c]=mx[rs[c]],id[c]=id[rs[c]];
}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ id[c]=ss;mx[c]=lca[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	Pull(c);
}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
    if(qs<=ss && qe>=se) return mp(mx[c],id[c]);
    int mid=ss+se>>1;
    if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
    if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
    pair<int,int> l=Get(ls[c],ss,mid,qs,qe);
    pair<int,int> r=Get(rs[c],mid+1,se,qs,qe);
    if(comp(l.first,r.first)) return l;
    else return r;
}
int main()
{
	int n,q,i,l,r;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i",&par[i][0]),E[par[i][0]].pb(i);
	DFS(1);
	for(i=1;i<n;i++) lca[i]=LCA(i,i+1);
	Build(root,1,n-1);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&l,&r);
		pair<int,int> fir=Get(root,1,n-1,l,r-1);
		int ans1=fir.second+1,ans2=fir.second;
		//First Case
		if(fir.second!=l)
		{
			if(comp(LCA(fir.second-1,fir.second+1),ans1)) ans1=LCA(fir.second-1,fir.second+1);
		}
		if(fir.second-2>=l)
		{
			pair<int,int> sec=Get(root,1,n-1,l,fir.second-2);
			if(comp(sec.first,ans1)) ans1=sec.first;
		}
		if(fir.second+1<=r-1)
		{
			pair<int,int> sec=Get(root,1,n-1,fir.second+1,r-1);
			if(comp(sec.first,ans1)) ans1=sec.first;
		}
		//Second Case
		fir.second++;
		if(fir.second!=r)
		{
			if(comp(LCA(fir.second-1,fir.second+1),ans2)) ans2=LCA(fir.second-1,fir.second+1);
		}
		if(fir.second-2>=l)
		{
			pair<int,int> sec=Get(root,1,n-1,l,fir.second-2);
			if(comp(sec.first,ans2)) ans2=sec.first;
		}
		if(fir.second+1<=r-1)
		{
			pair<int,int> sec=Get(root,1,n-1,fir.second+1,r-1);
			if(comp(sec.first,ans2)) ans2=sec.first;
		}
		if(comp(ans1,ans2))
		{
			printf("%i %i\n",fir.second,dep[ans2]-1);
		}
		else
		{
			printf("%i %i\n",fir.second-1,dep[ans1]-1);
		}
	}
	return 0;
}