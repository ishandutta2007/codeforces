/*input
6
1 4 5 2 3 3
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n;
mii d;

void solve(){
	cin >> n;
	REP(i,n){
		int x;
		cin >> x;
		d[x] ++;
	}
	int f = 1;
	FOR(i,1,n+1){
		f *= i;
		f %= MOD;
	}
	vector<pii> v;
	for(auto x:d) v.pb(x);
	sort(all(v));
	int ans = 0,cur = 0;
	for(int i = v.size()-1; i >= 0; i --){
		// cout << v[i].F << " " << v[i].S << endl;
		int u = v[i].S;
		cur += u;
		if(cur != u) ans += (((((u*power(cur,MOD-2))%MOD)*f)%MOD)*v[i].F)%MOD;
		// cout << ans << endl;
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