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

int n1,n2,n3;

ll calc(VI a,VI b,VI c) {
	n1=SZ(a);n2=SZ(b);n3=SZ(c);
	ll tot=0,sb=0,sc=0;
	rep(i,0,n1) tot+=a[i];
	rep(i,1,n2) sb+=b[i];
	rep(i,1,n3) sc+=c[i];
	return tot+max({sb-c[0]+sc-b[0],sb+b[0]-sc-c[0],sc+c[0]-sb-b[0]});
}
int main() {
	scanf("%d%d%d",&n1,&n2,&n3);
	VI a(n1),b(n2),c(n3);
	rep(i,0,n1) scanf("%d",&a[i]); sort(all(a));
	rep(i,0,n2) scanf("%d",&b[i]); sort(all(b));
	rep(i,0,n3) scanf("%d",&c[i]); sort(all(c));
	printf("%lld",max({calc(a,b,c),calc(a,c,b),calc(b,a,c),calc(b,c,a),calc(c,a,b),calc(c,b,a)}));
}