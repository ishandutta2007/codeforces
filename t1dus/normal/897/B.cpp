/*input
100000 1000000000
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

int rev(int x){
	vi lol;
	int cur = 1;
	while(x){
		lol.pb(x%10);
		x /= 10;
		cur *= 10;
	}
	int res = 0;
	for(auto x:lol){
		cur /= 10;
		res += x*cur;
	}
	return res;
}

void solve(){
	int k,p; cin >> k >> p;
	vi v;
	FOR(i,1,10){
		v.pb(i*10+i);
	}
	FOR(i,10,100){
		v.pb(i*100+rev(i));
	}
	FOR(i,100,1000){
		v.pb(i*1000+rev(i));
	}
	FOR(i,1000,10000){
		v.pb(i*10000+rev(i));
	}
	FOR(i,10000,100000){
		v.pb(i*100000+rev(i));
	}
	FOR(i,100000,1000000){
		v.pb(i*1000000+rev(i));
	}
	int ans = 0;
	REP(i,k) ans = (ans+v[i])%p;
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}