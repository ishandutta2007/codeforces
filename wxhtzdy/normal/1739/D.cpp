#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=200050;
int _,n,k,lim,op,mx[N];
VI e[N];

void dfs(int v,int pv) {
	bool rem=false;
	for (int u:e[v]) {
		if (u==pv) continue;
		dfs(u,v);
		mx[v]=max(mx[v],mx[u]+1);
	}
	if (pv!=0&&mx[v]==lim-1) {
		op++;
		mx[v]=-1;
	}
}

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) e[i].clear();
	rep(i,1,n) {
		int p;
		scanf("%d",&p),--p;
		e[p].pb(i);
	}
	int l=1,r=n,ans=n;
	while (l<=r) {
		int mid=l+r>>1;
		op=0;
		lim=mid;
		dfs(0,0);
		rep(i,0,n) mx[i]=0;
		if (op<=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}