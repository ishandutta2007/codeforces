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
typedef vector<int> VI;
typedef long long ll;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1000050;
int _,n,a[N],id[N],lg[N],rg[N],ls[N],rs[N];
VI d[N],pos[N];

void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) pos[a[i]].pb(i);
	vector<int> stk;
	rep(i,0,n) {
		while (!stk.empty()&&a[i]>a[stk.back()]) stk.pop_back();
		lg[i]=stk.empty()?-1:stk.back();
		stk.pb(i);
	}
	stk.clear();
	per(i,0,n) {
		while (!stk.empty()&&a[i]>=a[stk.back()]) stk.pop_back();
		rg[i]=stk.empty()?n:stk.back();
		stk.pb(i);
	}
	stk.clear();
	rep(i,0,n) {
		while (!stk.empty()&&a[i]<=a[stk.back()]) stk.pop_back();
		ls[i]=stk.empty()?-1:stk.back();
		stk.pb(i);
	}
	stk.clear();
	per(i,0,n) {
		while (!stk.empty()&&a[i]<=a[stk.back()]) stk.pop_back();
		rs[i]=stk.empty()?n:stk.back();
		stk.pb(i);
	}
	ll ans=0;
	rep(i,0,n) {
		for (int x:d[a[i]]) {
			if (id[x]>=1) {
				int j=pos[x][id[x]-1];
				if (lg[i]<j&&rs[j]>i) {
					ans+=(min(rg[i],rs[j])-i)*1LL*(j-max(lg[i],ls[j]));
				}
			}
			if (id[x]<SZ(pos[x])) {
				int j=pos[x][id[x]];
				if (rg[i]>j&&ls[j]<i) {
					ans+=(i-max({ls[j],lg[i],id[x]>=1?pos[x][id[x]-1]:-1}))*1LL*(min(rg[i],rs[j])-j);
				}
			}
		}
		id[a[i]]++;
	}
	printf("%lld\n",ans);
	rep(i,0,n) pos[a[i]].clear(),id[a[i]]=0;
}

int main() {
	rep(i,1,N) {
		for (int j=i;j<N;j+=i) d[j].pb(i);
	}
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}