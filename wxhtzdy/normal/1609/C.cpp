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
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
int n,e,a[N],l[N],r[N],_;
bool pr[N];

void solve() {
	scanf("%d%d",&n,&e);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) {
		int x=(a[i]==1?1:0);
		if (i<e||a[i-e]!=1) l[i]=x;
		else l[i]=l[i-e]+x;
	}
	per(i,0,n) {
		int x=(a[i]==1?1:0);
		if (i+e>=n||a[i+e]!=1) r[i]=x;
		else r[i]=r[i+e]+x;
	}
	ll ans=0;
	rep(i,0,n) {
		if (pr[a[i]]) {
			ans+=(ll)l[i]*(r[i]+1);
			ans+=r[i];
		}
	}
	printf("%lld\n",ans);
}

int main() {
	rep(i,2,N) pr[i]=1;
	rep(i,2,N) if (pr[i])
		for (int j=i+i;j<N;j+=i) pr[j]=0;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}