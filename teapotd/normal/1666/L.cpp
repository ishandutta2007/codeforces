#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using Vi  = vector<int>;
using Pii = pair<int,int>;
#define mp make_pair
#define pb push_back
#define x  first
#define y  second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x)  for(auto& a : (x))
#define all(x)     (x).begin(),(x).end()
#define sz(x)      int((x).size())
#define tem template<class t,class u,class...w> auto
#define pri(x,y,z) tem operator<<(t&o,u a)->decltype(z,o) { o << *x; y; z; return o << x[1]; }
pri("{}",, a.print())
pri("()",, o << a.x << ", " << a.y)
pri("[]", auto d=""; for (auto i : a) (o << d << i, d = ", "), all(a))
void DD(...) {}
tem DD(t s, u a, w... k) {
    for (int b=1; cerr << *s++, *s && *s - b*44;) b += 2 / (*s*2 - 81);
    cerr << ": " << a; DD(s, k...);
}
#ifdef LOC
#define deb(...) DD("[,\b :] "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

int s;
vector<Vi> G;
Vi par, col, path1, path2;

bool dfs(int v, int p, int c) {
	if (col[v]) {
		if (col[v] != c) {
			for (int u = v; u != -1; u = par[u]) {
				path1.pb(u);
			}
			path2.pb(v);
			return 1;
		}
		return 0;
	}

	par[v] = p;
	col[v] = c;

	each(e, G[v]) if (e != s) {
		if (dfs(e, v, c)) {
			path2.pb(v);
			return 1;
		}
	}
	return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m >> s;
	G.resize(n);
	s--;

	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		G[u-1].pb(v-1);
	}

	par.resize(n, -1);
	col.resize(n, 0);

	rep(c, 0, sz(G[s])) {
		int v = G[s][c];
		deb(col, par);
		if (dfs(v, s, c+1)) {
			path2.pb(s);
			reverse(all(path1));
			reverse(all(path2));

			cout << "Possible\n";

			cout << sz(path1) << '\n';
			each(u, path1) cout << u+1 << ' ';
			cout << '\n';

			cout << sz(path2) << '\n';
			each(u, path2) cout << u+1 << ' ';
			cout << '\n';
			return 0;
		}
	}

	cout << "Impossible\n";
    return 0;
}