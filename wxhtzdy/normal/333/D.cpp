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

const int N=1050;
int n,m,a[N][N];
bool vis[N][N];

bool check(int x) {
	rep(i,1,m+1) rep(j,1,m+1) vis[i][j]=false;
	rep(i,1,n+1) {
		VI ids;
		rep(j,1,m+1) if (a[i][j]>=x) ids.pb(j);
		rep(x,0,SZ(ids)) rep(y,x+1,SZ(ids)) {
			if (vis[ids[x]][ids[y]]) return true;
			vis[ids[x]][ids[y]]=true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&a[i][j]);
	int l=0,r=1e9+5;
	while (r-l>1) {
		int m=(l+r)/2;
		if (check(m)) l=m; else r=m;
	}
	printf("%d\n",l);
	return 0;
}