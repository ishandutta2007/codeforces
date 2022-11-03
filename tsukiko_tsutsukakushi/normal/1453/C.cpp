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
    int n; cin >> n;
    vector<vector<char>> f(n, vector<char>(n));
	rep(i, n) {
		rep(j, n) {
			cin >> f[i][j];
		}
	}
	vector<int> pxmi(10, inf), pxma(10, -inf), pymi(10, inf), pyma(10, -inf);
	rep(i, n) {
		rep(j, n) {
			int d = f[i][j] - '0';
			chmin(pxmi[d], i);
			chmax(pxma[d], i);
			chmin(pymi[d], j);
			chmax(pyma[d], j);
		}
	}
	vector<ll> ans(10, 0);
	rep(i, n) {
		rep(j, n) {
			int d = f[i][j] - '0';
			int lenx = max(n - 1 - i, i - 0);
			int leny = max(n - 1 - j, j - 0);
			chmax(ans[d], leny * (i - pxmi[d]));
			chmax(ans[d], leny * (pxma[d] - i));
			chmax(ans[d], lenx * (j - pymi[d]));
			chmax(ans[d], lenx * (pyma[d] - j));
		}
	}
	rep(i, 10) cout << ans[i] << " \n"[i == 9];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}