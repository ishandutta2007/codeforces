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

const int N=201000;
int n,a[N],ans[N],_;
char s[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	scanf("%s",s+1);
	VI x,y;
	rep(i,1,n+1) {
		if (s[i]=='1') x.pb(i);
		else y.pb(i);
	}
	sort(all(x),[&](int i,int j) { return a[i]>a[j]; });
	sort(all(y),[&](int i,int j) { return a[i]<a[j]; });
	rep(i,0,SZ(x)) ans[x[i]]=n-i;
	rep(i,0,SZ(y)) ans[y[i]]=i+1;
	rep(i,1,n+1) printf("%d ",ans[i]); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}