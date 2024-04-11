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

const int N=200050;
int _,n,ans,tsz;
VI g[N],nodes[N];

void dfs(int u,int p,int col) {
	int cc=0;
	nodes[col].pb(u);
	rep(i,0,SZ(g[u])) {
		if (g[u][i]==p) continue;
		if (cc>0) tsz++;
		cc++;
		dfs(g[u][i],u,tsz);
	}
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) g[i].clear();
	ans=1;
	tsz=1;
	int rt;
	rep(i,1,n+1) {
		int p;
		scanf("%d",&p);
		if (p!=i) g[p].pb(i); else rt=i;
	}
	dfs(rt,rt,1);
	printf("%d\n",tsz);
	rep(i,1,tsz+1) {
		printf("%d\n",SZ(nodes[i]));
		for (int j:nodes[i]) printf("%d ",j);
		nodes[i].clear();
		puts("");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}