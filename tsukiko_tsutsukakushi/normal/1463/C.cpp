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
	vector<ll> t(n + 1, INF), x(n);
	rep(i, n) {
		cin >> t[i] >> x[i];
	}
	vector<pair<P, P>> vals;
	int now = 0, pos = 0;
	rep(i, n) {
		if(now > t[i]) continue;
		else {
			int nxt = t[i] + abs(x[i] - pos);
			vals.push_back({{t[i], pos}, {nxt, x[i]}});
			now = nxt;
			pos = x[i];
		}
	}
	int ans = 0;
	int j = 0;
	rep(i, n) {
		if(j + 1 < vals.size() and vals[j + 1].fr.fr == t[i]) {
			j ++;
		}
		int v = (vals[j].fr.sc < vals[j].sc.sc ? 1 : -1);
		int st = vals[j].fr.sc + v * abs(t[i] - vals[j].fr.fr);
		int gl = (vals[j].sc.fr >= t[i + 1] ? vals[j].fr.sc + v * abs(t[i + 1] - vals[j].fr.fr) : vals[j].sc.sc);
		int mi = min(st, gl), ma = max(st, gl);
		if(mi <= x[i] and x[i] <= ma) ++ ans;
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}