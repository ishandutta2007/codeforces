#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,q,a[N];

struct Matrix {
	ll a[2][2];
	Matrix() {
		rep(i,0,2) rep(j,0,2) 
			a[i][j]=0;
	}
	Matrix operator * (Matrix b) {
		Matrix res;
		rep(i,0,2) rep(j,0,2) rep(k,0,2) 
			res.a[i][k]=(res.a[i][k]+a[i][j]*b.a[j][k])%mod;
		return res;
	}
	Matrix operator + (Matrix b) {
		Matrix res;
		rep(i,0,2) rep(j,0,2) 
			res.a[i][j]=(a[i][j]+b.a[i][j])%mod;
		return res;
	}
}F;

Matrix exp(Matrix a,int b) {
	Matrix res;
	res.a[0][0]=res.a[1][1]=1;
	while (b) {
		if (b&1) res=res*a;
		b>>=1; a=a*a;
	}
	return res;
}

struct node {
	Matrix f,fg;
}nd[4*N];
void upd(int p) {
	nd[p].f=(nd[p+p].f+nd[p+p+1].f)*nd[p].fg;
}
void build(int p,int l,int r) {
	nd[p].fg.a[0][0]=nd[p].fg.a[1][1]=1;
	if (l==r) {
		nd[p].f=exp(F,a[l]);
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void modify(int p,int l,int r,int tl,int tr,int x) {
	if (tl==l&&r==tr) {
		nd[p].fg=nd[p].fg*exp(F,x);
		nd[p].f=nd[p].f*exp(F,x);
	} else {
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,x);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,x);
		else modify(p+p,l,md,tl,md,x),modify(p+p+1,md+1,r,md+1,tr,x);
		upd(p);
	}
}
Matrix query(int p,int l,int r,int tl,int tr) {
	if (tl>tr) return Matrix();
	if (tl==l&&tr==r) return nd[p].f;
	int md=l+r>>1;
	if (tr<=md) return query(p+p,l,md,tl,tr)*nd[p].fg;
	else if (tl>md) return query(p+p+1,md+1,r,tl,tr)*nd[p].fg;
	else return (query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr))*nd[p].fg;
}

int main() {
	scanf("%d%d",&n,&q);
	F.a[0][1]=F.a[1][0]=F.a[1][1]=1;
	rep(i,1,n+1) scanf("%d",a+i);
	build(1,1,n);
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			modify(1,1,n,l,r,x);
		} else {
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,1,n,l,r).a[1][0]);
		}
	}	
}