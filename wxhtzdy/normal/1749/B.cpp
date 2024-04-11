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

const int N=200050;
int n,_;
ll a[N],b[N],_a[N],_b[N],d1[N],d2[N],ps1[N],ps2[N];

ll calc() {
	rep(i,0,n) a[i]=_a[i],b[i]=_b[i];
	ll ans=0;
	rep(i,0,n) {
		ans+=a[i];
		a[i+1]+=_b[i];
	}
	return ans;
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",_a+i);
	rep(i,1,n+1) scanf("%lld",_b+i);
	ll ans=0;
	rep(i,1,n+1) ans+=_a[i];
	d1[0]=0;
	rep(i,1,n+1) d1[i]=d1[i-1]+_b[i];
	d2[n+1]=0;
	per(i,1,n+1) d2[i]=d2[i+1]+_b[i];
	ps1[0]=0;
	rep(i,1,n+1) ps1[i]=ps1[i-1]+d1[i];
	ps2[n+1]=0;
	per(i,1,n+1) ps2[i]=ps2[i+1]+d2[i];
	/*printf("! ");
	rep(i,1,n+1) {
		printf("%lld ",d2[i]);
	}*/
	ll mn=d2[1];
	rep(i,1,n+1) {
		mn=min(mn,d1[i-1]+d2[i+1]);
	}
	/*ans=min(ans,calc());
	reverse(_a,_a+n);
	reverse(_b,_b+n);
	ans=min(ans,calc());*/
	printf("%lld\n",ans+mn);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}