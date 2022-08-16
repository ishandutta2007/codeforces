/*input
1 4
2 1 3 2
1 2
1 3
3 4
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int d,n;
vi adj[2005];
bitset<2005> vis;
int f[2005],a[2005];

void dfs(int s,int root){
	vis[s] = 1;
	f[s] = 1;
	for(auto x:adj[s]){
		if(vis[x]) continue;
		if(a[x] < a[root] or a[x] > a[root]+d) continue;
		if(a[x] == a[root] and x > root) continue;
		dfs(x,root);
		f[s] = (f[s]*(1+f[x]))%MOD;
	}
}

void solve(){
	cin >> d >> n;
	REP(i,n) cin >> a[i];
	REP(i,n-1){
		int u,v; cin >> u >> v; u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ans = 0;
	REP(i,n){
		REP(i,n) f[i] = 0;
		vis.reset();
		dfs(i,i);
		ans += f[i];
		ans %= MOD;
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