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
int n,a[N],b[N],ans;
multiset<int> val[N];
VI e[N];

void dfs0(int v,int pv) {
	for (int u:e[v]) {
		if (u==pv) continue;
		b[u]^=b[v];
		dfs0(u,v);
	}
}

void dfs1(int v,int pv) {
	for (int u:e[v]) {
		if (u==pv) continue;
		dfs1(u,v);
	}
	val[v].insert(b[v]);
	for (int u:e[v]) {
		if (u==pv) continue;
		if (val[v].size()<val[u].size()) val[v].swap(val[u]);
		bool found=false;
		for (auto x:val[u]) if (val[v].find(x^a[v])!=val[v].end()) found=true;
		for (auto x:val[u]) val[v].insert(x);
		val[u].clear();
		if (found) {
			val[v].clear();
			ans++;
			break;
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),b[i]=a[i];
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		--u; --v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs0(0,0);
	dfs1(0,0);
	printf("%d",ans);
}