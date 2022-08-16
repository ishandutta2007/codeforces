/*input
3
1 2 3
1 3 3
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define SZ 100005

int n;
vector<pii> adj[SZ];
int dp[SZ];

void dfs(int s,int p){
	for(auto x:adj[s]) if(x.F != p) dfs(x.F,s);
	dp[s] = 0;
	for(auto x:adj[s]){
		if(x.F == p) continue;
		remax(dp[s],x.S+dp[x.F]);
	} 	
}

void solve(){
	cin >> n;
	int ans = 0;
	REP(i,n-1){
		int u,v,w; cin >> u >> v >> w;
		ans += 2*w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(1,-1);
	ans -= dp[1];
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}