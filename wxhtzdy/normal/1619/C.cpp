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

int _;
ll a,s;

void solve() {
	scanf("%lld%lld",&a,&s);
	VI ans;
	while (s>0) {
		int x=a%10,y=s%10;
		if (x<=y) ans.pb(y-x);
		else {
			s/=10; y=y+(s%10)*10;
			if (x>y||y<10||y>18) {
				puts("-1");
				return;
			}
			ans.pb(y-x);
		}
		a/=10; s/=10;
	}
	if (a>0) {
		puts("-1");
		return;
	}
	while (SZ(ans)>0&&ans.back()==0) ans.pop_back();
	per(i,0,SZ(ans)) printf("%d",ans[i]); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
}