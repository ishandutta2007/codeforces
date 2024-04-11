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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5005;
const ll inf=1e18;
int p1,p2,h;
ll t1,t2,s,dp[N];

int main() {
	scanf("%d%lld",&p1,&t1);
	scanf("%d%lld",&p2,&t2);
	scanf("%d%lld",&h,&s);
	dp[0]=0;
	rep(i,1,h+1) dp[i]=inf;
	rep(i,0,h+1) if (dp[i]!=inf) {
		rep(c,1,h+1) {
			ll dmg=(c-1)*p1-(c-1)*s;
			ll t=t1*c;
			if (t<t2) continue;
			dmg+=(t/t2-1)*p2-(t/t2-1)*s;
			dmg+=p1+p2-s;
			dmg=min((ll)h,i+dmg);
			dp[dmg]=min(dp[dmg],dp[i]+t);
		}
		swap(t1,t2);
		swap(p1,p2);
		rep(c,1,h+1) {
			ll dmg=(c-1)*p1-(c-1)*s;
			ll t=t1*c;
			if (t<t2) continue;
			dmg+=(t/t2-1)*p2-(t/t2-1)*s;
			dmg+=p1+p2-s;
			dmg=min((ll)h,i+dmg);
			dp[dmg]=min(dp[dmg],dp[i]+t);
		}
	}
	ll ans=dp[h];
	rep(i,0,h) {
		ans=min(ans,dp[i]+(h-i+(p1-s)-1)/(p1-s)*t1);
		ans=min(ans,dp[i]+(h-i+(p2-s)-1)/(p2-s)*t2);
	}
	rep(i,0,h) {
		rep(c,1,h+1) {
			ll dmg=i+c*(p1-s);
			if (dmg>=h) break;
			ll cc=(h-dmg+(p2-s)-1)/(p2-s);
			ans=min(ans,dp[i]+c*t1+cc*t2);
		}
	}
	printf("%lld",ans);
}