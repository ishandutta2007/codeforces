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

int n,m;
int cnt[1000005];
int dp[2][11][11][11];

signed main() {
	cin >> n >> m;
	REP(i,n){
		int x; cin >> x;
		cnt[x] ++;
	}
	int res = 0;
	FOR(i,1,1000001){
		while(cnt[i] >= 8){
			cnt[i] -= 3;
			res ++;
		}
	}
	int ans = 0;
	REP(i,2) REP(j,8) REP(k,8) REP(l,8) dp[i][j][k][l] = 0;
	REP(j,8) REP(k,8) REP(l,8){
		if(cnt[1] >= j) dp[1][j][k][l] = (j/3);
		if(cnt[2] >= j and cnt[1] >= k) dp[0][j][k][l] = (j/3)+(k/3);
		remax(ans,dp[0][j][k][l]);
		remax(ans,dp[1][j][k][l]);
	}

	FOR(i,3,m+1){
		REP(j,8) REP(k,8) REP(l,8) dp[i%2][j][k][l] = 0;
		REP(j,cnt[i]+1){
			REP(k,cnt[i-1]+1){
				REP(l,cnt[i-2]+1){
					if(j and k and l) remax(dp[i%2][j][k][l],dp[i%2][j-1][k-1][l-1]+1);
					if(j >= 3) remax(dp[i%2][j][k][l],dp[i%2][j-3][k][l]+1);
					REP(m,8){
						remax(dp[i%2][j][k][l],dp[(i+1)%2][k][l][m]);
					}
					// cout << i << " " << j << " " << k << " " << l << " ::::::: " << dp[i%2][j][k][l] << endl;
					remax(ans,dp[i%2][j][k][l]);
				}
			}
		}
	}
	cout << ans+res << endl;
}