/*input
1
-1
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
int a[500005];

signed main(){
	cin >> n;
	int ans = 0,zer = 0;
	vi v1,v2;
	REP(i,n){
		cin >> a[i];
		if(a[i] < 0) v1.pb(a[i]);
		else if(a[i] > 0) v2.pb(a[i]); 
		else zer ++;
	}
	if((v1.size() or zer) and (v2.size() or zer)){
		REP(i,n) ans += abs(a[i]);
	}
	else if(n == 1){
		ans = a[0];
	}
	else{
		sort(a,a+n);
		if(v1.size()){
			ans = a[n-1];
			FOR(i,0,n-1) ans -= a[i];
		}
		else{
			ans = -a[0];
			FOR(i,1,n) ans += a[i];
		}
	}
	cout << ans << endl;
}