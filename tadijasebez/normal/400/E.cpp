#include <stdio.h>
#define ll long long
ll fir(int x){ return (ll)x*(x+1)/2;}
const int N=100050;
const int M=20*2*N;
struct Node
{
	int l,r,sz;
	ll sum;
	Node(){ l=r=sz=sum=0;}
	Node operator + (Node b) const
	{
		Node c;
		c.sz=sz+b.sz;
		c.sum=sum+b.sum-fir(r)-fir(b.l)+fir(r+b.l);
		c.l=l;
		if(l==sz) c.l+=b.l;
		c.r=b.r;
		if(b.r==b.sz) c.r+=r;
		return c;
	}
} node[M];
int a[N],ls[M],rs[M],tsz,root[20];
void Build(int &c, int ss, int se, int k)
{
	c=++tsz;
	if(ss==se)
	{
		node[c].sz=1;
		node[c].l=node[c].r=node[c].sum=(a[ss]>>k)&1;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,k);
	Build(rs[c],mid+1,se,k);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int val)
{
	if(ss==se){ node[c].l=node[c].r=node[c].sum=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	node[c]=node[ls[c]]+node[rs[c]];
}
int main()
{
	int n,q,i,p,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=0;i<18;i++) Build(root[i],1,n,i);
	while(q--)
	{
		scanf("%i %i",&p,&x);
		for(i=0;i<18;i++) Set(root[i],1,n,p,(x>>i)&1);
		ll ans=0;
		for(i=0;i<18;i++) ans+=node[root[i]].sum*(1<<i);
		printf("%lld\n",ans);
	}
	return 0;
}