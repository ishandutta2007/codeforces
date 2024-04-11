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

int n;
ll len;
vector<Vi> G;
Vi siz, ans;
vector<vector<Pii>> open;

void dfs(int v, int p) {
	open[v] = { {v, v} };
	siz[v] = 1;

	each(e, G[v]) if (e != p) {
		dfs(e, v);
		siz[v] += siz[e];

		if (sz(open[v]) < sz(open[e])) {
			swap(open[v], open[e]);
		}

		int rest = n - siz[v];
		int tot = sz(open[v]) + sz(open[e]);

		while (tot-2 >= rest) {
			assert(!open[v].empty() && !open[e].empty());
			Pii a = open[v].back(), b = open[e].back();
			open[v].pop_back();
			open[e].pop_back();
			tot -= 2;
			ans[a.x] = b.y;
			ans[b.x] = a.y;
		}

		if (tot > rest) {
			assert(!open[v].empty() && !open[e].empty());
			Pii a = open[v].back(), b = open[e].back();
			open[v].pop_back();
			open[e].pop_back();
			ans[a.x] = b.y;
			open[v].pb({ b.x, a.y });
		}

		each(x, open[e]) {
			open[v].pb(x);
		}
	}

	len += min(siz[v], n-siz[v]);
}

int main() {
	cin >> n;
	G.resize(n);

	rep(i, 1, n) {
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	ans.resize(n, -1);
	siz.resize(n);
	open.resize(n);
	dfs(0, -1);

	cout << len*2 << '\n';
	each(a, ans) cout << a+1 << ' ';
	cout << '\n';
	return 0;
}