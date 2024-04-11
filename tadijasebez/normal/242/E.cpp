#include <stdio.h>
#define ll long long
struct Node
{
	int a[21];
	inline ll calc()
	{
		ll ret=0;
		int i;
		for(i=0;i<21;i++) ret+=(ll)a[i]*(1<<i);
		return ret;
	}
	Node(){}
	Node(int x)
	{
		int i;
		for(i=0;i<21;i++)
		{
			if((x>>i)&1) a[i]=1;
			else a[i]=0;
		}
	}
	inline Node operator + (const Node &b) const
	{
		Node c;
		int i;
		for(i=0;i<21;i++) c.a[i]=a[i]+b.a[i];
		return c;
	}
};
void Flip(Node &n, int sz, int x)
{
	int i;
	for(i=0;i<21;i++) if((x>>i)&1) n.a[i]=sz-n.a[i];
}
const int N=100050;
const int M=N*2;
Node x[M];
int Lazy[M],ls[M],rs[M],clock,root,A[N];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=Node(A[ss]);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	if(Lazy[c]>0)
	{
		Flip(x[c],se-ss+1,Lazy[c]);
		if(ss!=se)
		{
			Lazy[ls[c]]^=Lazy[c];
			Lazy[rs[c]]^=Lazy[c];
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		Flip(x[c],se-ss+1,val);
		if(ss!=se)
		{
			Lazy[ls[c]]^=val;
			Lazy[rs[c]]^=val;
		}
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=x[ls[c]]+x[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(Lazy[c]>0)
	{
		Flip(x[c],se-ss+1,Lazy[c]);
		if(ss!=se)
		{
			Lazy[ls[c]]^=Lazy[c];
			Lazy[rs[c]]^=Lazy[c];
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return Node(0);
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,i,l,r,k,q,t;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1) printf("%lld\n",Get(root,1,n,l,r).calc());
		else scanf("%i",&k),Set(root,1,n,l,r,k);
	}
	return 0;
}