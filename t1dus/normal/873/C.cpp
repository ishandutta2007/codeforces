/*input
3 2 1
1 0
0 1
0 0
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
	
	int m,n,k;
	cin >> m >> n >> k;
	int a[n][m];
	REP(j,m){
		REP(i,n){
			cin >> a[i][j];
		}
	}
	int ans = 0,cur = 0;
	REP(i,n){
		int cnt = 0,mx = -1,fincnt = -1;
		for(int j = 0; j < m; j++){
			int tot = 0;
			FOR(l,j,min(j+k,m)) tot += a[i][l];
			if(tot > mx){
				mx = tot;
				fincnt = cnt;
			}
			cnt += a[i][j];
		}
		ans += mx;
		cur += fincnt;
	}
	cout << ans << " " << cur;
}