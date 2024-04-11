#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000009
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

struct mat
{
	int a[2][2];
	mat(){memset(a,0,sizeof a);}
	mat operator +(const mat &A) const
	{
		mat res;
		rep(i,0,1) rep(j,0,1) res.a[i][j]=(a[i][j]+A.a[i][j])%mod;
		return res;
	}
	mat operator *(const mat &A) const
	{
		mat res;
		rep(i,0,1) rep(k,0,1) rep(j,0,1) res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*A.a[k][j])%mod;
		return res;
	}
};
mat A[maxn+5],iA[maxn+5],pre[maxn+5];

pii operator +(pii a,pii b)
{
	return mp((a.FI+b.FI)%mod,(a.SE+b.SE)%mod);
}
pii operator *(pii a,mat b)
{
	return mp((1ll*a.FI*b.a[0][0]+1ll*a.SE*b.a[1][0])%mod,(1ll*a.FI*b.a[0][1]+1ll*a.SE*b.a[1][1])%mod);
}

struct segt
{
	#define ls i*2
	#define rs i*2+1
	int s[maxn*4+5];
	pii lz[maxn*4+5];
	void pu(int i) {s[i]=(s[ls]+s[rs])%mod;}
	void push(int i,int l,int r,pii x)
	{
		s[i]=(s[i]+(x*pre[r-l]).FI)%mod;
		lz[i]=lz[i]+x;
	}
	void pd(int i,int l,int r)
	{
		int mid=(l+r)>>1;
		push(ls,l,mid,lz[i]);
		push(rs,mid+1,r,lz[i]*A[mid-l+1]);
		lz[i]=mp(0,0);
	}
	void build(int i,int l,int r)
	{
		if(l==r)
		{
			s[i]=a[l];
		}
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pu(i);
		}
	}
	void add(int i,int l,int r,int ql,int qr,pii x)
	{
		if(ql<=l && r<=qr)
		{
			push(i,l,r,x);
			return;
		}
		if(r<ql || qr<l) return;
		pd(i,l,r);
		int mid=(l+r)>>1;
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x*A[mid+1-l]);
		pu(i);
	}
	int ask(int i,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return s[i];
		if(r<ql || qr<l) return 0;
		pd(i,l,r);
		int mid=(l+r)>>1;
		return (ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr))%mod;
	}
}t;

int main()
{
	pre[0].a[0][0]=pre[0].a[1][1]=1; iA[0]=A[0]=pre[0];
	A[1].a[0][0]=A[1].a[0][1]=A[1].a[1][0]=1;
	iA[1].a[1][0]=iA[1].a[0][1]=1; iA[1].a[1][1]=mod-1;
	rep(i,2,maxn) A[i]=A[i-1]*A[1];
	rep(i,2,maxn) iA[i]=iA[i-1]*iA[1];
	rep(i,1,maxn) pre[i]=pre[i-1]+A[i];

	int n,Q; scanf("%d%d",&n,&Q);
	rep(i,1,n) scanf("%d",&a[i]);
	t.build(1,1,n);
	rep(i,1,Q)
	{
		int op,l,r; scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			pii x=mp(1,0)*iA[l-1];
			t.add(1,1,n,l,r,x);
		}
		else printf("%d\n",t.ask(1,1,n,l,r));
	}
	return 0;
}