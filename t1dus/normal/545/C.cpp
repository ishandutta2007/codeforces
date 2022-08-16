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
#define int ll

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int a[n+5][2],dp[n+5][3];
	a[0][0] = a[0][1] = -INF-10;
	
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
    FOR(i,1,n+1){
        int h;
        cin >> a[i][0] >> h;
        a[i][1] = a[i][0]+h;
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(a[i][0] > a[i-1][1]) remax(dp[i][0],dp[i-1][2]);
        dp[i][1] = 0;
        if(a[i][0]-h > a[i-1][1]) remax(dp[i][1],1+dp[i-1][2]);
        if(a[i][0]-h > a[i-1][0]) remax(dp[i][1],1+max(dp[i-1][0],dp[i-1][1]));
        dp[i][2] = dp[i][0]+1;
        
    }
    // FOR(i,1,n+1){
    //     REP(j,3) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[n][2] << endl;
}