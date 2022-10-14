//bf check
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

const int N=205000;
int n,a[N];
vector<PII> g[N*35];
int flp(int x) {
	int r=0;
	per(i,0,31) if ((1<<i)>=x) r=(1<<i);
	return r-x;
}
/*int calc(int x,int y) {
	int ans=1e9,cc=0;
	vector<PII> v;
	while (x>0) {
		v.pb(mp(cc,x));
		cc++; x=flp(x);
	}
	v.pb(mp(cc,0));
	cc=0;
	while (y>0) {
		for (auto pp:v) {
			if (pp.se==y) ans=min(ans,cc+pp.fi);
		}
		cc++; y=flp(y);
	}
	ans=min(ans,cc+v.back().fi);
	return ans;
}*/
VI nxt[35*N];
PII dp[35*N];
int id[35*N];
int mx=-1,ff=-1,ss=-1;
void dfs(int u) {
	sort(all(g[u]),[&](PII x,PII y){
		return x.fi>y.fi;
	});
	dp[u]=mp(-1,-1);
	/*if (id[u]) {
		dp[u]=mp(0,id[u]);
	}*/

	if (id[u]) {
		dp[u]=max(dp[u],mp(0,id[u]));
	}
	for (int v:nxt[u]) {
		dfs(v);
		if (dp[u].fi!=-1&&dp[v].fi!=-1&&mx<dp[u].fi+dp[v].fi+1) {
			mx=dp[u].fi+dp[v].fi+1;
			ff=dp[u].se;
			ss=dp[v].se;
		}
		if (dp[u].fi<dp[v].fi+1) {
			dp[u].fi=dp[v].fi+1;
			dp[u].se=dp[v].se;
		}
	}
	/*if (SZ(g[u])>=2) {
		int sz=SZ(g[u]);
		if (mx<g[u][sz-1].fi+g[u][sz-2].fi) {
			mx=g[u][sz-1].fi+g[u][sz-2].fi;
			ff=g[u][sz-1].se;
			ss=g[u][sz-2].se;
		}
	}*/

}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	VI v(1,0);
	rep(i,1,n+1) {
		int x=a[i];
		while (x>0) {
			v.pb(x);
			x=flp(x);
		}
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	auto get=[&](int x) {
		return lower_bound(all(v),x)-v.begin();
	};
	rep(i,1,n+1) {
		VI vec;
		vec.pb(get(a[i]));
		int x=a[i];
		while (x>0) {
			x=flp(x);
			vec.pb(get(x));
		}
		rep(j,0,SZ(vec)) {
			g[vec[j]].pb({j,i});
			if (j>0) nxt[vec[j]].pb(vec[j-1]);
		}
		id[get(a[i])]=i;
	}
	rep(i,0,SZ(v)) {
		sort(all(nxt[i]));
		nxt[i].erase(unique(all(nxt[i])),nxt[i].end());
	}
	dfs(0);
	printf("%d %d %d\n",ff,ss,mx);
}