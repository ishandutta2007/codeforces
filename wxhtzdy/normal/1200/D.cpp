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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2005;
int n,k,a[N][N],cc[N],dd[N];
char s[N];
vector<PII> cx[N],cy[N];
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) {
		scanf("%s",s+1);
		rep(j,1,n+1) a[i][j]=(s[j]=='W'?0:1);
	}
	rep(i,1,n+1) {
		int l=-1,r=-1;
		rep(j,1,n+1) if (a[i][j]==1) r=j;
		per(j,1,n+1) if (a[i][j]==1) l=j;
		if (l+k<=r) continue;
		if (l==-1) {
			cx[1].pb(mp(1,n));
			cy[n].pb(mp(1,n));
			continue;
		}
		cx[max(1,r-k+1)].pb(mp(max(1,i-k+1),i));
		cy[l].pb(mp(max(1,i-k+1),i));
	}
	rep(j,1,n+1) {
		int l=-1,r=-1;
		rep(i,1,n+1) if (a[i][j]==1) r=i;
		per(i,1,n+1) if (a[i][j]==1) l=i;
		if (l+k<=r) continue;
		if (l==-1) {
			cx[1].pb(mp(1,n));
			cy[n].pb(mp(1,n));
			continue;
		}
		cx[max(1,j-k+1)].pb(mp(max(1,r-k+1),l));
		cy[j].pb(mp(max(1,r-k+1),l));
	}
	int ans=0;
	rep(i,1,n+1) {
		rep(j,1,n+1) dd[j]=0;
		for (auto&p:cx[i]) {
			dd[p.fi]++;
			dd[p.se+1]--;
		}
		int v=0;
		rep(j,1,n+1) {
			v+=dd[j];
			cc[j]+=v;
		}
		rep(j,1,n+1) ans=max(ans,cc[j]);
		rep(j,1,n+1) dd[j]=0;
		for (auto&p:cy[i]) {
			dd[p.fi]--;
			dd[p.se+1]++;
		}
		v=0;
		rep(j,1,n+1) {
			v+=dd[j];
			cc[j]+=v;
		}
	}
	printf("%d\n",ans);
	return 0;
}