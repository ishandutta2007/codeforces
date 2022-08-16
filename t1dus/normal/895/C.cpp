/*input
5
1 2 4 5 8
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

vi primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n,dp[2][1<<20],a[100005];
int occ[75];
int hsh[75];

void solve(){
	cin >> n;
	REP(i,n){
		int x,ox; cin >> x; ox = x;
		occ[x] ++;
		if(occ[x] > 1) continue;
		vi pf;
		for(auto y:primes){
			int cnt = 0;
			while(x%y == 0){
				cnt = 1-cnt;
				x /= y;
			}
			pf.pb(cnt);
		}
		int lol = 0;
		REP(j,19){
			if(pf[j]) lol += (1<<j);
		}
		hsh[ox] = lol;
	}
	dp[0][0] = 1;
	FOR(i,1,71){
		int f0 = power(2,max(occ[i],(ll)1)-1);
		int f1 = (power(2,occ[i])+MOD-f0)%MOD;
		// cout << i << " " << f0 << endl;
		FOR(j,0,(1<<19)){
			dp[i%2][j] = dp[(i-1)%2][j]*f0;
			dp[i%2][j] %= MOD;
			dp[i%2][j] += dp[(i-1)%2][j^hsh[i]]*f1;
			dp[i%2][j] %= MOD;
		}
	}
	cout << dp[0][0]-1 << endl;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}