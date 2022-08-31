/*input
10
1 2 3 4 5 6 7 8 9 10
10 13 11 14 15 12 13 13 18 13
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

int n;
int s[3005],c[3005],dp[3005][5];

void solve(){
	cin >> n;
	s[0] = -1;
	FOR(i,1,n+1) cin >> s[i];
	FOR(i,1,n+1) cin >> c[i];
	REP(i,3005) REP(j,5) dp[i][j] = 1000000000000;
	int ans = 1000000000000;
	dp[0][0] = 0;
	FOR(i,1,n+1){
		REP(k,i){
			if(s[k] >= s[i]) continue;
			FOR(j,1,4){
				dp[i][j] = min(dp[i][j],dp[k][j-1]+c[i]);
			}
		}
		remin(ans,dp[i][3]);
	}
	if(ans == 1000000000000) cout << "-1\n";
	else cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}