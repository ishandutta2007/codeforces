#include <stdio.h>
const int N=100050;
const int M=2*N;
const int H=60;
struct Node
{
	int dp[H],sol;
	Node(){ sol=0;for(int i=0;i<H;i++) dp[i]=0;}
	Node operator + (Node b) const
	{
		Node c;
		c.sol=sol+b.dp[sol%H];
		for(int i=0;i<H;i++) c.dp[i]=dp[i]+b.dp[(i+dp[i])%H];
		return c;
	}
} node[M];
int ls[M],rs[M],tsz,root,a[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		node[c].sol=2;
		int i;
		for(i=0;i<H;i++) node[c].dp[i]=1;
		for(i=0;i<H;i+=a[ss]) node[c].dp[i]=2;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int x)
{
	if(ss==se)
	{
		node[c].sol=2;
		int i;
		for(i=0;i<H;i++) node[c].dp[i]=1;
		for(i=0;i<H;i+=x) node[c].dp[i]=2;
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	node[c]=node[ls[c]]+node[rs[c]];
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
	int n,i,q,l,r,x,p;char t;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='A')
		{
			scanf("%i %i",&l,&r);
			Node res=Get(root,1,n,l,r-1);
			printf("%i\n",res.sol);
		}
		else
		{
			scanf("%i %i",&p,&x);
			Set(root,1,n,p,x);
		}
	}
	return 0;
}