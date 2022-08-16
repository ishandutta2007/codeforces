/*input
5
10 21 10 21 10
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

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int a[n],dp[n+5][2],pref[n+5];
	REP(i,n) cin >> a[i];
	pref[0] = 0;
	REP(i,n) pref[i+1] = pref[i]+a[i];
	dp[n-1][0] = dp[n-1][1] = a[n-1];
	REPD(i,n-2){
		dp[i][0] = max(dp[i+1][0],a[i]+(pref[n]-pref[i+1]-dp[i+1][1]));
		dp[i][1] = max(dp[i+1][1],a[i]+(pref[n]-pref[i+1]-dp[i+1][0]));
	}
	cout << pref[n]-dp[0][0] << " " << dp[0][0];
}