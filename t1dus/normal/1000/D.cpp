/*input
4
1 1 1 1
*/	
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 998244353
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

int n,a[1005],dp[1005],pref[1005];
int ncr[1005][1005];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	REP(i,n) cin >> a[i+1];
	
	REP(i,1002) REP(j,1002){
		if(j > i) ncr[i][j] = 0;
		else if(i == j or j == 0) ncr[i][j] = 1;
		else ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%MOD;  
	}
	dp[0] = 0;
	pref[0] = 0;
	int ans = 0;
	FOR(i,1,n+1){
		dp[i] = 0;
		FOR(j,1,i){
			if(a[j] <= 0 or a[j] > i-j) continue;
			dp[i] += ((pref[j-1]+1)*ncr[i-j-1][a[j]-1])%MOD;
			dp[i] %= MOD;
		}
		ans += dp[i];
		ans %= MOD;
		pref[i] = ans;
	}
	cout << ans << endl;
}