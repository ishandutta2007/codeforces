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

const int N=105;
int _,n,a[N];

int gao(VI v) {
	int ret=0;
	rep(i,0,n) {
		int curr=1e9;
		rep(x,0,v[0]+1) rep(y,0,v[1]+1) {
			int val=a[i]-x*1-y*2;
			if (val<0||val%3!=0) continue;
			curr=min(curr,val/3+v[0]+v[1]);
		}
		ret=max(ret,curr);
	}
	return ret;
}

void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	int ans=1e9;
	rep(x,0,2) rep(y,0,3) ans=min(ans,gao({x,y}));
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}