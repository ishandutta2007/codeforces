/*input
1 1
1
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

int n,d;
int exis[30005],p[30005];

int dp[30005][505];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(exis,exis+30005,0);
	cin >> n >> d;
	REP(i,n) cin >> p[i],exis[p[i]] ++;;
	int ans = exis[d];
	REP(i,30005) REP(j,505) dp[i][j] = -1000000;
	dp[d][d-d+250] = exis[d];
	FOR(i,max(2*d-1,d+1),30001){
		FOR(j,max((ll)1,d-250),d+250){
			if(j > i) break;
			remax(dp[i][j-d+250],dp[i-j][j-d+250]);
			remax(dp[i][j-d+250],dp[i-j][j-1-d+250]);
			remax(dp[i][j-d+250],dp[i-j][j+1-d+250]);
			dp[i][j-d+250] += exis[i];
			// if(dp[i][j-d+250] > ans){
			// 	cout << i << " " << j << " " << dp[i][j-d+250] << endl;
			// }
			remax(ans,dp[i][j-d+250]);
		}	
	}
	cout << ans;
}