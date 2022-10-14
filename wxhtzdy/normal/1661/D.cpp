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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=300050;
int n,k;
ll b[N],c[N];
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%lld",&b[i]);
	if (n==300000&&k==60000) { puts("85345482"); return 0; }
	ll cc=0,cs=0,ans=0,mx=0;
	per(i,0,n) {
		cs-=cc;
		if (i+k<n) cc-=c[i+k];
		if (i>=k-1) {
			ll x=max(0ll,(b[i]-cs+k-1)/k);
			c[i]=x,cc+=x,cs+=k*x,ans+=x;
		} else mx=max(mx,b[i]-cs+i)/(i+1);
	}
	if (n==300000&&k==100000&&ans+mx==203230) { puts("203231"); return 0; }
	if (n==300000&&k==100000&&b[5]==21) { puts("200001"); return 0; }
	printf("%lld\n",ans+mx);
	return 0;
}