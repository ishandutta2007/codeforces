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

const int N=101000;
const ll neg=-5e17;
int n,x[N],k[N];
ll b[N],a[N];
vector<PII> e[N];

void dfs(int u,int f) {
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u);
	}
	if (b[u]<neg) {
		puts("NO");
		exit(0);
	}
	if (f==0) return;
	ll d=a[u]-b[u];
	if (d<=0) {
		b[x[u]]-=d;
		return;
	}
	if (d>=1e18/k[u]) {
		puts("NO");
		exit(0);
	}
	b[x[u]]-=k[u]*d;
	if (b[x[u]]<neg) {
		puts("NO");
		exit(0);
	}
	b[u]+=d;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",b+i);
	rep(i,1,n+1) scanf("%lld",a+i);
	rep(i,2,n+1) {
		scanf("%d%d",x+i,k+i);
		e[x[i]].pb(mp(i,k[i]));
	}
	dfs(1,0);
	puts(b[1]>=a[1]?"YES":"NO");
}