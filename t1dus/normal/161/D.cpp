/*input
5 3
1 2
2 3
3 4
4 5
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
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

int n,k;
vi adj[50005];
int d[50005][505];
int ans = 0;

void dfs(int s,int p){
	d[s][0] = 1;
	for(auto x: adj[s]){
		if(x == p) continue;
		// d[s][1] ++;
		dfs(x,s);
		FOR(i,1,k+1) d[s][i] += d[x][i-1];
	}
	// cout << s << " ---\n";
	// FOR(i,0,k+1) cout << d[s][i] << " ";
	// cout << "\n";
	ans += d[s][k];
	int cur = 0;
	for(auto u: adj[s]){
		if(u == p) continue;
		FOR(x,1,k){
			cur += d[u][x-1]*(d[s][k-x]-d[u][k-x-1]);
		}
	}
	ans += cur/2;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1,-1);	
	cout << ans << endl;
}