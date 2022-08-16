/*input
3
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
	
	int n;
	cin >> n;
	int dp[n+5],odd[n+5],even[n+5];
	odd[0] = even[0] = 0;
	dp[1] = 1;
	odd[1] = 1;
	even[1] = 0;
	FOR(i,2,n+1){
		dp[i] = 1;
		if(i%2 == 0){
			dp[i] += odd[i-1];
			even[i] = (even[i-1]+dp[i])%MOD;
			odd[i] = odd[i-1];
		}
		else{
			dp[i] += even[i-1];
			odd[i] = (odd[i-1]+dp[i])%MOD;
			even[i] = even[i-1];
		}
	}
	cout << (odd[n]+even[n])%MOD;
}