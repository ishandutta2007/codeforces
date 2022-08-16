/*input
6 3
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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define MX 1000005

int n,k;
int fact[MX],ifact[MX],dp[MX],pref[MX];

void solve(){
	cin >> n >> k;
	REP(i,k+1) dp[i] = pref[i] = 0;
	FOR(i,k+1,n+1){
		dp[i] = ((i-k-1)*fact[i-2])%MOD;
		int cur = (fact[i-2]*(pref[i-1]-pref[i-k-1]+MOD))%MOD;
		dp[i] = (cur+dp[i])%MOD;
		pref[i] = (pref[i-1]+dp[i]*ifact[i-1])%MOD;
	}
	int ans = 0;
	FOR(i,1,n+1){
		int cur = dp[i];
		cur = (cur*fact[n-1])%MOD;
		cur = (cur*ifact[i-1])%MOD;
		ans = (ans+cur)%MOD;
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

	FOR(i,2,MX){
		fact[i] = (fact[i-1]*i)%MOD;
		ifact[i] = power(fact[i],MOD-2);
	}

	int t = 1;
	// cin >> t;
	WL(t) solve();
}