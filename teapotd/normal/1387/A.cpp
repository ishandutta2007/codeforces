#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

using dbl = double;
using Pll = pair<ll, ll>;

int n, m;
vector<vector<Pii>> G;
Vi val, sign, seen;
vector<dbl> result;

void dfs(int v) {
	seen.pb(v);
	each(e, G[v]) if (sign[e.x] == 0) {
		sign[e.x] = -sign[v];
		val[e.x] = e.y - val[v];
		dfs(e.x);
	}
}

void solve(int root) {
	seen.clear();
	val[root] = 0;
	sign[root] = 1;
	dfs(root);

	bool odd = 0;
	int kek = 0;

	each(v, seen) {
		each(e, G[v]) {
			if (sign[v] == sign[e.x]) {
				int alt = e.y - val[v] - val[e.x];
				if (sign[v] == -1) alt *= -1;

				if (odd && kek != alt) {
					cout << "NO\n";
					exit(0);
				}

				odd = 1;
				kek = alt;
			} else {
				if (val[v] + val[e.x] != e.y) {
					cout << "NO\n";
					exit(0);
				}
			}
		}
	}

	dbl ans = 0;

	if (odd) {
		ans = dbl(kek) / 2;
	} else {
		vector<pair<ll, Pll>> events;
		Pll cur = {0, 0};

		each(i, seen) {
			ll s = sign[i], v = val[i];
			cur.x--;
			cur.y += -s*v;
			events.pb({ -s*v, {2, 2*s*v} });
		}

		dbl best = 1e30;
		sort(all(events));

		each(e, events) {
			cur.x += e.y.x;
			cur.y += e.y.y;
			dbl alt = dbl(cur.x*e.x + cur.y);
			if (alt < best) {
				best = alt;
				ans = dbl(e.x);
			}
		}
	}

	each(v, seen) {
		result[v] = ans*sign[v] + val[v];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(1);
	cin >> n >> m;
	G.resize(n);

	rep(i, 0, m) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a].pb({b, c});
		G[b].pb({a, c});
	}

	val.resize(n);
	sign.resize(n);
	result.resize(n);

	rep(i, 0, n) {
		if (sign[i] == 0) {
			solve(i);
		}
	}

	cout << "YES\n";
	each(a, result) cout << a << ' ';
	cout << '\n';
	return 0;
}