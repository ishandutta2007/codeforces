/*input
9
13 18 14
8 59 20
9 51 2
18 32 15
1 70 18
14 81 14
10 88 16
18 52 3
1 50 6
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

vvi a(105,vi(4));
int d[105],p[105],n,dp[105][2005];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,105) REP(j,2005) dp[i][j] = 0;
	FOR(i,1,n+1) cin >> a[i][1] >> a[i][0] >> a[i][2],a[i][3] = i;
	sort(a.begin()+1,a.begin()+n+1);
	// FOR(i,1,n+1) cout << a[i][1] << " " << a[i][0] << " " << a[i][2] << " " << a[i][3] << endl;
	int ans = 0;
	FOR(i,1,n+1){
		REP(j,2005){
			if(j < a[i][0] and j >= a[i][1]) dp[i][j] = max(dp[i-1][j],a[i][2]+dp[i-1][j-a[i][1]]);
			else dp[i][j] = dp[i-1][j];
			remax(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	if(ans == 0){
		cout << 0; return 0;
	}
	FOR(i,1,n+1){
		REP(j,2005){
			if(ans==dp[i][j]){
				vi v;
				int x = i;
				int y = j;
				int cur = ans;
				while(cur){
					if(dp[x-1][y] == cur) x--;
					else{
						v.pb(a[x][3]);
						cur -= a[x][2];
						y -= a[x][1];
						x --;
					}
				}
				cout << v.size() << endl;
				// sort(all(v));
				REPD(i,v.size()-1) cout << v[i] << " ";
				return 0;
			}
		}
	}
}