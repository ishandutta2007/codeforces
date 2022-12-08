#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,i,x,t,l,r;
struct mjj{int a[4];}a,b,V[400010],cov[400010];
mjj mult(mjj a,mjj b)
{
	mjj c;
	c.a[0]=(1ll*a.a[0]*b.a[0]+1ll*a.a[1]*b.a[2])%mod;
	c.a[1]=(1ll*a.a[1]*b.a[3]+1ll*a.a[0]*b.a[1])%mod;
	c.a[2]=(1ll*a.a[2]*b.a[0]+1ll*a.a[3]*b.a[2])%mod;
	c.a[3]=(1ll*a.a[3]*b.a[3]+1ll*a.a[2]*b.a[1])%mod;
	return c;
}
mjj count(mjj a,int b)
{
	mjj c;
	c.a[0]=1;c.a[1]=0;
	c.a[2]=0;c.a[3]=1;
	for(;b;b>>=1,a=mult(a,a))
		if(b&1)c=mult(c,a);
	return c;
}
void build0(int l,int r,int cur)
{
	V[cur].a[0]=r-l+1;
	V[cur].a[1]=V[cur].a[2]=V[cur].a[3]=0;
	cov[cur].a[0]=cov[cur].a[3]=1;
	cov[cur].a[1]=cov[cur].a[2]=0;
	if(l==r)return;
	int mid=l+r>>1;
	build0(l,mid,cur<<1);
	build0(mid+1,r,cur<<1|1);
}
void pushdown(int cur)
{
	V[cur<<1]=mult(V[cur<<1],cov[cur]);
	V[cur<<1|1]=mult(V[cur<<1|1],cov[cur]);
	cov[cur<<1]=mult(cov[cur<<1],cov[cur]);
	cov[cur<<1|1]=mult(cov[cur<<1|1],cov[cur]);
	cov[cur].a[0]=cov[cur].a[3]=1;
	cov[cur].a[1]=cov[cur].a[2]=0;
}
void update(int cur)
{
	for(int i=0;i<4;i++)
		V[cur].a[i]=(V[cur<<1].a[i]+V[cur<<1|1].a[i])%mod;
}
void add(int l,int r,int L,int R,int cur,mjj a)
{
	if(L<=l&&R>=r)
	{
		V[cur]=mult(V[cur],a);
		cov[cur]=mult(cov[cur],a);
		return;
	}
	pushdown(cur);
	int mid=l+r>>1;
	if(L<=mid)add(l,mid,L,R,cur<<1,a);
	if(R>mid)add(mid+1,r,L,R,cur<<1|1,a);
	update(cur);
}
int ask(int l,int r,int L,int R,int cur)
{
	if(L<=l&&R>=r)return V[cur].a[0];
	pushdown(cur);
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans+=ask(l,mid,L,R,cur<<1);
	if(R>mid)ans+=ask(mid+1,r,L,R,cur<<1|1);
	return ans%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	a.a[0]=1;a.a[1]=1;a.a[2]=1;
	build0(1,n,1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(1,n,i,i,1,count(a,x-1));
	}
	while(m--)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==2)printf("%d\n",ask(1,n,l,r,1));
		else scanf("%d",&x),add(1,n,l,r,1,count(a,x));
	}
}