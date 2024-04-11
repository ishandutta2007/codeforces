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

constexpr int INF = 1e6;

struct Match {
	int from, to, nxt1, nxt2;
};

struct StateClose {
	int len, head;
	bool operator<(const StateClose& r) const {
		return len < r.len;
	}
};

struct StateOpen {
	int len, head, in, out;
	bool operator<(const StateOpen& r) const {
		return len < r.len;
	}
};

vector<Vi> G;
vector<StateClose> close;
vector<StateOpen> open;
vector<Match> matches;
Vi ans;

StateClose merge(StateClose a, StateClose b) {
	matches.pb({ -1, -1, a.head, b.head });
	return { a.len+b.len, sz(matches)-1 };
}

StateOpen merge(StateClose a, StateOpen b) {
	matches.pb({ -1, -1, a.head, b.head });
	return { a.len+b.len, sz(matches)-1, b.in, b.out };
}

StateClose merge(StateOpen a, StateOpen b) {
	matches.pb({ b.out, a.in, a.head, b.head });
	matches.pb({ a.out, b.in, sz(matches)-1, -1 });
	return { a.len+b.len, sz(matches)-1 };
}

StateOpen mergeOpen(StateOpen a, StateOpen b) {
	matches.pb({ b.out, a.in, a.head, b.head });
	return { a.len+b.len, sz(matches)-1, b.in, a.out };
}

void dfs(int v, int p) {
	close[v].head = open[v].head = -1;
	close[v].len = INF;
	open[v].len = 0;
	open[v].in = open[v].out = v;

	each(e, G[v]) if (e != p) {
		dfs(e, v);

		StateClose c1 = merge(close[v], close[e]);
		StateClose c2 = merge(open[v], open[e]);
		StateOpen o1 = merge(close[v], open[e]);
		StateOpen o2 = merge(close[e], open[v]);
		StateOpen o3 = mergeOpen(open[v], open[e]);

		close[v] = min(c1, c2);
		open[v] = min(min(o1, o2), o3);
	}

	open[v].len += 2;
}

void collect(int v) {
	if (v == -1) return;
	auto& m = matches[v];
	if (m.from != -1) ans[m.from] = m.to;
	collect(m.nxt1);
	collect(m.nxt2);
}

int main() {
	int n; cin >> n;
	G.resize(n);

	rep(i, 1, n) {
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	close.resize(n);
	open.resize(n);
	dfs(0, -1);

	ans.resize(n);
	collect(close[0].head);

	cout << close[0].len << '\n';
	each(i, ans) cout << i+1 << ' ';
	cout << '\n';
	return 0;
}