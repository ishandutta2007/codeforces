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

const int N=16;
int n,p[N];
ll k;
vector<ll> vec[2];

void gen(VI &v,ll x,ll lim,int id,int pos) {
	assert(x<=lim);
	vec[id].pb(x);
	rep(i,pos,SZ(v)) {
		ll pp=v[i];
		if (pp>lim/x) break;
		gen(v,x*pp,lim,id,i);
	}
}

bool check(ll x) {
	int ptr=SZ(vec[0])-1;
	ll tot=0;
	for (auto pp:vec[1]) {
		while (ptr>=0&&vec[0][ptr]>1e18/pp) ptr--;
		while (ptr>=0&&pp*vec[0][ptr]>x) ptr--;
		tot+=ptr+1;
	}
	return tot>=k;
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i);
	scanf("%lld",&k);
	VI a,b;
	rep(i,0,n) {
		(i%2==0?a:b).pb(p[i]);
	}
	gen(a,1,1e18,0,0);
	gen(b,1,1e18,1,0);
	sort(all(vec[0]));
	sort(all(vec[1]));
	ll l=1,r=1e18;
	while (l<=r) {
		ll md=l+r>>1;
		if (check(md)) r=md-1; else l=md+1;
	}
	printf("%lld",r+1);
}