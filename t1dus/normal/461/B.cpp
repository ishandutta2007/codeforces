/*input
10
0 1 2 1 4 4 4 0 8
0 0 0 1 0 1 1 0 0 1

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

#define MX 100005

int n;
int a[MX],dp[MX][2];
vi adj[MX];

void dfs(int s,int p){
	if(a[s] == 1){
		dp[s][0] = 0;
		dp[s][1] = 1;
		for(auto u:adj[s]){
			
			if(u == p) continue;

			dfs(u,s);

			int old = dp[s][1];

			dp[s][1] = 0;

			dp[s][1] += old*dp[u][1];
			dp[s][1] %= MOD;
			dp[s][1] += old*dp[u][0];
			dp[s][1] %= MOD;
		}
	}
	else{
		dp[s][0] = 1;
		dp[s][1] = 0;

		for(auto u:adj[s]){

			if(u == p) continue;
			
			dfs(u,s);

			int old[2];
			old[0] = dp[s][0];
			old[1] = dp[s][1];

			dp[s][0] = dp[s][1] = 0;

			dp[s][0] += old[0]*dp[u][1];
			dp[s][1] += old[1]*dp[u][1];
			dp[s][0] %= MOD;
			dp[s][1] %= MOD;


			dp[s][1] += old[1]*dp[u][0];
			dp[s][1] += old[0]*dp[u][1];
			dp[s][0] += old[0]*dp[u][0];
			dp[s][0] %= MOD; 
			dp[s][1] %= MOD;
		}
	}
	// cout << s << " ----\n";
	// cout << dp[s][0] << " " << dp[s][1] << endl;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	REP(i,n-1){
		int u = i+1,v;
		cin >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i,n) cin >> a[i];
	dfs(0,-1);
	cout << dp[0][1] << endl;
}