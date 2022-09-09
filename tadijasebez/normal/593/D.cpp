#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
const ll inf=(ll)1000000000*1000000000;
struct Node
{
	ll A,B;
	Node(){ A=1,B=0;}
	Node(ll a){ A=a,B=(A!=1);}
	Node operator + (Node b) const
	{
		Node c;
		if((inf/b.A)/A==0) c.A=inf;
		else c.A=b.A*A;
		c.B=b.B+B;
		return c;
	}
} x[M];
int ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, Node val)
{
	if(!c) c=++clock;
	if(ss==se){ x[c]=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	x[c]=x[ls[c]]+x[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return Node();
	if(ss>qe || qs>se) return Node();
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector< pair<int,int> > E[N];
vector<int> Euler,D;
int sz[N],Index[N],FAI[N],logs[M],Table[M][20],par[N],Edge[N];
void Preprocess()
{
	int j=1,i;
	for(i=0;i<M;i++)
	{
		if(i==1<<j) j++;
		logs[i]=j-1;
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
void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
int LCA(int u, int v)
{
	if(FAI[u]>FAI[v]) Swap(u,v);
	u=FAI[u];
	v=FAI[v];
	int k=logs[v-u+1];
	if(D[Table[u][k]]<D[Table[v-(1<<k)+1][k]])
		return Euler[Table[u][k]];
	else return Euler[Table[v-(1<<k)+1][k]];
}
void DFS(int c, int p, int e, int d)
{
	FAI[c]=Euler.size();
	Euler.push_back(c);
	D.push_back(d);
	par[c]=p;
	Edge[e]=c;
	sz[c]=1;
	for(int i=0;i<E[c].size();i++)
	{
		int v=E[c][i].first;
		int ed=E[c][i].second;
		if(v!=p)
		{
			DFS(v,c,ed,d+1);
			sz[c]+=sz[v];
			Euler.push_back(c);
			D.push_back(d);
		}
	}
}
vector<int> Head;
int Chain[N],time;
void HLD(int c, int p)
{
	if(!Chain[c])
	{
		Chain[c]=Head.size();
		Head.push_back(c);
	}
	int HC=0,i;
	Index[c]=++time;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i].first;
		if(v!=p && sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		Chain[HC]=Chain[c];
		HLD(HC,c);
		for(i=0;i<E[c].size();i++)
		{
			int v=E[c][i].first;
			if(v!=p && v!=HC) HLD(v,c);
		}
	}
}
ll val[N];
void HLD(int n)
{
	DFS(1,0,0,1);
	BuildSparseTable();
	Head.push_back(0);
	HLD(1,0);
	for(int i=1;i<n;i++) Set(root,1,N,Index[Edge[i]],Node(val[i]));
}
void Change(int u, ll X)
{
	Set(root,1,N,Index[Edge[u]],Node(X));
}
ll Query(int u, int v, ll y)
{
	int lca=LCA(u,v);
	Node tmp=Node();
	while(Chain[u]!=Chain[lca])
	{
		tmp=tmp+Get(root,1,N,Index[Head[Chain[u]]],Index[u]);
		u=par[Head[Chain[u]]];
	}
	tmp=tmp+Get(root,1,N,Index[lca]+1,Index[u]);
	while(Chain[v]!=Chain[lca])
	{
		tmp=tmp+Get(root,1,N,Index[Head[Chain[v]]],Index[v]);
		v=par[Head[Chain[v]]];
	}
	tmp=tmp+Get(root,1,N,Index[lca]+1,Index[v]);
	if(tmp.B>1 && y==tmp.A) return 0;
	return y/tmp.A;
}
int main()
{
	int n,q,u,v,i,t;
	ll y;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%i %i %lld",&u,&v,&val[i]);
		E[u].push_back(make_pair(v,i));
		E[v].push_back(make_pair(u,i));
	}
	HLD(n);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i %lld",&u,&v,&y),printf("%lld\n",Query(u,v,y));
		else scanf("%i %lld",&u,&y),Change(u,y);
	}
	return 0;
}