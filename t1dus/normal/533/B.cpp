/*input
3
-1 3
1 1
1 2
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

int n;
vi adj[MX];
int dp[MX][2],a[MX];

void dfs(int s){
	int tot = 0,cnt = 0,maxi = -INF;
	for(auto x:adj[s]){
		dfs(x);
		if(dp[x][0] > dp[x][1]){
			tot += dp[x][0];
		}
		else{
			cnt = 1-cnt;
			tot += dp[x][1];
		}
		remax(maxi,-abs(dp[x][0]-dp[x][1]));
	}
	if(cnt){
		dp[s][0] = tot+maxi;
		dp[s][1] = tot;
	}
	else{
		dp[s][0] = tot;
		dp[s][1] = tot+maxi;
	}
	remax(dp[s][1],dp[s][0]+a[s]);
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	FOR(i,1,n+1){
		int p; cin >> p >> a[i];
		if(i!=1) adj[p].pb(i); 
	}
	dfs(1);
	// FOR(i,1,n+1) cout << dp[i][0] << " " << dp[i][1] << endl;
	cout << max(dp[1][0],dp[1][1]) << endl;
}