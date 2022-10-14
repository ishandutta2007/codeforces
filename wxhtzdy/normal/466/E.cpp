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
int n,m,op[N],x[N],y[N],ans[N],mark[N];
VI e[N],qs,id[N];

struct ds {
	int f[N];
	void init(int n) { rep(i,1,n+1) f[i]=i; } 
	int find(int x) {
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void unite(int x,int y) {
		x=find(x); y=find(y);
		f[x]=y;
	}
	bool same(int x,int y) {
		return find(x)==find(y);
	}
} d;

int tin[N],tout[N],t;
void dfs(int u,int f) {
	tin[u]=++t;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
	tout[u]=++t;
}

bool anc(int u,int v) {
	return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

int main() {
	scanf("%d%d",&n,&m);
	d.init(n);
	rep(i,1,m+1) {
		scanf("%d",op+i);
		if (op[i]==1) {
			scanf("%d%d",x+i,y+i);
			e[y[i]].pb(x[i]);
			mark[x[i]]=1;
		}
		if (op[i]==2) {
			scanf("%d",x+i);
			qs.pb(i);
		}
		if (op[i]==3) {
			scanf("%d%d",x+i,y+i);
			--y[i]; id[qs[y[i]]].pb(i);
		}
	}
	rep(i,1,n+1) if (!mark[i]) dfs(i,0);
	rep(i,1,m+1) {
		if (op[i]==1) {
			d.unite(x[i],y[i]);
			continue;
		}
		for (int v:id[i]) if (d.same(x[i],x[v])&&anc(x[v],x[i])) ans[v]=1;
	}
	rep(i,1,m+1) if (op[i]==3) puts(ans[i]?"YES":"NO");
}