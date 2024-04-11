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

const int N=201000;
int n,q;

namespace lazy {
	ll fg[4*N],s[4*N];
	void build(int p,int l,int r) {
		s[p]=r-l+1; fg[p]=0;
		if (l!=r) {
			int md=(l+r)>>1;
			build(p+p,l,md);
			build(p+p+1,md+1,r);
		}
	}
	void setf(int p,ll v,int l,int r) {
		fg[p]+=v; 
		s[p]+=v*(r-l+1);
	}
	void push(int p,int l,int r) {
		if (fg[p]) {
			int md=(l+r)>>1;
			setf(p+p,fg[p],l,md);
			setf(p+p+1,fg[p],md+1,r);
			fg[p]=0;
		}
	}
	void modify(int p,int l,int r,int tl,int tr,ll v) {
		if (l>r||l>tr||r<tl) return;
		if (tl<=l&&r<=tr) {
			setf(p,v,l,r);
		} else {
			push(p,l,r);
			int md=(l+r)>>1;
			modify(p+p,l,md,tl,tr,v);
			modify(p+p+1,md+1,r,tl,tr,v);
			s[p]=s[p+p]+s[p+p+1];
		}
	}
	ll query(int p,int l,int r,int tl,int tr) {
		if (l>r||l>tr||r<tl) return 0;
		if (tl<=l&&r<=tr) return s[p];
		push(p,l,r);
		int md=(l+r)>>1;
		return query(p+p,l,md,tl,tr)+query(p+p+1,md+1,r,tl,tr);
	}
} 

struct node {
	int mx1,mx2,cc,fg;
}nd[4*N];
void upd(int p) {
	if (nd[p+p].mx1==nd[p+p+1].mx1) {
		nd[p].mx1=nd[p+p].mx1;
		nd[p].mx2=max(nd[p+p].mx2,nd[p+p+1].mx2);
		nd[p].cc=nd[p+p].cc+nd[p+p+1].cc;
	} else {
		if (nd[p+p].mx1>nd[p+p+1].mx1) {
			nd[p].mx1=nd[p+p].mx1;
			nd[p].mx2=max(nd[p+p].mx2,nd[p+p+1].mx1);
			nd[p].cc=nd[p+p].cc;
		} else {
			nd[p].mx1=nd[p+p+1].mx1;
			nd[p].mx2=max(nd[p+p].mx1,nd[p+p+1].mx2);
			nd[p].cc=nd[p+p+1].cc;
		}
	}
}
void setf(int p,int v) {
	if (nd[p].mx1<=v) return;
	nd[p].mx1=v; 
	nd[p].fg=v;
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
void build(int p,int l,int r) {
	nd[p].mx1=r;
	nd[p].mx2=r-1;
	nd[p].cc=1;
	nd[p].fg=0;
	if (l==r) {
		nd[p].mx2=0;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}
void modify(int p,int l,int r,int tl,int x) {
	if (l==r) {
		lazy::modify(1,1,n,l,x,1);
		lazy::modify(1,1,n,l,nd[p].mx1,-1);
		nd[p].mx1=x;
		nd[p].mx2=0;
		nd[p].cc=1;
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tl<=md) modify(p+p,l,md,tl,x);
		else modify(p+p+1,md+1,r,tl,x);
		upd(p);
	}
}
void update(int p,int l,int r,int tl,int tr,int x) {
	if (l>r||tl>tr||l>tr||r<tl||nd[p].mx1<=x) return;
	if (tl<=l&&r<=tr&&nd[p].mx2<x) {
		lazy::modify(1,1,n,x+1,nd[p].mx1,-nd[p].cc);
		setf(p,x);
	} else {
		push(p);
		int md=(l+r)>>1;
		update(p+p,l,md,tl,tr,x);
		update(p+p+1,md+1,r,tl,tr,x);
		upd(p);	
	}
}

int main() {
	scanf("%d%d",&n,&q);
	lazy::build(1,1,n);
	build(1,1,n);
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int c,g;
			scanf("%d%d",&c,&g);
			modify(1,1,n,c,g);
			update(1,1,n,1,c-1,c-1);
		} else {
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",lazy::query(1,1,n,l,r));
		}
	}
}