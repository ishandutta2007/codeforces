#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
struct Node
{
	vector<int> a;
	Node(){}
	Node(vector<int> b)
	{
		a=b;
	}
	inline Node operator + (const Node &b) const
	{
		Node c;
		int i=0,j=0,n=a.size(),m=b.a.size();
		while((i<n || j<m) && (c.a.size()<10))
		{
			if(i<n && j<m && a[i]==b.a[j]) c.a.pb(a[i++]),j++;
			if(i<n && (j>=m || a[i]<b.a[j])) c.a.pb(a[i++]);
			if(j<m && (i>=n || b.a[j]<a[i])) c.a.pb(b.a[j++]);
		}
		while(c.a.size()>10) c.a.pop_back();
		return c;
	}
};
const int N=100050;
const int M=2*N;
Node x[M];
int ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qi, Node val)
{
	if(!c) c=++clock,x[c]=val;
	else x[c]=x[c]+val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
bool NotOnSegment(int ss, int se, int qs, int qe){ return (ss>qe || qs>se);}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return Node();
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	if(NotOnSegment(ss,mid,qs,qe)) return Get(rs[c],mid+1,se,qs,qe);
	if(NotOnSegment(mid+1,se,qs,qe)) return Get(ls[c],ss,mid,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> E[N],Head,Euler,D;
int sz[N],time,id[N],Chain[N],b[N],par[N];
void DFS(int c, int p, int d)
{
	par[c]=p;
	b[c]=Euler.size();
	sz[c]=1;
	Euler.pb(c);
	D.pb(d);
	int i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p)
		{
			DFS(v,c,d+1);
			sz[c]+=sz[v];
			Euler.pb(c);
			D.pb(d);
		}
	}
}
int logs[N<<1],Table[N<<1][20];
void Preprocess()
{
	int k=0,i;
	for(i=0;i<N<<1;i++)
	{
		if(i==1<<(k+1)) k++;
		logs[i]=k;
	}
}
void BuildSparseTable()
{
	Preprocess();
	int n=Euler.size(),i,j;
	for(i=0;i<n;i++) Table[i][0]=i;
	for(j=1;j<20;j++)
	{
		for(i=0;i<n-(1<<j)+1;i++)
		{
			if(D[Table[i][j-1]]<D[Table[i+(1<<(j-1))][j-1]])
				Table[i][j]=Table[i][j-1];
			else Table[i][j]=Table[i+(1<<(j-1))][j-1];
		}
	}
}
void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
int LCA(int u, int v)
{
	if(b[u]>b[v]) swap(u,v);
	u=b[u];
	v=b[v]+1;
	int k=logs[v-u];
	if(D[Table[u][k]]<D[Table[v-(1<<k)][k]])
		return Euler[Table[u][k]];
	else return Euler[Table[v-(1<<k)][k]];
}
int ChainEnd[N],ChainBegin[N];
void HLD(int c, int p)
{
	if(Chain[c]==-1)
	{
		Chain[c]=Head.size();
		Head.push_back(c);
	}
	id[c]=++time;
	if(!ChainBegin[Chain[c]]) ChainBegin[Chain[c]]=id[c];
	ChainEnd[Chain[c]]=id[c];
	int ch=0,i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p && (!ch || sz[ch]<sz[v])) ch=v;
	}
	if(ch)
	{
		Chain[ch]=Chain[c];
		HLD(ch,c);
		for(i=0;i<E[c].size();i++)
		{
			int v=E[c][i];
			if(v!=p && v!=ch) HLD(v,c);
		}
	}
}
vector<int> people[N];
void HLD(int n)
{
	int i;
	for(i=1;i<=n;i++) Chain[i]=-1;
	DFS(1,0,0);
	BuildSparseTable();
	HLD(1,0);
	for(i=1;i<=n;i++) Set(root[Chain[i]],ChainBegin[Chain[i]],ChainEnd[Chain[i]],id[i],Node(people[i]));
}
void Query(int u, int v, int a, int n)
{
	int lca=LCA(u,v);
	Node tmp;
	while(Chain[u]!=Chain[lca])
	{
		tmp=tmp+Get(root[Chain[u]],ChainBegin[Chain[u]],ChainEnd[Chain[u]],id[Head[Chain[u]]],id[u]);
		u=par[Head[Chain[u]]];
	}
	tmp=tmp+Get(root[Chain[u]],ChainBegin[Chain[u]],ChainEnd[Chain[u]],id[lca],id[u]);
	while(Chain[v]!=Chain[lca])
	{
		tmp=tmp+Get(root[Chain[v]],ChainBegin[Chain[v]],ChainEnd[Chain[v]],id[Head[Chain[v]]],id[v]);
		v=par[Head[Chain[v]]];
	}
	tmp=tmp+Get(root[Chain[v]],ChainBegin[Chain[v]],ChainEnd[Chain[v]],id[lca],id[v]);
	int i;
	if(a>tmp.a.size())
	{
		printf("%i ",tmp.a.size());
		for(i=0;i<tmp.a.size();i++) printf("%i ",tmp.a[i]);
		printf("\n");
	}
	else
	{
		printf("%i ",a);
		for(i=0;i<a;i++) printf("%i ",tmp.a[i]);
		printf("\n");
	}
}
int main()
{
	int n,m,q,i,u,v,a;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=m;i++)
	{
		scanf("%i",&u);
		if(people[u].size()<10) people[u].pb(i);
	}
	HLD(n);
	while(q--) scanf("%i %i %i",&u,&v,&a),Query(u,v,a,n);
	return 0;
}