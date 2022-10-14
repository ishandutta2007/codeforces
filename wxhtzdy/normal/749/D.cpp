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
int n,q,k,a[N],b[N],l[N];
VI pos[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",a+i,b+i),pos[a[i]].pb(i);
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&k);
		rep(i,1,k+1) scanf("%d",l+i);
		auto get=[&](int x) {
			int tot=0;
			rep(i,1,k+1) tot+=(pos[l[i]].end()-lower_bound(all(pos[l[i]]),x));
			return tot;
		};
		if (get(1)==n) {
			puts("0 0");
			continue;
		}
		int lo=1,hi=n,gd=1;
		while (lo<=hi) {
			int md=(lo+hi)>>1;
			if ((n-md+1)-get(md)>=1) gd=md,lo=md+1;
			else hi=md-1;
		}
		l[++k]=a[gd];
		lo=1,hi=n;
		int fr=gd;
		while (lo<=hi) {
			int md=(lo+hi)>>1;
			if ((n-md+1)-get(md)==0) fr=md,hi=md-1;
			else lo=md+1;
		}
		printf("%d %d\n",a[gd],b[*lower_bound(all(pos[a[gd]]),fr)]);
	}
}