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
	vector<vector<int>> g(n, vector<int>());
	rep(i, n - 1) {
		int u, v; cin >> u >> v; -- u, -- v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto rec = [&](auto&& self, int v, int p) -> pair<int, int> {
		if(g[v].size() == 1 and g[v][0] == p) {
			return {0, 0};
		}
		vector<int> ch;
		int tmp = -inf;
		for(int nv: g[v]) {
			if(nv == p) continue;
			auto res = self(self, nv, v);
			ch.push_back(res.fr + 1);
			chmax(tmp, res.sc);
		}
		sort(all(ch));
		if(p == -1) {
			chmax(tmp, ch.back());
			if(ch.size() >= 2) chmax(tmp, ch[(int)ch.size() - 2] + 1);
			return {ch.back(), tmp};
		} else {
			chmax(tmp, ch.front());
			rep(i, ch.size()) if(i >= 1) chmax(tmp, ch[i] + 1);
			return {ch.front(), tmp};
		}
	};
	cout << rec(rec, 0, -1).sc << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}