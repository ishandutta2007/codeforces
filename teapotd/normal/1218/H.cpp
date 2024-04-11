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

struct Fenwick {
	Vi s;
	Fenwick(int n = 0) : s(n, 0) {}
	void modify(int i, int v) { for (; i < sz(s); i |= i+1) s[i] += v; }
	int query(int i) {
		int v = 0;
		for (; i > 0; i &= i-1) v += s[i-1];
		return v;
	}
};

vector<Vi> G;
Vi nxt, seen, ans;
vector<vector<pair<ll, int>>> queries;
int tot;

vector<Fenwick> rests;
int add;
Vi kek;

void upd(int i, int k) {
	i -= add;
	int r = i % sz(rests);
	int d = i / sz(rests);
	rests[r].modify(d, k);
}

int query(int dist) {
	dist -= add;
	int r = dist % sz(rests);
	int d = dist / sz(rests);
	return rests[r].query(d+1);
}

void dfs(int v, int d) {
	if (seen[v] != 2) {
		each(q, queries[v]) {
			ll s = q.x + d;
			if (s < sz(kek)) ans[q.y] -= kek[s];
		}
	}

	kek[d]++;
	tot++;

	each(e, G[v]) {
		if (seen[e] == 2) continue;
		seen[e] = 3;
		dfs(e, d+1);
	}

	if (seen[v] != 2) {
		each(q, queries[v]) {
			ll s = q.x + d;
			if (s < sz(kek)) ans[q.y] += kek[s];
		}
	}
}

void dfsCount(int v, int d, int m) {
	upd(d, m);
	each(e, G[v]) {
		if (seen[e] == 2) continue;
		dfsCount(e, d+1, m);
	}
}

void process(int root) {
	Vi cycle;
	while (seen[root] != 2) {
		cycle.pb(root);
		seen[root] = 2;
		root = nxt[root];
	}

	tot = 0;
	each(v, cycle) {
		dfs(v, 0);
	}

	int lim = tot*3 + 3;
	lim = lim/sz(cycle) + 2;
	add = 0;
	rests.resize(sz(cycle));
	reverse(all(cycle));

	each(r, rests) {
		r = {lim};
	}

	rep(i, 0, sz(cycle)) {
		dfsCount(cycle[i], i, 1);
	}

	rep(i, 0, sz(cycle)) {
		each(q, queries[cycle[i]]) {
			ll tmp = q.x;
			if (tmp > tot*2) {
				tmp = (tmp-tot*2) % sz(cycle) + tot*2;
			}
			ans[q.y] = query(int(tmp));
		}

		dfsCount(cycle[i], 0, -1);
		add--;
		dfsCount(cycle[i], sz(cycle)-1, 1);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

	int n; cin >> n;
	nxt.resize(n);
	G.resize(n);
	queries.resize(n);
	kek.resize(n+5);

	rep(i, 0, n) {
		cin >> nxt[i];
		nxt[i]--;
		G[nxt[i]].pb(i);
	}

	int q; cin >> q;

	rep(i, 0, q) {
		ll m;
		int y;
		cin >> m >> y;
		y--;
		queries[y].pb({m, i});
	}

	seen.resize(n);
	ans.resize(q);

	rep(i, 0, n) {
		if (seen[i]) continue;
		int v = i;
		while (!seen[v]) {
			seen[v] = 1;
			v = nxt[v];
		}
		process(v);
	}

	each(a, ans) {
		cout << a << '\n';
	}
}