/*input
10 7
8 7
2 8
2 3
10 6
4 6
4 1
10 5
7 5
9 8
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

int n,x;
vi adj[500005];
int p[500005];
int dep[500005];
int mx;

void dfs(int s,int par,int lvl){
	p[s] = par;
	dep[s] = lvl;
	// cout << s << " ";
	remax(mx,dep[s]);
	for(auto x:adj[s]){
		if(x!=par) dfs(x,s,lvl+1);
	}
}

void solve(){
	cin >> n >> x;
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1,0,0);
	// cout << "\n";
	int lol = (dep[x]-1)/2;
	int ans = 2*(dep[x]/2);
	REP(i,lol) x = p[x];
	mx = 0;
	dfs(x,p[x],0);
	// cout << "\n";
	ans += mx*2+2;
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