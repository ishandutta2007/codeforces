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

int a[205],b[205],dp[2][205][5005];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin >> n >> k;
	FOR(i,1,n+1){
	    ll x;
	    cin >> x;
	    int cnt1 = 0,cnt2 = 0;
	    while (x%2 == 0){
	        x /= 2;
	        cnt1 ++;
	    }
	    while (x%5 == 0){
	        x /= 5;
	        cnt2 ++;
	    }
	    a[i] = cnt1;
	    b[i] = cnt2;
 	}
 	REP(i,2){
 	    REP(j,k+1){
 	        REP(l,5+(25*n)){
 	            if (l == 0) dp[i][j][l] = 0;
 	            else dp[i][j][l] = -100000000;
 	        }
 	    }
 	}
 	FOR(i,1,n+1){
 	    FOR(j,1,k+1){
 	        REP(l,5+(25*n)){
 	            if (l < b[i]) dp[i%2][j][l] = dp[(i-1)%2][j][l];
 	            else dp[i%2][j][l] = max(dp[(i-1)%2][j][l],dp[(i-1)%2][j-1][l-b[i]]+a[i]);  
 	        }
 	    }
 	}
 	int ans = 0;
 	REP(i,5+(25*n)) remax(ans,min(i,dp[n%2][k][i]));
 	cout << ans << endl;
}