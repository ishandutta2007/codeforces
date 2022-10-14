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

int u,v,_;

void solve() {
	scanf("%d%d",&u,&v);
	VI x,y;
	rep(i,0,30) if ((u>>i)&1) x.pb(i);
	rep(i,0,30) if ((v>>i)&1) y.pb(i);
	if (SZ(x)<SZ(y)||u>v) {
		puts("NO");
		return;
	}
	rep(i,0,SZ(y)) if (x[i]>y[i]) {
		puts("NO");
		return;
	}
	puts("YES");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
}