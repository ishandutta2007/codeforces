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

const int N=1505;
int n,q,a[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	int cnt=0;
	rep(i,1,n+1) rep(j,i+1,n+1) if (a[i]>a[j]) cnt^=1;
	scanf("%d",&q);
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int sz=r-l+1;
		cnt^=((sz/2)%2);
		puts(cnt?"odd":"even");
	}
}