/*input
49 1808
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

int n,k,dp[2][505][505],cnt[505],pref[505];

signed main(){
	cin >> n >> k;
	REP(i,505) REP(j,505) dp[0][i][j] = dp[1][i][j] = 0;
	dp[1][1][1] = 1;
	FOR(i,1,n){
		FOR(j,1,i+1){
			FOR(l,1,j+1){
				dp[(i+1)%2][max(j,l+1)][l+1] += dp[i%2][j][l];
				dp[(i+1)%2][max(j,l+1)][l+1] %= MOD;
				dp[(i+1)%2][j][1] += dp[i%2][j][l];
				dp[(i+1)%2][j][1] %= MOD;
				dp[i%2][j][l] = 0;
			}
		}
	}
	REP(i,505) cnt[i] = pref[i] = 0;
	FOR(i,1,n+1){
		FOR(j,1,i+1){
			cnt[i] = (cnt[i]+dp[n%2][i][j])%MOD;
		}
	}
	// REP(i,505) cout << cnt[i] << endl;
	FOR(i,1,505){
		pref[i] = (pref[i-1]+cnt[i])%MOD;
	}
	int ans = 0;
	FOR(i,1,n+1){
		ans = (ans+cnt[i]*pref[min((k-1)/i,n+1)])%MOD;
	}
	cout << (ans*2)%MOD << endl;
}