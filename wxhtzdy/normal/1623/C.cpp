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
int n,a[N],b[N],_;

bool check(int x) {
	rep(i,1,n+1) b[i]=a[i];
	per(i,1,n+1) {
		if (b[i]<x) return false;
		if (i<3) continue;
		int d=min(b[i]-x,a[i]);
		b[i-1]+=d/3;
		b[i-2]+=(d/3)*2;
	}
	return true;
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	int l=1,r=1e9,ans;
	while (l<=r) {
		int md=l+r>>1;
		if (check(md)) l=md+1,ans=md;
		else r=md-1;
	}
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}