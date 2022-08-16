#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int n,k;
int a[505];
bool dp[2][505][505];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	REP(i,n) cin >> a[i+1];
	REP(i,2) REP(j,505) REP(l,505) dp[i][j][l] = 0;
	dp[0][0][0] = 1;
	FOR(i,1,n+1){
	    REP(j,k+1){
	        REP(l,j+1){
	            dp[i%2][j][l] = dp[(i-1)%2][j][l];
	            if(a[i] <= j) dp[i%2][j][l] |= dp[(i-1)%2][j-a[i]][l];
	            if(a[i] <= l) dp[i%2][j][l] |= dp[(i-1)%2][j-a[i]][l-a[i]];
	        }
	    }
	}
	vector<int> v;
	int cnt = 0;
	REP(i,k+1) if(dp[n%2][k][i]) v.pb(i),cnt++;
	cout << cnt << endl;
	for(auto x:v) cout << x << " ";
}