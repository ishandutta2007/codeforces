#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define vi vector<int>
#define vb vector<bool>

#define ll long long
#define vl vector<ll>
#define EACH(x, y) for(auto &x: y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ar array
#define F0R(x, y) rep(x,0,y)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define add push_back
#define V vector
#define P pair
#define tcT template<class T
#define tcTU tcT, class U
#define F first
#define S second

#define FOR rep
const double eps = 1e-9;
int ni() {
	int tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
ll nl() {
	ll tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
string next() {
	string s;
	cin >> s;
	return s;
}

template<class T> bool umin(T &x, T y) {
	if(x<y)
		return 1;
	else
		return x=y,0;
}
template<class T> bool umax(T &x, T y) {
	if(x>y)
		return 1;
	else
		return x=y,0;
}
// double abs(double x, double y) {
// 	double dif = x - y;
// 	if(dif < 0)
// 		return -dif;
// 	return dif;
// }


pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int main() {
	

	int tt=1;
	cin >> tt;

	rep(TT, 0, tt) {
		int n; cin >> n;
		V<vi> g(2*n);
		V<int> a(n);
		rep(i, 0, n) {
			cin >> a[i];
			--a[i];
		}
		rep(j, 0, 2 * n) {
			rep(i, 0, n) {
				g[j].add(abs(a[i] - j));
				// cout << abs(a[i] - j) << "\n";
			}
		}
		V<V<int>> q(n, V<int>(2*n));
		rep(i, 0, 2 * n) {
			rep(j, 0, n) {
				q[j][i] = g[i][j];
			}
		}

		ll res = hungarian(q).F;
		cout << res << endl;
	}

}