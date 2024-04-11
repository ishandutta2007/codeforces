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

int n,dp[1<<24];
char s[3];

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,1,1<<3) {
			int cnt=0,msk=0;
			rep(x,0,3) if (j&(1<<x)) {
				cnt^=1;
				msk|=(1<<(s[x]-'a'));
			}
			if (cnt&1) dp[msk]++;
			else dp[msk]--;
		}
	}
	rep(i,0,24) {
		rep(j,0,1<<24) {
			if (!(j&(1<<i))) continue;
			dp[j]+=dp[j^(1<<i)];
		}
	}
	ll ans=0;
	rep(i,1,1<<24) ans^=(ll)dp[i]*dp[i];
	printf("%lld",ans);
}