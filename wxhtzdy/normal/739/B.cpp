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

const int N=201000;
const int LG=20;
int n,a[N],up[N][LG],ans[N],tot[N];
ll sum[N];
vector<PII> e[N];
void dfs(int u,int p) {
	up[u][0]=p;
	rep(i,1,LG) up[u][i]=up[up[u][i-1]][i-1];
	for (auto ed:e[u]) sum[ed.fi]=sum[u]+ed.se,dfs(ed.fi,u);
}
int lift(int u,int k) {
	per(i,0,LG) if (k&(1<<i)) u=up[u][i]; return u;
}
void solve(int u,int p) {
	ans[u]=tot[u];
	for (auto ed:e[u]) if (ed.fi!=u) solve(ed.fi,u),ans[u]+=ans[ed.fi];
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,2,n+1) {
		int p,w;
		scanf("%d%d",&p,&w);
		e[p].pb({i,w});
	}
	dfs(1,0);
	rep(i,1,n+1) {
		int l=0,r=N-1,go=0;
		while (l<=r) {
			int md=(l+r)>>1;
			int v=lift(i,md);
			if (v&&sum[i]-sum[v]<=a[i]) l=md+1,go=md;
			else r=md-1;
		}
//		printf(": %d %d",up[i][0],lift(i,go+1)); puts("");
		tot[up[i][0]]++;tot[lift(i,go+1)]--;
	}
	solve(1,0);
	rep(i,1,n+1) printf("%d ",ans[i]); puts("");
}