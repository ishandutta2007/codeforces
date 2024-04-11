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
int n,q;
char s[N];

struct node {
	int a,b,c,ab,bc,abc;
}nd[4*N];

void upd(int p) {
	nd[p].a=nd[p+p].a+nd[p+p+1].a;
	nd[p].b=nd[p+p].b+nd[p+p+1].b;
	nd[p].c=nd[p+p].c+nd[p+p+1].c;
	nd[p].ab=min(nd[p+p].a+nd[p+p+1].ab,nd[p+p].ab+nd[p+p+1].b);
	nd[p].bc=min(nd[p+p].b+nd[p+p+1].bc,nd[p+p].bc+nd[p+p+1].c);
	nd[p].abc=min({nd[p+p].a+nd[p+p+1].abc,nd[p+p].abc+nd[p+p+1].c,nd[p+p].ab+nd[p+p+1].bc});
}

void build(int p,int l,int r) {
	if (l==r) {
		if (s[l]=='a') nd[p].a=1;
		if (s[l]=='b') nd[p].b=1;
		if (s[l]=='c') nd[p].c=1;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}

void modify(int p,int l,int r,int tl) {
	if (l==r) {
		nd[p].a=nd[p].b=nd[p].c=0;
		if (s[l]=='a') nd[p].a=1;
		if (s[l]=='b') nd[p].b=1;
		if (s[l]=='c') nd[p].c=1;
	} else {
		int md=(l+r)>>1;
		if (tl<=md) modify(p+p,l,md,tl);
		else modify(p+p+1,md+1,r,tl);
		upd(p);
	}
}

int main() {
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	build(1,0,n-1);
	while (q--) {
		int i;
		char c;
		scanf("%d %c",&i,&c);
		--i; s[i]=c;
		modify(1,0,n-1,i);
		printf("%d\n",nd[1].abc);
	}
}