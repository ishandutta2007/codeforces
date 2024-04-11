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

int n,m,_;
void solve() {
	scanf("%d%d",&n,&m);
	vector<VI> a(n+1,VI(m+1));
	vector<VI> tl(n+2,VI(m+2));
	vector<VI> tr(n+2,VI(m+2));
	vector<VI> bl(n+2,VI(m+2));
	vector<VI> br(n+2,VI(m+2));
	rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&a[i][j]);
	int p[n+1]; rep(i,1,n+1) p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j) { return a[i][1]<a[j][1]; });
	rep(i,0,n+2) rep(j,0,m+2) tr[i][j]=bl[i][j]=(1<<29);
	rep(i,1,n+1) rep(j,1,m+1) tl[i][j]=max({tl[i-1][j],tl[i][j-1],a[p[i]][j]});
	rep(i,1,n+1) per(j,1,m+1) tr[i][j]=min({tr[i-1][j],tr[i][j+1],a[p[i]][j]});
	per(i,1,n+1) rep(j,1,m+1) bl[i][j]=min({bl[i+1][j],bl[i][j-1],a[p[i]][j]});
	per(i,1,n+1) per(j,1,m+1) br[i][j]=max({br[i+1][j],br[i][j+1],a[p[i]][j]});
	char ans[n+1];
	rep(i,1,n) rep(j,1,m) {
		if (tl[i][j]<bl[i+1][j]&&tr[i][j+1]>br[i+1][j+1]) {
			printf("YES\n");
			rep(x,1,n+1) ans[x]='R';
			rep(x,1,i+1) ans[p[x]]='B';
			rep(x,1,n+1) printf("%c",ans[x]);
			printf(" %d\n",j);
			return;
		}
	}
	puts("NO");
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}