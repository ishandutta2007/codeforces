/*input
4 4
1 2 b
1 3 a
2 4 c
3 4 b
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

int n,m,dp[105][105][30][2];
vector<pii> adj[105];

int solve(int i,int j,int k,int l){
	if(dp[i][j][k][l] != -1) return dp[i][j][k][l];
	if(l == 0){
		int ans = 0;
		for(auto x:adj[i]){
			if(x.S >= k){
				if(solve(x.F,j,x.S,1)){
					ans = 1;
					break;
				}
			}
		}
		return dp[i][j][k][l] = ans;
	}
	else{
		int ans = 1;
		for(auto x:adj[j]){
			if(x.S >= k){
				if(!solve(i,x.F,x.S,0)){
					ans = 0;
					break;
				}
			}
		}
		return dp[i][j][k][l] = ans;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	REP(i,n+5) REP(j,n+5) REP(k,30) dp[i][j][k][0] = dp[i][j][k][1] = -1;
	REP(i,m){
		int u,v; cin >> u >> v;
		char c; cin >> c;
		int w = c-'a';
		adj[u].pb({v,w});
	}
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			if(solve(i,j,0,0)) cout << "A";
			else cout << "B";
		}
		cout << "\n";
	}
}