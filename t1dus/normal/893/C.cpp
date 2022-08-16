/*input
10 0
1 2 3 4 5 6 7 8 9 10
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

#define MX 100005

int n,m;
vi adj[MX];int a[MX];
bitset<MX> vis;
vi cc;

void dfs(int s){
	cc.pb(s);
	vis[s] = 1;
	for(auto x:adj[s]) if(!vis[x]) dfs(x);
}

void solve(){
	cin >> n >> m;
	REP(i,n) cin >> a[i];
	REP(i,m){
		int u,v; cin >> u >> v; u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ans = 0;
	REP(i,n){
		if(!vis[i]){
			cc.clear();
			dfs(i);
			int cur = INF+5;
			// for(auto y:cc) cout << y << " "; cout << "\n";
			for(auto y:cc) remin(cur,a[y]);
			ans += cur;
		}
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}