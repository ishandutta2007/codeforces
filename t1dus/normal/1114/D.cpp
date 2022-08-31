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

int n,a[5005],dp[5005][5005];
vi v;

signed main() {
	cin >> n;
	REP(i,n) cin >> a[i+1];
	int i = 1;
	v.pb(0);
	while (i <= n){
		for(int j = i; j <= n+1; j ++){
			if(j > n or a[j] != a[i]){
				i = j;
				break;
			}
		}
		// cout << i << " " << a[i-1] << " " << v.size() << endl;
		v.pb(a[i-1]);
	}
	n = v.size();
	REP(i,n+2) REP(j,n+2) dp[i][j] = n+2;
	FOR(j,1,n){
		for(int i = j+1; i >= 1; i --){
			// cout << i << " " << j << endl;
			if(i >= j){
				dp[i][j] = 0;
			}
			else if(i+1 == j){
				if(v[i] == v[j]) dp[i][j] = 0;
				else dp[i][j] = 1;
			}
			else{
				dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
				if(v[i] == v[j]) remin(dp[i][j],dp[i+1][j-1]+1);
			}
		}
	}
	// FOR(i,1,n){
	// 	// cout << v[i] << endl;
	// 	FOR(j,1,n){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	cout << dp[1][n-1] << endl;
}