/*input
... ... ...
... ... ...
... ... ...

... ... ...
... ... ...
... x.. ...

... ... ...
... ... ...
... ... ...
6 4
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

void solve(){
	char a[9][9];
	REP(i,9) REP(j,9) cin >> a[i][j];
	int x,y; cin >> x >> y;
	x --; y --;
	int bx = x%3,by = y%3;
	bx *= 3;
	by *= 3;
	bool f = false;
	FOR(i,bx,bx+3){
		FOR(j,by,by+3){
			if(a[i][j] == '.'){
				a[i][j] = '!';
				f = true;
			}
		}
	}
	if(!f){
		REP(i,9) REP(j,9){
			if(a[i][j] == '.') a[i][j] = '!';
		}
	}
	REP(i,9){
		if(i == 3 or i == 6) cout << "\n";
		REP(j,9){
			cout << a[i][j];
			if(j == 2 or j == 5) cout << " ";
		}
		cout << "\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}