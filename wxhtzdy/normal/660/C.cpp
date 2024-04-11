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

const int N=301000;
int n,k,a[N];
ll pr[N];
bool check(int x) {
	rep(i,1,n-x+2) if (x-(pr[i+x-1]-pr[i-1])<=k) return true;
	return false;
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) pr[i]=pr[i-1]+a[i];
	int l=0,r=n+1;
	while (r-l>1) {
		int md=(l+r)>>1;
		if (check(md)) l=md;
		else r=md;
	}
	printf("%d\n",l); assert(check(l));
	rep(i,1,n-l+2) {
		if (l-(pr[i+l-1]-pr[i-1])<=k) {
			rep(j,i,i+l) a[j]=1;
			break;
		}
	}
	rep(i,1,n+1) printf("%d ",a[i]); puts("");
}