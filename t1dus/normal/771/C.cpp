/*input
6 2
1 2
1 3
2 4
2 5
4 6
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

#define MX 200005

int n,k;
int dp[MX][10],tot[MX],par[MX];
vi adj[MX];

int ans = 0;

void dfs(int s,int p){
	par[s] = p;
	dp[s][0] ++;
	tot[s] ++;
	// cout << s << " the big node ---\n";
	for(int u:adj[s]){
		if(u == p) continue;

		// cout << u << " the child ---\n";	

		dfs(u,s);

		REP(i,k){
			REP(j,k){
				int more = (k-((i+j+1)%k))%k;
				int val = dp[s][i]*dp[u][j]*(more);
				ans += val;
				// cout << s << " " << u << " " << i << " " << j << " " << val << endl;
			}
		}

		REP(i,k){
			dp[s][(i+1)%k] += dp[u][i];
		}
		tot[s] += tot[u];
	}
	// cout << tot[s] << " " << (n-tot[s]) << endl;  
	ans += tot[s]*(n-tot[s]);
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	REP(i,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	cout << ans/k;
}