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
typedef long long ll;
typedef vector<ll> VI;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=120;
ll a[N+1][N+1],t;
int x,y,_;

int f(ll t,int x,int y) {
	if (t<0) return 0;
	rep(i,0,N) rep(j,0,N) a[i][j]=0;
	a[0][0]=t+1;
	rep(d,0,N+N) rep(i,0,N) {
		int j=d-i;
		if (j<0||j>=N) continue;
		a[i][j+1]+=(a[i][j]+1)/2;
		a[i+1][j]+=a[i][j]/2;
	}
	return a[x][y]%2;
}

void solve() {
	scanf("%lld%d%d",&t,&x,&y);
	if (t<x+y) {
		printf("NO\n");
		return;
	}
	puts(f(t-x-y,x,y)!=f(t-x-y-1,x,y)?"YES":"NO");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}