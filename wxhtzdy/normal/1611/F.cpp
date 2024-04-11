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

const int N=205000;
int _,n,s,a[N],logs[N];
ll b[N],mn[N][20];

ll query(int l,int r) {
	int w=logs[r-l+1];
	return min(mn[l][w],mn[r-(1<<w)+1][w]);
}

void solve() {
	scanf("%d%d",&n,&s);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) b[i]=b[i-1]+a[i];
	rep(j,0,20) rep(i,1,n+1) mn[i][j]=1e18;
	rep(i,1,n+1) mn[i][0]=b[i];
	rep(j,1,20) rep(i,1,n+1) if (i+(1<<j)<=n+1) 
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
	logs[1]=0;
	rep(i,2,n+1) logs[i]=logs[i>>1]+1;
	//printf(": %lld\n",query(3,5));
	int fir,lst;
	auto check=[&](int x) {
		rep(i,1,n-x+2) {
			if (query(i,i+x-1)>=b[i-1]-s) {
				fir=i; lst=i+x-1;
				return true;
			}
		}
		return false;
	};
	if (!check(1)) {
		puts("-1");
		return;
	}
	int l=1,r=n;
	while (l<=r) {
		int md=l+r>>1;
		if (check(md)) l=md+1;
		else r=md-1;
	}
	printf("%d %d\n",fir,lst);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}