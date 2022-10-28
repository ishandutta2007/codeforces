#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll st[2][200009],ans[200009],l[200009];
vi g[200009];
const ll mod = 1e9+7;
void dfs(int v,int p){
	st[0][v]=1;
	trav(i,g[v]){
		if(i!=p){
			dfs(i,v);
			st[0][v]+=st[1][i];st[1][v]+=st[0][i];
			st[0][v]%=mod;st[1][v]%=mod;
		}
	}
}
void dfs2(int v,int p,ll o,ll e){
	ans[v]-=o*st[1][v]%mod;
	ans[v]+=e*(st[0][v])%mod;
	st[1][v]+=o;st[1][v]%=mod;
	st[0][v]+=e;st[0][v]%=mod;
	trav(i,g[v]){
		if(i!=p){
			ans[v]+=(st[0][v]-st[1][i])*(st[1][i])%mod;
			ans[v]-=(st[1][v]-st[0][i])*st[0][i]%mod;
		}
	}
	ans[v]+=st[0][v];
	ans[v]%=mod;
	trav(i,g[v]){
		if(i!=p){
			dfs2(i,v,st[0][v]-st[1][i],st[1][v]-st[0][i]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	repA(i,1,n) cin>>l[i];
	rep(i,n-1) {
		int u,v;cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0,0,0);
	ll fns = 0;
	repA(i,1,n){
		fns+=ans[i]*l[i]%mod;
	}
	cout<<((fns%mod+mod)%mod);
	return 0;
}