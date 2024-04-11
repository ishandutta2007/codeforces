#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


const ll INF = 1000000000ll*100000000ll;

struct MinTree{
	int BOTTOM, DEPTH;
	std::vector<ll> t, u;
	static inline int left(int a){return a<<1;}
	static inline int right(int a){return (a<<1)+1;}
	static inline int parent(int a){return a>>1;}
	void build(int size){
		BOTTOM = 1;
		DEPTH = 0;
		while(BOTTOM < size){
			BOTTOM *= 2;
			DEPTH++;
		}
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
	}
	void upd(int v){
		if(u[v] != 0){
			t[v] += u[v];
			if(v < BOTTOM){
				u[left(v)] += u[v];
				u[right(v)] += u[v];
			}
			u[v] = 0;
		}
	}
	ll query(int a, int b, ll v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return INF;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), left(v), lo, mid),
						query(std::max(a, mid+1), b, right(v), mid+1, hi));
	}
	void add(int a, int b, ll val, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), val, left(v), lo, mid);
		add(std::max(a, mid+1), b, val, right(v), mid+1, hi);
		t[v] = std::min(t[left(v)], t[right(v)]);
	}
};

int n;
std::vector<std::vector<PII> > g;
std::vector<std::vector<PR<PII, int> > > queries;
VI parent, leaves;
std::vector<ll> ans;
MinTree tree;

// up = n-1
void dfs(int v, int up){
	TRAV(q, queries[v]) ans[q.Y] = tree.query(q.X.X, q.X.Y);
	FOR(i, SZ(g[v])){
		int ch = g[v][i].X;
		int w = g[v][i].Y;
		int r = (i == SZ(g[v])-1 ? up : g[v][i+1].X-1);
		int lf = std::distance(leaves.begin(), std::lower_bound(leaves.begin(), leaves.end(), ch));
		int rg = std::distance(leaves.begin(), --std::upper_bound(leaves.begin(), leaves.end(), r));
		tree.add(lf, rg, -w);
		if(lf > 0) tree.add(0, lf-1, w);
		if(rg < SZ(leaves)-1) tree.add(rg+1, SZ(leaves)-1, w);
		dfs(ch, r);
		tree.add(lf, rg, w);
		if(lf > 0) tree.add(0, lf-1, -w);
		if(rg < SZ(leaves)-1) tree.add(rg+1, SZ(leaves)-1, -w);
	}
}

int kt=0;
void dfsinit(int v, ll dist){
	if(SZ(g[v]) == 0) tree.add(kt, kt, dist), kt++;
	TRAV(ch, g[v]) dfsinit(ch.X, dist+ch.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> n >> q;
	parent.resize(n, -1);
	g.resize(n);
	queries.resize(n);
	std::set<int> lset;
	FOR(i, n-1){
		int a, w;
		std::cin >> a >> w;
		a--;
		g[a].push_back(MP(i+1, w));
		parent[i+1] = a;
		lset.erase(a);
		lset.insert(i+1);
	}
	TRAV(i, lset) leaves.push_back(i);		
	tree.build(SZ(leaves));
	ans.resize(q);
	FOR(i, q){
		int a, l, r;
		std::cin >> a >> l >> r;
		a--;l--;r--;
		int lf = std::distance(leaves.begin(), std::lower_bound(leaves.begin(), leaves.end(), l));
		int rg = std::distance(leaves.begin(), --std::upper_bound(leaves.begin(), leaves.end(), r));
		queries[a].push_back(MP(MP(lf, rg), i));
	}
	dfsinit(0, 0);
	dfs(0, n-1);
	TRAV(i, ans) std::cout << i << "\n";
	return 0;
}