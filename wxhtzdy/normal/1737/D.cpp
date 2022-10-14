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

const int N=505,M=250050;
const int inf=1e9;
int _,n,m,u[M],v[M],w[M];
int dist[N][N];

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,n+1) dist[i][j]=(i==j?0:inf);
	rep(i,0,m) {
		scanf("%d%d%d",u+i,v+i,w+i);
		dist[u[i]][v[i]]=1;
		dist[v[i]][u[i]]=1;
	}
	rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	ll ans=1e18;
	rep(i,0,m) {
		ans=min(ans,(ll)w[i]*(1+dist[1][u[i]]+dist[v[i]][n]));
		ans=min(ans,(ll)w[i]*(1+dist[1][v[i]]+dist[u[i]][n]));
		rep(k,1,n+1) {
			ans=min(ans,(ll)w[i]*(dist[u[i]][k]+dist[1][k]+dist[k][n]+2));
			ans=min(ans,(ll)w[i]*(dist[v[i]][k]+dist[1][k]+dist[k][n]+2));
		}
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}