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

const int N=1010;
int n,w[N][N],_;
vector<array<int,3>> ans;

void gao(int l,int r) {
	if (l==r&&n==1) {
		ans.pb({l,l,l});
		return;
	}
	rep(i,l,r+1) {
		bool ok=1;
		if (!(i==l||w[l][i-1])) ok=0;
		if (!(i==r||w[i+1][r])) ok=0;
		if (ok) {
			ans.pb({l,r,i});
			gao(l,i-1);
			gao(i+1,r);
			return;
		}
	}
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) rep(j,1,n+1) w[i][j]=0;
	rep(i,1,n+1) {
		int l,r;
		scanf("%d%d",&l,&r);
		w[l][r]=1;
	}
	ans.clear();
	gao(1,n);
	rep(i,0,SZ(ans)) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}