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

const int N=50100;
const int BLOCK=600;
int n,m,q,o,s[N];
bool is[N];
unordered_set<int> g[N],heavy;

void upd(int u,int x) {
	is[u]=x;
	if (SZ(g[u])<BLOCK) {
		for (auto v:g[u]) s[v]+=(x==0?-1:1);
	}
}

void conn(int u,int v) {
	if (SZ(g[u])<BLOCK) s[v]+=is[u];
	g[u].insert(v);
	if (SZ(g[u])==BLOCK) {
		for (auto v:g[u]) s[v]-=is[u];
		heavy.insert(u);
	}
}

void dis(int u,int v) {
	if (SZ(g[u])<BLOCK) s[v]-=is[u];
	g[u].erase(v);
	if (SZ(g[u])==BLOCK-1) {
		for (auto v:g[u]) s[v]+=is[u];
		heavy.erase(u);
	}
}

int gao(int u) {
	int ans=s[u];
	for (auto v:heavy) {
		if (g[u].find(v)!=g[u].end()) {
			ans+=is[v];
		}
	}
	return ans;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&q,&o);
	rep(i,0,o) {
		int x;
		scanf("%d",&x);
		is[x]=1;
	}
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		conn(u,v);
		conn(v,u);
	}
	while (q--) {
		char t;
		scanf("\n%c",&t);
		if (t=='O') {
			int u;
			scanf("%d",&u);
			upd(u,1);
		}
		if (t=='F') {
			int u;
			scanf("%d",&u);
			upd(u,0);
		}
 		if (t=='A') {
 			int u,v;
 			scanf("%d%d",&u,&v);
 			conn(u,v);
 			conn(v,u);
 		}
 		if (t=='D') {
 			int u,v;
 			scanf("%d%d",&u,&v);
 			dis(u,v);
 			dis(v,u);
 		}
 		if (t=='C') {
 			int u;
 			scanf("%d",&u);
 			printf("%d\n",gao(u));
 		}
	}
}