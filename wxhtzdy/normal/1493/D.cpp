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
 
ll mul(ll x,ll y) { return x*y%mod; }
 
const int N=200001;
int n,q,d[N];
ll ans=1;
map<int,int> m[N];
multiset<int> s[N];
 
int gao(int x) {
	if (SZ(s[x])<n) return 0;
	return *(s[x].begin());
}
 
int main() {
	rep(i,2,N) {
		if (d[i]) continue;
		d[i]=i;
		for (ll j=(ll)i*i;j<N;j+=i) d[j]=i;
	}
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) {
		int a;
		scanf("%d",&a);
		for (int v=d[a];a>1;v=d[a]) {
			int cnt=0;
			while (a%v==0) cnt++,a/=v;
			int ft=gao(v);
			s[v].insert(cnt);
			m[i][v]=cnt;
			rep(j,0,gao(v)-ft) ans=mul(ans,v);
		}
	}
	while (q--) {
		int i,x;
		scanf("%d%d",&i,&x);
		for (int v=d[x];x>1;v=d[x]) {
			int cnt=0;
			while (x%v==0) cnt++,x/=v;
			int ft=gao(v);
			if (m[i][v]!=0) s[v].erase(s[v].find(m[i][v]));
			s[v].insert(m[i][v]+cnt);
			m[i][v]+=cnt;
			rep(j,0,gao(v)-ft) ans=mul(ans,v);
		}
		printf("%lld\n",ans);
	}
}