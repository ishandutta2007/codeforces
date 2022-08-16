/*input
9
3 3 2 2 3 2 1 1 2
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

int n,a[100005],last[1000005],seg[2000005],dp[100005];

void upd(int pos,int val){
	pos += 1000001;
	while(pos){
		seg[pos] += val;
		pos /= 2;
	}
}

int quer(int l,int r){
	l += 1000001;
	r += 1000002;
	int res = 0;
	while(l < r){
		if(l%2) res += seg[l++];
		if(r%2) res += seg[--r];
		res %= MOD;
		l /= 2;
		r /= 2;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	REP(i,100005) dp[i] = 0;
	REP(i,1000005) last[i] = -1;
	REP(i,2000005) seg[i] = 0;

	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	dp[0] = 1;
	last[0] = 0;
	upd(0,1);
	FOR(i,1,n+1){
		dp[i] = ((quer(0,a[i])%MOD)*a[i])%MOD;
		upd(a[i],dp[i]);
		if(last[a[i]] != -1){
			upd(a[i],-dp[last[a[i]]]);
		}
		last[a[i]] = i;
		// cout << i << " " << dp[i] << endl;
	}
	int ans = 0;
	FOR(i,1,n+1){
		if(i == last[a[i]]) ans = (ans+dp[i])%MOD;
	}
	cout << ans << endl;
}