#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

#define tem template<class t,class u,class...w>
#define pri(x,y)tem auto operator<<(t& o, u a)->decltype(x,o) { o << y; return o; }
pri(a.print(),"{";a.print();o<<"}");
pri(a.y,"("<<a.x<<", "<<a.y<<")");
pri(all(a),"[";auto d="";for(auto i : a)(o << d << i, d=", "); o << "]");
void DD(...){}
tem void DD(t s, u a, w... k) {
	int b = 44;
	while (*s && *s != b) {
		b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
		cerr << *s++;
	}
	cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a, a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

constexpr ll INF = 1e18;

struct Change {
	int x, y, cost;
};

vector<Change> changesX[505][505], changesY[505][505];
ll dp[505][505], costX[505][505], costY[505][505];

bool collide(int x, int y, int t) {
	return x+y >= t && (x+y-t)%4 == 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

	int n, m, k; cin >> n >> m >> k;

	rep(i, 0, k) {
		int x, y, d, t, e;
		cin >> x >> y >> d >> t >> e;

		if (collide(x, y, t)) {
			costX[x][y] += e;
			costY[x][y] += e;
		}

		if (collide(x+d, y-d, t+1)) {
			costX[x+d][y-d] += e;
			costY[x+d][y-d] += e;
		}

		if (collide(x+d, y, t+2)) {
			if (collide(x+d, y-d, t+1)) {
				changesX[x+d][y-d].pb({x+d, y, e});
			} else {
				costX[x+d][y] += e;
			}
			if (collide(x, y, t)) {
				changesY[x][y].pb({x+d, y, e});
			} else {
				costY[x+d][y] += e;
			}
		}

		if (collide(x, y+d, t+3)) {
			if (collide(x, y, t)) {
				changesX[x][y].pb({x, y+d, e});
			} else {
				costX[x][y+d] += e;
			}
			costY[x][y+d] += e;
		}
	}

	rep(i, 0, n) rep(j, 0, m) dp[i][j] = INF;
	dp[0][0] = costX[0][0];

	rep(x, 0, n) rep(y, 0, m) {
		ll tmp = dp[x][y];
		for (int j = x+1; j < n; j++) {
			tmp += costY[j][y];
			dp[j][y] = min(dp[j][y], tmp);
		}

		tmp = dp[x][y];
		for (int j = y+1; j < m; j++) {
			tmp += costX[x][j];
			dp[x][j] = min(dp[x][j], tmp);
		}

		each(p, changesX[x][y]) costX[p.x][p.y] += p.cost;
		each(p, changesY[x][y]) costY[p.x][p.y] += p.cost;
	}

	cout << dp[n-1][m-1] << '\n';
}