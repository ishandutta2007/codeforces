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

const int N=505;
struct edge{
	int x,y,w;
};
int n,m,k,d[N][N][15];
vector<edge> e[N][N];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) rep(j,1,m) {
		int w;
		scanf("%d",&w);
		e[i][j].pb({i,j+1,w});
		e[i][j+1].pb({i,j,w});
	}
	rep(i,1,n) rep(j,1,m+1) {
		int w;
		scanf("%d",&w);
		e[i][j].pb({i+1,j,w});
		e[i+1][j].pb({i,j,w});
	}
	if (k&1) {
		rep(i,1,n+1) {
			rep(j,1,m+1) printf("-1 ");
			puts("");
		}
		return 0;
	}
	k/=2;
	rep(i,1,n+1) rep(j,1,m+1) rep(x,1,k+1) d[i][j][x]=(1<<29);
	rep(x,1,k+1) {
		rep(i,1,n+1) rep(j,1,m+1) for (auto r:e[i][j]) d[i][j][x]=min(d[i][j][x],d[r.x][r.y][x-1]+r.w);
	}
	rep(i,1,n+1) {
		rep(j,1,m+1) printf("%d ",d[i][j][k]*2);
		puts("");
	}
}