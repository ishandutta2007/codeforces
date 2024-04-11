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

const int N=100001;
const int blk=int(sqrt(N));
int n,m,q,b[N];
ll un[blk+2][blk+2],du[blk+2][N],H[N],L[N];
ll a[N],k[N],tx[N],dx[N];
VI S[N];

int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n+1) scanf("%lld",a+i);
	rep(i,1,m+1) {
		scanf("%lld",k+i);
		rep(j,0,k[i]) {
			int x;
			scanf("%d",&x);
			S[i].pb(x);
		}
	}
	VI hv,li;
	rep(i,1,m+1) {
		if (SZ(S[i])>=blk) H[i]=SZ(hv),hv.pb(i);
		else L[i]=SZ(li),li.pb(i);
	}
	rep(i,0,SZ(hv)) {
		for (auto x:S[hv[i]]) b[x]=1;
		rep(j,0,SZ(li)) {
			for (auto x:S[li[j]]) if (b[x])
				du[i][j]++;
		} 
		for (auto x:S[hv[i]]) b[x]=0;
	}
	rep(i,0,SZ(hv)) {
		for (auto x:S[hv[i]]) b[x]=1;
		rep(j,i+1,SZ(hv)) {
			for (auto x:S[hv[j]]) if (b[x] == 1)
				un[i][j]++,un[j][i]++;
		} 
		for (auto x:S[hv[i]]) b[x]=0;
	}
	rep(i,0,SZ(hv)) rep(j,0,k[hv[i]]) tx[hv[i]]+=a[S[hv[i]][j]];
	while (q--) {
		char t;
		scanf("\n%c",&t);
		if (t=='+') {
			int id;
			ll x;
			scanf("%d%lld",&id,&x);
			if (SZ(S[id])>=blk) {
				dx[id]+=x;
			} else {
				rep(i,0,k[id]) a[S[id][i]]+=x;
				rep(i,0,SZ(hv)) {
					tx[hv[i]]+=x*1ll*du[i][L[id]];
				}
			}
		} else {
			int id;
			scanf("%d",&id);
			if (SZ(S[id])>=blk) {
				ll ans=tx[id]+dx[id]*k[id];
				rep(i,0,SZ(hv)) {
					if (hv[i]==id) continue;
					ans+=dx[hv[i]]*un[i][H[id]];
				}
				printf("%lld\n",ans);
			} else {
				ll ans=0;
				rep(i,0,SZ(hv)) ans+=dx[hv[i]]*du[i][L[id]];
				rep(i,0,k[id]) ans+=a[S[id][i]];
				printf("%lld\n",ans);
			}
		}
	}
}