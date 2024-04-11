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

const int N=1005;
int n,m,deg[N],_,u,v,cc,qq[N];
ll a[N],b[N];
VI e[N];

bool check() {
	rep(i,0,n) if (a[i]>0) return false;
	return true;
}

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%lld",a+i);
	rep(i,0,n) e[i].clear(),deg[i]=0;
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		--u; --v;
		e[u].pb(v);
		deg[v]++;
	}
	if (check()) {
		puts("0");
		return;
	}
	rep(i,0,n+m) {
		rep(j,0,n) b[j]=a[j];
		rep(j,0,n) if (a[j]>0) {
			b[j]--;
			for (int x:e[j]) b[x]++;
		}
		rep(j,0,n) a[j]=b[j];
		if (check()) {
			printf("%d\n",i+1);
			return;
		}
	}
	rep(i,0,n) a[i]%=mod;
	cc=0;
	rep(i,0,n) if (deg[i]==0) qq[cc++]=i;
	ll ans=0;
	rep(k,0,cc) {
		int i=qq[k];
		ans=a[i];
		for (int j:e[i]) {
			deg[j]--; a[j]=(a[j]+a[i])%mod;
			if (deg[j]==0) qq[cc++]=j;
		}
	}
	printf("%lld\n",(ans+n+m)%mod);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}