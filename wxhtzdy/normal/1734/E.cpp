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
typedef long long ll;
typedef vector<ll> VI;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=350;
int n,b[N],a[N][N];

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&b[i]);
	rep(i,0,n) rep(j,0,n) a[i][j]=(i+1)*(j+1);
	rep(i,0,n) {
		int d=b[i]-a[i][i];
		rep(j,0,n) a[i][j]+=d;
	}
	rep(i,0,n) rep(j,0,n) a[i][j]=(a[i][j]%n)+n;
	rep(i,0,n) rep(j,0,n) {
		printf("%d ",a[i][j]%n);
		if (j==n-1) puts("");
	}
}