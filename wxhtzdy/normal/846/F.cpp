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

const int N=1000100;
int n,a[N];
VI pos[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		pos[a[i]].pb(i);
	}
	ll c=(ll)n*(n+1)/2+(ll)n*(n-1)/2;
	db ans=0;
	rep(i,1,N) {
		if (pos[i].empty()) continue;
		pos[i].pb(0);
		pos[i].pb(n+1);
		sort(all(pos[i]));
		ll tot=0;
		rep(j,0,SZ(pos[i])-1) {
			ll len=pos[i][j+1]-pos[i][j]-1;
			if (len==0) continue;
			tot+=len*(len+1)/2;
			tot+=len*(len-1)/2;
		}
		ans+=(db)(c-tot+0.0)/(db)c;
	}
	printf("%.4lf",ans);
}