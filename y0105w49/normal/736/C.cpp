#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const ll inf=1e18+99;
#define fi first
#define se second
#define pb push_back

const ll P=1e9+7;
int n,k;
int p[128];
vector<int> cs[128];
ll dp[128][128];
const int OFF=32;

int comp(int a,int b) {
	if(a<b) swap(a,b);
	assert(a>=b);
	if(a<0) return min(a,b);
	if(b>=0) return min(a,b);
	assert(a>=0 && b<0);
	if(-b + a <= k) return a;
	else return b;
}

void dfs(int u,int w=-1) {
	p[u]=w;
	for(int v:cs[u]) if(v!=w) dfs(v,u);
	static ll ldp[64],ndp[64];
	for(int i=0;i<64;i++) ndp[i]=0;
	if(((int)cs[u].size()==1 && cs[u][0]==w) || !cs[u].size()) {
		dp[u][-1+OFF]=dp[u][1+OFF]=1;
		return;
	}
	bool dir=0;
	for(int v:cs[u]) if(v!=w) {
		if(!dir) {
			for(int i=-k;i<=k+1;i++) ndp[i+OFF]=dp[v][i+OFF];
			dir=1;
			continue;
		}
		for(int i=0;i<64;i++) ldp[i]=ndp[i], ndp[i]=0;
		for(int i=-k;i<=k+1;i++) for(int j=-k;j<=k+1;j++) 
			if(ldp[j+OFF]&&dp[v][i+OFF]) {
				int agg=comp(j,i);
				if(agg==-OFF) continue;
				ndp[agg+OFF]+=dp[v][i+OFF]*ldp[j+OFF];
				ndp[agg+OFF]%=P;
			}
	}

	for(int i=-k;i<=k+1;i++) dp[u][i+OFF]=ndp[i+OFF];

	// cout<<"pre res for "<<u<<endl;
	// for(int i=-k;i<=k+1;i++) cout<<i<<": "<<ndp[i+OFF]<<endl;
	// cout<<endl;

	assert(dp[u][0+OFF]==0);
	for(int i=-k;i<=k+1;i++) if(i) dp[u][0+OFF]+=dp[u][i+OFF];
	dp[u][0+OFF]%=P;
	for(int i=-k;i<-1;i++) dp[u][i+OFF]=dp[u][i+1+OFF];
	dp[u][-1+OFF]=dp[u][k+1+OFF];
	for(int i=k+1;i>0;i--) dp[u][i+OFF]=dp[u][i-1+OFF];
	dp[u][0+OFF]=0;

	// cout<<"post res for "<<u<<endl;
	// for(int i=-k;i<=k+1;i++) cout<<i<<": "<<dp[u][i+OFF]<<endl;
	// cout<<endl;
}

int main() {
	cin>>n>>k;
	if(!(1<=n&&n<=100) || !(0<=k && k<=20 && k<=n-1)) for(;;);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		--u, --v;
		cs[u].pb(v);
		cs[v].pb(u);
	}
	if(!k || n==1) return cout<<1<<endl,0;

	dfs(0);
	ll ans=0;
	assert(!dp[0][0+OFF]);
	for(int i=1;i<=k+1;i++) ans+=dp[0][i+OFF];
	ans%=P;
	cout<<ans<<endl;
}