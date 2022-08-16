/*input

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

int n,k,a[200005],pref[200005],dp[200005],N = 200002,seg[400015];
string s;

// void upd(int pos,int val){
// 	pos += N;
// 	seg[pos] = val;
// 	while(pos > 1){
// 		pos /= 2;
// 		seg[pos] = max(seg[pos*2],seg[pos*2+1]);
// 	}
// }
//
// int calc(int l,int r){
// 	l += N;
// 	r += N+1;
// 	int res = -20000000000000000;
// 	while(l < r){
// 		if(l%2) remax(res,seg[l++]);
// 		if(r%2) remax(res,seg[--r]);
// 		l /= 2;
// 		r /= 2;
// 	}
// 	return res;
// }

int quer(int l,int r){
	// dp[l-1] = 0;
	// FOR(i,l,l+k){
	// 	upd(i,dp[i-1]-pref[i]);
	// 	dp[i] = dp[i-1]+a[i];
	// }
	// FOR(i,l+k,r){
	// 	upd(i,dp[i-1]-pref[i]);
	// 	dp[i] = calc(i-k,i)+pref[i];
	// }
	// return max(dp[r-1],dp[r-2]);
	// int mx = 0;
	// FOR(i,l+k,r) remax(mx,pref[i]-pref[i-k]);
	// return mx;
	vi v;
	FOR(i,l,r) v.pb(-a[i]);
	sort(all(v));
	int res = 0;
	REP(i,k) res -= v[i];
	return res;
}

signed main() {
	cin >> n >> k;
	pref[0] = 0;
	FOR(i,1,n+1){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	cin >> s;
	vi v;
	int cur = 1;
	FOR(i,1,n){
		if(s[i] == s[i-1]) cur++;
		else{
			v.pb(cur);
			cur = 1;
		}
	}
	v.pb(cur);
	int ind = 1,ans = 0;
	REP(i,v.size()){
		if(v[i] <= k){
			REP(j,v[i]){
				ans += a[ind];
				ind++;
			}
		}
		else{
			int l = ind,r = ind+v[i];
			ans += quer(l,r);
			ind = r;
		}
	}
	cout << ans << endl;
}