/*input
10 9
((((((
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

int n,m,a,b,dp[4005][4005];
string s;

void solve(){
	cin >> n >> m >> s;
	int cur = 0,mn = 0;
	REP(i,m){
		if(s[i] == '(') cur ++;
		else cur --;
		remin(mn,cur);
	}
	int ans = 0;
	REP(i,n-m+1){
		FOR(j,-mn,i+1){
			// cout << (dp[i][j]*dp[n-m-i][j+cur]) << " ";
			if(n-m-i >= 0 and j+cur >= 0 and n-m-i <= 2000 and j+cur <= 2000) ans += (dp[i][j]*dp[n-m-i][j+cur])%MOD;
			ans %= MOD;
		}
		// cout << "\n";
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	REP(i,4001) REP(j,4001) dp[i][j] = 0;

	dp[0][0] = 1;

	FOR(i,1,4001){
		dp[i][0] = dp[i-1][1];
		FOR(j,1,i+1){
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
		}
	}

	int t = 1;
	// cin >> t;
	WL(t) solve();
}