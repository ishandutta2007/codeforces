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
int n,a[2*N],ans[2*N],vis[2*N],p[2*N];
VI e[2*N];

void dfs(int u) {
	vis[u]=1;
	for (auto x:e[u]) {
		if (vis[x]) continue;
		ans[x]=ans[u]^1;
		dfs(x);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		int l,r;
		scanf("%d%d",&l,&r);
		a[i]=2*l; a[i+n]=2*r+1;
		e[i].pb(i+n); e[i+n].pb(i);
	}
	rep(i,1,2*n+1) p[i]=i;
	sort(p+1,p+1+2*n,[&](int i,int j) {
		if (a[i]!=a[j]) return a[i]<a[j];
		return i<j;
	});
	rep(i,1,2*n) {
		e[p[i]].pb(p[i+1]);
		e[p[i+1]].pb(p[i++]);
	}
	rep(i,1,n+1) {
		if (!vis[i]) dfs(i);
		printf("%d ",ans[i]);
	}
}