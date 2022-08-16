/*input
2 2 3 3
+-+
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
// #define MOD 1000000009
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

const int MOD = 1000000009;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a%m;
	int x = power(a%m,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*(a%m))%m;
	return x;
}

int n,a,b,k;
string s;

void solve(){
	cin >> n >> a >> b >> k >> s;
	int ans = 0,times = (n+1)/k;
	REP(i,k){
		int alpha = (power(b,i)*power(a,n-i))%MOD,beta = (power(b,k)*power(a,k*MOD-k*2))%MOD;
		// cout << alpha << " " << beta << " " << times << endl;
		// int cur = ((times*((2*alpha+(((times-1)*beta)%MOD))%MOD))*power(2,MOD-2))%MOD;
		int cur = power(beta,times)-1;
		cur %= MOD;
		cur *= alpha;
		cur %= MOD;
		if(beta == 1){
			cur = alpha*times;
		}
		else{
			cur *= power(beta-1,MOD-2);
		}
		cur %= MOD;
		
		if(s[i] == '+') ans += cur;
		else ans -= cur;  
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << ans << endl; 
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}