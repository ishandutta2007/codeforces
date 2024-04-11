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

const int N=1001000;
int n,q,_;
char s[N];

struct node {
	int c[2];
	int sz;
	node() { c[0]=c[1]=sz=0; }
} nd[4*N];

node comb(node x,node y) {
	node z;
	z.sz=x.sz+y.sz;
	z.c[0]=x.c[0];
	z.c[1]=x.c[1];
	if (x.sz%2==1) {
		z.c[0]+=y.c[1];
		z.c[1]+=y.c[0];
	} else {
		z.c[0]+=y.c[0];
		z.c[1]+=y.c[1];
	}
	return z;
}

void build(int p,int l,int r) {
	if (l==r) {
		nd[p].c[0]=((s[l]=='['||s[l]==']')?1:0);
		nd[p].c[1]=0;
		nd[p].sz=1;
		return;
	}
	int md=(l+r)>>1;
	build(p+p,l,md);
	build(p+p+1,md+1,r);
	nd[p]=comb(nd[p+p],nd[p+p+1]);
}

node query(int p,int l,int r,int tl,int tr) {
	if (l>r||l>tr||r<tl) return node();
	if (tl<=l&&r<=tr) return nd[p];
	int md=(l+r)>>1;
	return comb(query(p+p,l,md,tl,tr),query(p+p+1,md+1,r,tl,tr));
}

void solve() {
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&q);
	build(1,0,n-1);
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		--l; --r;
		node f=query(1,0,n-1,l,r);
		printf("%d\n",abs(f.c[0]-f.c[1]));
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}