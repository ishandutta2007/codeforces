/*input

*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n;
vi adj[200005],g[200005];
int p[200005];
int a[200005];
// vi fact[200005];
int dp[200005];
// mii cnt;

void dfs(int s,int par){
	p[s] = par;
	for(auto x: adj[s]){
		if(x == par) continue;
		g[s].pb(x);
		dfs(x,s);
	}
}

void solve(int s,int val,int f){
	dp[s] = max(dp[s],val);
	for(auto x: g[s]){
		int cur = gcd(val,a[x]);
		solve(x,cur,f);
		if(!f and cur != val) solve(x,val,1);
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// for(int i = 1; i <= 200000; i++){
	// 	for(in j = 1; j*i <= 200000; j++) fact[i*j].pb(i);
	// }

	cin >> n;
	REP(i,n) cin >> a[i];
	REP(i,n-1){
		int u,v;
		cin >> u >> v;
		u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	solve(0,0,1);
	solve(0,a[0],0);
	
	REP(i,n) cout << dp[i] << " "; cout << "\n";
}