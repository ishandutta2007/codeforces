#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=1000050;
const int M=2*N;
const int H=1050;
struct DSU
{
	int p[H],w[H];
	vector<int> id;
	DSU(){ for(int i=0;i<H;i++) p[i]=i,w[i]=0;}
	void init(){ for(int i=0;i<id.size();i++) p[id[i]]=id[i],w[id[i]]=0;id.clear();}
	int last;
	int Find(int x)
	{
		if(p[x]==x){ last=0;return x;}
		int y=Find(p[x]);
		w[x]^=last;
		last=w[x];
		return p[x]=y;
	}
	int Get(int x)
	{
		return w[x];
		//if(p[x]==x) return 0;
		//return w[x]^Get(p[x]);
	}
	int Union(int x, int y)
	{
		Find(x);Find(y);
		//printf("x:%i y:%i w[x]:%i w[y]:%i\n",x,y,Get(x),Get(y));
		if(Find(x)==Find(y))
		{
			if(Get(x)==Get(y)) return -1;
			return 0;
		}
		id.pb(Find(x));
		w[Find(x)]^=Get(x)^Get(y)^1;
		p[Find(x)]=Find(y);
		return 1;
	}
} Tree;
struct Edge
{
	int u,v,w;
	Edge(){}
	Edge(int a, int b, int c){ u=a,v=b,w=c;}
	bool operator < (Edge b) const { return w>b.w;}
};
vector<Edge> Merge(vector<Edge> &a, vector<Edge> &b)
{
	vector<Edge> c;
	int i=0,j=0;
	while(i<a.size() || j<b.size())
	{
		if(i==a.size()) c.pb(b[j++]);
		else if(j==b.size()) c.pb(a[i++]);
		else if(a[i]<b[j]) c.pb(a[i++]);
		else c.pb(b[j++]);
	}
	return c;
}
struct Node
{
	vector<Edge> all;
	int sol;
	Node(){}
};
Node operator + (Node a, Node b)
{
	Node c;c.sol=-1;
	c.all=Merge(a.all,b.all);
	int i;
	Tree.init();
	vector<Edge> tmp;
	for(i=0;i<c.all.size();i++)
	{
		int val=Tree.Union(c.all[i].u,c.all[i].v);
		if(val==0) continue;
		tmp.pb(c.all[i]);
		if(val==-1)
		{
			c.sol=c.all[i].w;
			//printf("!!!\n");
			break;
		}
	}
	c.all=tmp;
	return c;
}
int ls[M],rs[M],tsz,root;
int A[N],B[N],C[N];
Node node[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		node[c].all.pb(Edge(A[ss],B[ss],C[ss]));
		node[c].sol=-1;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
	//printf("(%i %i):\n",ss,se);
	//for(int i=0;i<node[c].all.size();i++) printf("%i %i %i\n",node[c].all[i].u,node[c].all[i].v,node[c].all[i].w);
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,q,m,i,l,r;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=m;i++) scanf("%i %i %i",&A[i],&B[i],&C[i]);
	Build(root,1,m);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		Node tmp=Get(root,1,m,l,r);
		printf("%i\n",tmp.sol);
		//for(i=0;i<tmp.all.size();i++) printf("%i %i %i\n",tmp.all[i].u,tmp.all[i].v,tmp.all[i].w);
	}
	return 0;
}