#include <stdio.h>
#define ll long long
const int N=300050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
struct Node
{
	int l,r,L,R,sol,sz;
	ll lzy,fir,las;
	Node(){ l=r=L=R=sol=sz=1;lzy=0;}
};
Node operator + (Node ls, Node rs)
{
	Node c;
	c.sz=ls.sz+rs.sz;
	c.fir=ls.fir;
	c.las=rs.las;
	c.sol=max(ls.sol,rs.sol);
	c.l=ls.l;
	if(ls.l==ls.sz && ls.las>rs.fir) c.l+=rs.l;
	c.r=rs.r;
	if(rs.r==rs.sz && rs.fir>ls.las) c.r+=ls.r;
	c.L=ls.L;
	c.R=rs.R;
	if(ls.las>rs.fir)
	{
		if(ls.R==ls.sz) c.L=max(c.L,ls.R+rs.l);
		c.sol=max(c.sol,ls.R+rs.l);
		if(rs.l==rs.sz) c.R=max(c.R,ls.R+rs.l);
	}
	if(ls.las<rs.fir)
	{
		if(ls.r==ls.sz) c.L=max(c.L,ls.r+rs.L);
		c.sol=max(c.sol,ls.r+rs.L);
		if(rs.L==rs.sz) c.R=max(c.R,ls.r+rs.L);
	}
	c.L=max(c.L,c.l);
	c.R=max(c.R,c.r);
	c.sol=max(c.sol,max(c.L,c.R));
	return c;
}
Node node[M];
int ls[M],rs[M],a[M],root,tsz;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c].fir=node[c].las=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Push(int c, int ss, int se)
{
	if(node[c].lzy)
	{
		node[c].fir+=node[c].lzy;
		node[c].las+=node[c].lzy;
		if(ss!=se)
		{
			node[ls[c]].lzy+=node[c].lzy;
			node[rs[c]].lzy+=node[c].lzy;
		}
		node[c].lzy=0;
	}
}
void Add(int c, int ss, int se, int qs, int qe, int k)
{
	Push(c,ss,se);
	if(qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ node[c].lzy+=k;Push(c,ss,se);return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,k);
	Add(rs[c],mid+1,se,qs,qe,k);
	node[c]=node[ls[c]]+node[rs[c]];
}
int main()
{
	int n,i,q,l,r,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		Add(root,1,n,l,r,k);
		printf("%i\n",node[root].sol);
	}
	return 0;
}