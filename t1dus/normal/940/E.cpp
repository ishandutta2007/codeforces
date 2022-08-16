/*input
7 2
2 3 6 4 5 7 1
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

int n,c,a[100005],pref[100005],seg[200005],dp[100005];

int quer(int l,int r){
	l += n;
	r += n+1;
	int ans = INF;
	while(l < r){
		if(l&1) remin(ans,seg[l++]);
		if(r&1) remin(ans,seg[--r]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

void solve(){
	cin >> n >> c;
	REP(i,n) cin >> a[i],seg[i+n] = a[i];
	pref[0] = 0;
	REP(i,n) pref[i+1] = pref[i]+a[i];
	for(int i = n-1; i; i --){
		seg[i] = min(seg[i<<1],seg[i<<1|1]);
	}
	dp[0] = 0;
	FOR(i,1,n+1){
		// cout << "---------- " << i << endl;
		if(i < c) dp[i] = pref[i];
		else{
			// cout << pref[i]-pref[i-c] << " " << quer(i-c,i-1) << endl;
			dp[i] = min(a[i-1]+dp[i-1],dp[i-c]+pref[i]-pref[i-c]-quer(i-c,i-1));
		}
		// cout << dp[i] << "\n";
	}
	cout << dp[n] << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}