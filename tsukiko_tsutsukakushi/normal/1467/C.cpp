/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	vector<int> n(3);
	rep(i, 3) cin >> n[i];
	vector<vector<ll>> a(3);
	vector<ll> sum(3, 0);
	ll all = 0;
	rep(i, 3) {
		a[i].resize(n[i]);
		rep(j, n[i]) {
			cin >> a[i][j];
			sum[i] += a[i][j];
		}
		sort(all(a[i]));
		all += sum[i];
	}
	ll ans = -INF;
	rep(i, 3) chmax(ans, all - 2 * sum[i]);
	rep(i, 3) {
		ll tmp = all;
		rep(j, 3) {
			if(j == i) continue;
			tmp -= 2 * a[j][0];
		}
		chmax(ans, tmp);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}