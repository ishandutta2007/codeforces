#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int h[maxn+5],d[maxn+5];

struct node
{
	ll mx,lm,rm,s;
};

node operator +(node a,node b)
{
	node res;
	res.mx=max(max(a.mx,b.mx),a.lm+b.rm);
	res.lm=max(b.lm,a.lm+b.s);
	res.rm=max(a.rm,a.s+b.rm);
	res.s=a.s+b.s;
	return res;
}

struct segt
{
	#define ls i*2
	#define rs i*2+1
	node a[maxn*4+5];
	void pu(int i)
	{
		a[i]=a[ls]+a[rs];
	}
	void build(int i,int l,int r)
	{
		if(l==r)
		{
			a[i].mx=-inf;
			a[i].lm=1ll*h[l]+d[l];
			a[i].rm=h[l];
			a[i].s=d[l];
			//printf("%d, %d: %lld %lld %lld %lld\n",l,r,a[i].mx,a[i].lm,a[i].rm,a[i].s);
		}
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pu(i);
			//printf("%d, %d: %lld %lld %lld %lld\n",l,r,a[i].mx,a[i].lm,a[i].rm,a[i].s);
		}
	}
	node ask(int i,int l,int r,int ql,int qr)
	{
		//printf("??? %d, %d: %lld %lld %lld %lld\n",l,r,a[i].mx,a[i].lm,a[i].rm,a[i].s);
		if(ql<=l && r<=qr) 
		{
			return a[i];
		}
		if(r<ql || qr<l) return (node){-inf,-inf,-inf,0};
		int mid=(l+r)>>1;
		return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
	}
}t;

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&d[i]),d[i+n]=d[i];
	rep(i,1,n) scanf("%d",&h[i]),h[i]*=2,h[i+n]=h[i];
	t.build(1,1,n*2);
	while(m--)
	{
		int a,b; scanf("%d%d",&a,&b);
		if(a<=b) printf("%lld\n",t.ask(1,1,n*2,b+1,a+n-1).mx);
		else printf("%lld\n",t.ask(1,1,n*2,b+1,a-1).mx);
	}
	return 0;
}