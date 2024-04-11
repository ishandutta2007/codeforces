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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
struct node {
	ll l,r,lzy;
	int ld,lu,rd,ru,sz,mx;
}nd[4*N];
int n,m,a[N];
void add(int p,ll d) {
	nd[p].lzy+=d; nd[p].l+=d; nd[p].r+=d;
}
void push(int p) {
	if (nd[p].lzy) {
		add(p+p,nd[p].lzy);
		add(p+p+1,nd[p].lzy);
		nd[p].lzy=0;
	}
}
void upd(int p) {
	// I'm enough of this problem
	// copy-pasted
	bool lg=nd[p+p].r>nd[p+p+1].l,rg=nd[p+p].r<nd[p+p+1].l;
	if (nd[p+p].ld==nd[p+p].sz&&lg)
		nd[p].ld=nd[p+p].sz+nd[p+p+1].ld;
	else nd[p].ld=nd[p+p].ld;
	if (nd[p+p+1].rd==nd[p+p+1].sz&&rg)
		nd[p].rd=nd[p+p+1].sz+nd[p+p].rd;
	else nd[p].rd=nd[p+p+1].rd;
	if (nd[p+p].lu==nd[p+p].sz) {
		if (nd[p+p].rd==nd[p+p].sz) {
			if (rg) nd[p].lu=nd[p+p].sz+nd[p+p+1].lu;
			if (lg) nd[p].lu=nd[p+p].sz+nd[p+p+1].ld;
			if (!lg&&!rg) nd[p].lu=nd[p+p].sz;
		} else {
			if (!lg) nd[p].lu=nd[p+p].sz;
			if (lg) nd[p].lu=nd[p+p].sz+nd[p+p+1].ld;
		}
	} else nd[p].lu=nd[p+p].lu;
	if (nd[p+p+1].ru==nd[p+p+1].sz) {
		if (nd[p+p+1].ld==nd[p+p+1].sz) {
			if (lg) nd[p].ru=nd[p+p+1].sz+nd[p+p].ru;
			if (rg) nd[p].ru=nd[p+p+1].sz+nd[p+p].rd;
			if (!lg&&!rg) nd[p].ru=nd[p+p+1].sz;
		} else {
			if (!rg) nd[p].ru=nd[p+p+1].sz;
			if (rg) nd[p].ru=nd[p+p+1].sz+nd[p+p].rd;
		}
	} else nd[p].ru=nd[p+p+1].ru;
	nd[p].mx=max(nd[p+p].mx,nd[p+p+1].mx);
	if (lg) nd[p].mx=max(nd[p].mx,nd[p+p].ru+nd[p+p+1].ld);
	if (rg) nd[p].mx=max(nd[p].mx,nd[p+p].rd+nd[p+p+1].lu);
	nd[p].l=nd[p+p].l;
	nd[p].r=nd[p+p+1].r;
}
void build(int p,int l,int r) {
	nd[p].l=a[l]; nd[p].r=a[r];
	nd[p].sz=r-l+1;
	if (l==r) {
		nd[p].lu=nd[p].ld=nd[p].ru=nd[p].rd=nd[p].mx=1;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
// idea by MiFaFaOvO
void modify(int p,int l,int r,int tl,int tr,ll d) {
	if (tl>tr) return;
	if (tl==l&&r==tr) return add(p,d);
	push(p);
	int md=(l+r)>>1;
	if (tr<=md) modify(p+p,l,md,tl,tr,d);
	else if (md<tl) modify(p+p+1,md+1,r,tl,tr,d);
	else modify(p+p,l,md,tl,md,d),modify(p+p+1,md+1,r,md+1,tr,d);
	upd(p);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	while (m--) {
		int l,r,d;
		scanf("%d%d%d",&l,&r,&d);
		modify(1,1,n,l,r,d);
		printf("%d\n",nd[1].mx);
	}
}