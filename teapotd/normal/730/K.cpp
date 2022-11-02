#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct Treap {
	struct Node {
		int E[2] = {-1, -1}, weight{rand()};
		int size{1}, par{-1};
	};

	vector<Node> G;

	// Initialize structure for n nodes; O(n)
	// Each node is separate treap,
	// use join() to construct sequence.
	Treap(int n = 0) { init(n); }
	void init(int n) { G.clear(); G.resize(n); }

	int size(int x) { // Returns subtree size
		return (x >= 0 ? G[x].size : 0);
	}

	void push(int) { // Propagates down stuff
	}

	void update(int x) { // Updates aggregates
		if (x >= 0) {
			G[x].par = -1;
			int& s = G[x].size = 1;
			each(e, G[x].E) if (e >= 0) {
				s += size(e);
				G[e].par = x;
			}
		} // + any other aggregates
	}

	// Split treap x by index i into l and r
	// average time: O(lg n)
	void split(int x, int& l, int& r, int i) {
		push(x); l = r = -1;
		if (x < 0) return;
		int key = size(G[x].E[0]);
		if (i <= key) {
			split(G[x].E[0], l, G[x].E[0], i);
			r = x;
		} else {
			split(G[x].E[1], G[x].E[1], r, i-key-1);
			l = x;
		}
		update(x);
	}

	// Join two treaps in given order; O(lg n)
	int join(int l, int r) {
		push(l); push(r);
		if (l < 0 || r < 0) return max(l, r);

		if (G[l].weight < G[r].weight) {
			G[l].E[1] = join(G[l].E[1], r);
			update(l);
			return l;
		}

		G[r].E[0] = join(l, G[r].E[0]);
		update(r);
		return r;
	}

	// Find node with index i in treap x; O(lg n)
	int find(int x, int i) {
		while (x >= 0) {
			push(x);
			int key = size(G[x].E[0]);
			if (key == i) return x;
			x = G[x].E[key < i];
			if (key < i) i -= key+1;
		}
		return x;
	}

	int index(int x) {
		int prev = -2, i = 0;
		while (x != -1) {
			if (G[x].E[0] != prev) i += size(G[x].E[0])+1;
			prev = x;
			x = G[x].par;
		}
		return i-1;
	}
};

struct Vert {
	Vi E, forward, back;
	bool visited{0}, merged{0}, onPath{0}, processed{0};
	int par{-1}, in{0}, out{0};
};

int n, m, s, t;
vector<Vert> G;
vector<Pii> ans;
Treap topo;
int topoRoot;

void dfs(int i) {
	G[i].visited = G[i].onPath = 1;

	each(e, G[i].E) if (e != G[i].par) {
		if (G[e].visited) {
			if (G[e].onPath) G[e].back.pb(i);
		} else {
			G[i].forward.pb(e);
			G[e].par = i;
			dfs(e);
		}
	}

	G[i].onPath = 0;
}

void direct(int i, int src) {
	int finish = G[i].par;
	while (finish != -1 && !G[finish].merged) {
		finish = G[finish].par;
	}

	bool rev = (topo.index(finish) < topo.index(src));
	int tree = -1;

	while (i != finish) {
		G[i].merged = 1;
		if (rev) tree = topo.join(i, tree);
		else tree = topo.join(tree, i);
		i = G[i].par;
	}

	int L, R, index = topo.index(finish);
	topo.split(topoRoot, L, R, index+rev);
	L = topo.join(L, tree);
	topoRoot = topo.join(L, R);
}

bool solve() {
	cin >> n >> m >> s >> t;
	s--; t--;

	G.assign(n, {});
	ans.clear();
	topo.init(n);
	topoRoot = -1;

	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].E.pb(b);
		G[b].E.pb(a);
	}

	dfs(s);
	if (!G[t].visited) return false;

	direct(t, t);
	queue<int> que;
	que.push(s);

	while (!que.empty()) {
		int i = que.front();
		que.pop();
		if (G[i].processed) continue;
		G[i].processed = 1;

		each(e, G[i].back) {
			if (!G[e].merged) direct(e, i);
		}
		each(e, G[i].forward) que.push(e);
	}

	rep(i, 0, n) {
		each(e, G[i].E) {
			if (topo.index(i) < topo.index(e)) {
				ans.pb({ i, e });
				G[i].out++;
				G[e].in++;
			}
		}
	}

	if (G[s].in != 0 || G[t].out != 0) return false;

	rep(i, 0, n) if (i != s && i != t) {
		if (G[i].in == 0 || G[i].out == 0) return false;
	}

	return true;
}

void run() {
	int k; cin >> k;

	while (k--) {
		if (solve()) {
			cout << "Yes\n";
			each(p, ans) cout << p.x+1 << ' ' << p.y+1 << '\n';
		} else {
			cout << "No\n";
		}
	}
}