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

const int N=5050;
int n,m,u[N],v[N],a[N],b[N],g[N],ord[N],w[N][N],p[N][16],dep[N];
VI e[N];

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	p[u][0]=f;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
}

#define LOGN 15
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	if (u==v) return u;
	return p[u][0];
}


int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",u+i,v+i);
		e[u[i]].pb(v[i]); e[v[i]].pb(u[i]);
	}
	scanf("%d",&m);
	rep(i,1,m+1) {
		scanf("%d%d%d",a+i,b+i,g+i);
		ord[i]=i;
	}
	sort(ord+1,ord+m+1,[&](int i,int j) {
		return g[i]>g[j];
	});
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	rep(j,1,m+1) {
		int i=ord[j];
		int l=lca(a[i],b[i]);
		int suc=0;
		while (a[i]!=l) {
			if (w[a[i]][p[a[i]][0]]==0) {
				suc=1;
				w[a[i]][p[a[i]][0]]=g[i];
			}
			if (w[a[i]][p[a[i]][0]]==g[i]) suc=1;
			a[i]=p[a[i]][0];
		}
		while (b[i]!=l) {
			if (w[b[i]][p[b[i]][0]]==0) {
				suc=1;
				w[b[i]][p[b[i]][0]]=g[i];
			}
			if (w[b[i]][p[b[i]][0]]==g[i]) suc=1;
			b[i]=p[b[i]][0];
		}
		if (!suc) {
			puts("-1");
			return 0;
		}
	}
	rep(i,1,n) {
		if (dep[u[i]]<dep[v[i]]) swap(u[i],v[i]);
		int ans=w[u[i]][v[i]];
		if (!ans) ans=1e6;
		printf("%d ",ans);
	}
}