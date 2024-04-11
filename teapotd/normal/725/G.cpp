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

struct SegmentTree {
	using T = int;
	static constexpr T ID = INT_MIN;

	struct Node {
		T extra{ID}; // Lazy propagated value
		T great{INT_MIN};

		// Initialize node with default value x
		void init(T x, int) {
			great = x;
		}

		// Merge with node R on the right
		void merge(const Node& R) {
			great = max(great, R.great);
		}

		// Apply modification to node, return
		// value to be applied to node on right
		T apply(T x, int begin, int size) {
			extra = max(extra, x);
			great = max(great, x + (begin+size-1)*2);
			return x;
		}
	};

	vector<Node> V;
	int len;

	SegmentTree(int n=0, T def=ID) {init(n,def);}

	void init(int n, T def) {
		for (len = 1; len < n; len *= 2);

		V.assign(len*2, {});
		rep(i, len, len+n) V[i].init(def, 1);
		for (int i = len-1; i > 0; i--) update(i);
	}

	int getChild(int i, int j) { return i*2+j; }
	int L(int i) { return getChild(i, 0); }
	int R(int i) { return getChild(i, 1); }

	void update(int i) {
		int a = L(i), b = R(i);
		V[i] = {};
		V[i].merge(V[a]);
		V[i].merge(V[b]);
	}

	void push(int i, int begin, int size) {
		int e = V[i].extra;
		if (e != ID) {
			e = V[L(i)].apply(e, begin, size/2);
			V[R(i)].apply(e, begin+size/2, size/2);
			V[i].extra = ID;
		}
	}

	// Modify [vBegin;end) with x; time: O(lg n)
	T modify(int vBegin, int vEnd, T x,
	         int i = 1,
	         int begin = 0, int end = -1) {
		if (end < 0) end = len;
		if (vEnd <= begin || end <= vBegin)
			return x;

		if (vBegin <= begin && end <= vEnd) {
			return V[i].apply(x, begin, end-begin);
		}

		int mid = (begin + end) / 2;
		push(i, begin, end-begin);
		x = modify(vBegin,vEnd,x,L(i),begin,mid);
		x = modify(vBegin,vEnd,x,R(i),mid,end);
		update(i);
		return x;
	}

	// Query [vBegin;vEnd); time: O(lg n)
	// Returns base nodes merged together
	Node query(int vBegin, int vEnd, int i = 1,
	           int begin = 0, int end = -1) {
		if (end < 0) end = len;
		if (vEnd <= begin || end <= vBegin)
			return {};
		if (vBegin <= begin && end <= vEnd)
			return V[i];

		int mid = (begin + end) / 2;
		push(i, begin, end-begin);
		Node x = query(vBegin,vEnd,L(i),begin,mid);
		x.merge(query(vBegin,vEnd,R(i),mid,end));
		return x;
	}

	int search(int vBegin, int vEnd, int value, int i = 1, int begin = 0, int end = -1) {
		if (end < 0) end = len;
		if (vEnd <= begin || end <= vBegin)
			return begin;

		if (vBegin <= begin && end <= vEnd) {
			if (V[i].great < value) return begin;
			if (begin+1 == end) return end;
		}

		int mid = (begin+end) / 2;
		push(i, begin, end-begin);

		int ind = search(vBegin, vEnd, value, R(i), mid, end);
		if (ind > mid) return ind;
		return search(vBegin, vEnd, value, L(i), begin, mid);
	}
};

// ---

constexpr int INF = 1.6e9;

struct Vert {
	Vi E;
	int parent, size, depth, chain, chainPos;
	DBP(E, parent, size, depth, chain, chainPos);
};

struct Chain {
	Vi verts;
	SegmentTree tree;
	DBP(verts);
};

struct Query {
	int from, time, ans;
	DBP(from, time, ans);
};

vector<Vert> G;
vector<Chain> chains;
vector<Query> queries;

void hld(int i, int parent = -1, int d = 0) {
	int h = -1;
	G[i].parent = parent;
	G[i].depth = d;
	G[i].size = 1;

	each(e, G[i].E) if (e != parent) {
		hld(e, i, d+1);
		G[i].size += G[e].size;
		if (h < 0 || G[h].size < G[e].size) h = e;
	}

	if (h < 0) {
		h = sz(chains);
		chains.emplace_back();
	} else {
		h = G[h].chain;
	}
	chains[h].verts.pb(i);
	G[i].chain = h;

	if (parent < 0) {
		each(p, chains) {
			reverse(all(p.verts));
			rep(j, 0, sz(p.verts))
				G[p.verts[j]].chainPos = j;

			p.tree.init(sz(p.verts), 0);
		}
	}
}

int rootTime(Query& q) {
	return q.time + G[q.from].depth;
}

void handle(Query& q) {
	int to = q.from;
	int t = rootTime(q);

	while (true) {
		auto& chain = chains[G[to].chain];
		int i = chain.tree.search(0, G[to].chainPos+1, t);

		if (i > 0) {
			to = chain.verts[i-1];
			break;
		}

		to = G[chain.verts[0]].parent;
	}
	
	q.ans = q.time + (G[q.from].depth-G[to].depth)*2;

	int v = q.from;
	t = q.time + G[q.from].depth - G[to].depth;

	while (true) {
		auto& chain = chains[G[v].chain];
		bool finalChain = (G[to].chain == G[v].chain);

		int begin = (finalChain ? G[to].chainPos+1 : 0);
		int end = G[v].chainPos+1;

		if (begin < end) {
			int time = t + 2*G[chain.verts[0]].depth - G[to].depth;
			chain.tree.modify(begin, end, time-1);
		}

		if (finalChain) break;
		v = G[chain.verts[0]].parent;
	}
}

void solve() {
	hld(0);

	Vi sorted(sz(queries));
	iota(all(sorted), 0);
	sort(all(sorted), [](int l, int r) {
		return mp(rootTime(queries[l]), queries[l].from) < mp(rootTime(queries[r]), queries[r].from);
	});

	chains[G[0].chain].tree.modify(0, 1, INF);

	each(i, sorted) handle(queries[i]);
}

void run() {
	int n, m; cin >> n >> m;
	n++;
	G.resize(n);

	rep(i, 1, n) {
		int j; cin >> j;
		G[i].E.pb(j);
		G[j].E.pb(i);
	}

	queries.resize(m);
	each(q, queries) cin >> q.from >> q.time;

	solve();

	each(q, queries) cout << q.ans << ' ';
	cout << endl;
}