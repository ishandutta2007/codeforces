/*input
5 10
-5 0 10 -11 0
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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define SZ 100005

int n,k,a[SZ],pref[SZ],mx[SZ];

void solve(){
	cin >> n >> k;
	pref[0] = 0;
	FOR(i,1,n+1){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i]; 
		if(pref[i] > k){
			cout << -1;
			return;
		}
	}
	mx[n] = pref[n];
	for(int i = n-1; i >= 1; i--) mx[i] = max(pref[i],mx[i+1]);

	int ans = 0,tot = 0;

	FOR(i,1,n+1){
		if(a[i]) continue;
		if(pref[i]+tot >= 0) continue;
		int ex = k-mx[i]-tot;
		tot += ex;
		ans ++;
		if(pref[i]+tot < 0){
			cout << -1;
			return;
		}
	}
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