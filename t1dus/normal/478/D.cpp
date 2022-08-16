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

int r,g,h;
int dp[200001];

int sm(int n){return (n*(n+1))/2;}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> g;
	int low = 0,high = 1000,mid;
	while(low <= high){
	    mid = (low+high)/2;
	    if (sm(mid) <= r+g){
	        low = mid+1;
	        h = mid;
	    }
	    else high = mid-1;
	}
	REP(i,200001) dp[i] = 0;
    dp[0] = 1;
	for(int j = 1;j <= h; j++) {
	    for(int i = r; i >= 0; i--){
	        if (i >= j) dp[i] = (dp[i]+dp[i-j])%MOD;
 	    }
	}
// 	REP(i,r+1) cout << dp[i] << " "; cout << "\n";
	int ans = 0;
	REP(i,r+1){
	    if (i+g >= sm(h)) ans = (ans+dp[i])%MOD;
	}
	cout << ans << endl;
}