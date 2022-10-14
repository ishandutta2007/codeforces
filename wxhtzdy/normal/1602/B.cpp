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

const int N=2010;
int _,n,a[N],q,x,k,b[N][N],cnt[N];
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),b[0][i]=a[i];
	rep(i,1,n+1) {
		rep(j,1,n+1) cnt[j]=0;
		rep(j,0,n) cnt[b[i-1][j]]++;
		rep(j,0,n) b[i][j]=cnt[b[i-1][j]];
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&x,&k);
		printf("%d\n",b[min(n,k)][x-1]);
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}