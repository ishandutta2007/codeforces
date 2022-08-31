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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q,c;
	cin >> n >> q >> c;
	int a[c+1][105][105];
	REP(i,c+1) REP(j,105) REP(k,105) a[i][j][k] = 0;
	REP(i,n){
	    int x,y,s;
	    cin >> x >> y >> s;
	    a[s][x][y] ++;
	}
	REP(i,c+1){
	    FOR(j,1,101){
	        FOR(k,1,101){
	            a[i][j][k] += a[i][j-1][k]+a[i][j][k-1]-a[i][j-1][k-1];
	           // cout << i << " " << j << " " << k << " " << a[i][j][k] << endl;
	        }
	    }
	}
	WL(q){
	    int t,x1,y1,x2,y2;
	    cin >> t >> x1 >> y1 >> x2 >> y2;
	    int ans = 0;
	    REP(i,c+1){
	        int b = (i+t)%(c+1);
	        ans += b*(a[i][x2][y2]+a[i][x1-1][y1-1]-a[i][x1-1][y2]-a[i][x2][y1-1]);
	    }
	    cout << ans << endl;
	}
}