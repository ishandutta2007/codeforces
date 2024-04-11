#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const int INF = 2000000000;

int n, q;
std::vector<VI> g;
VI level, parent, lvec, which, fst, lst;

struct Tree{
	int BOTTOM;
	VI t, vec;
	inline int left(int a){
		return a<<1;
	}
	inline int right(int a){
		return (a<<1)+1;
	}
	inline int parent(int a){
		return a>>1;
	}
	void prop(int v){
		if(v >= BOTTOM) return;
		prop(left(v));
		prop(right(v));
		if(vec[t[left(v)]] < vec[t[right(v)]]) t[v] = t[left(v)];
		else t[v] = t[right(v)];
	}
	void build(int size, VI vc){
		vec = vc;
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		t.resize(BOTTOM*2);
		FOR(i, size) t[i+BOTTOM] = i;
		REP(i, size, BOTTOM) t[i+BOTTOM] = -1;
		prop(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return -1;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		int l = query(a, std::min(b, mid), left(v), lo, mid);
		int r = query(std::max(a, mid+1), b, right(v), mid+1, hi);
		if(r == -1) return l;
		if(l == -1) return r;
		if(vec[l] < vec[r]) return l;
		return r;
	}
};
struct MaxTree{
	int BOTTOM;
	VI t, vec;
	inline int left(int a){
		return a<<1;
	}
	inline int right(int a){
		return (a<<1)+1;
	}
	inline int parent(int a){
		return a>>1;
	}
	void prop(int v){
		if(v >= BOTTOM) return;
		prop(left(v));
		prop(right(v));
		if(vec[t[left(v)]] > vec[t[right(v)]]) t[v] = t[left(v)];
		else t[v] = t[right(v)];
	}
	void build(int size, VI vc){
		vec = vc;
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		t.resize(BOTTOM*2);
		FOR(i, size) t[i+BOTTOM] = i;
		REP(i, size, BOTTOM) t[i+BOTTOM] = -1;
		prop(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return -1;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		int l = query(a, std::min(b, mid), left(v), lo, mid);
		int r = query(std::max(a, mid+1), b, right(v), mid+1, hi);
		if(r == -1) return l;
		if(l == -1) return r;
		if(vec[l] > vec[r]) return l;
		return r;
	}
};


void dfs0(int v, int lev){
	level[v] = lev;
	fst[v] = SZ(lvec);
	lst[v] = SZ(lvec);
	lvec.push_back(lev);
	which.push_back(v);
	TRAV(ch, g[v]) if(ch != parent[v]){
		dfs0(ch, lev+1);
		lst[v] = SZ(lvec);
		lvec.push_back(lev);
		which.push_back(v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	g.resize(n);
	parent.resize(n);
	level.resize(n);
	fst.resize(n, -1);
	lst.resize(n, -1);
	parent[0] = -1;
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		parent[i+1] = a;
		g[a].push_back(i+1);
		g[i+1].push_back(a);
	}
	dfs0(0, 0);
	Tree tree;
	tree.build(SZ(lvec), lvec);
	Tree ltree;
	MaxTree rtree;
	ltree.build(SZ(fst), fst);
	rtree.build(SZ(lst), lst);
	while(q--){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(b - a == 1){
			if(level[a] > level[b]) std::swap(a, b);
			std::cout << a+1 << " " << level[b] << "\n";
			continue;
		}
		// std::cout << lvec[tree.query(std::min(fst[a], fst[b]), std::max(lst[b], lst[a]))] << std::endl;
		// continue;
		int leftmost = ltree.query(a, b);
		int rightmost = rtree.query(a, b);
		int l = ltree.query(a, leftmost-1);
		int r = ltree.query(leftmost+1, b);
		int next_leftmost;
		if(l == -1) next_leftmost = r;
		else if(r == -1) next_leftmost = l;
		else if(fst[l] > fst[r]) next_leftmost = r;
		else next_leftmost = l;
		l = rtree.query(a, rightmost-1);
		r = rtree.query(rightmost+1, b);
		int next_rightmost;
		if(l == -1) next_rightmost = r;
		else if(r == -1) next_rightmost = l;
		else if(lst[l] < lst[r]) next_rightmost = r;
		else next_rightmost = l;
		int x1 = lvec[tree.query(std::min(fst[leftmost], fst[next_rightmost]), std::max(lst[next_rightmost], lst[leftmost]))];
		int x2 = lvec[tree.query(std::min(fst[next_leftmost], fst[rightmost]), std::max(lst[next_leftmost], lst[rightmost]))];
		// std::cout << "wyjeb " << leftmost+1 << " or " << rightmost+1 << std::endl;
		// std::cout << "next " << next_leftmost+1 << " or " << next_rightmost+1 << std::endl;
		// std::cout << "cand " << x2 << " or " << x1 << std::endl;
		if(leftmost == rightmost) std::cout << leftmost+1 << " " << lvec[tree.query(std::min(fst[next_leftmost], fst[next_rightmost]), std::max(lst[next_leftmost], lst[next_rightmost]))] << "\n";
		else if(x1 > x2)
			std::cout << rightmost+1 << " " << x1 << "\n";
		else
			std::cout << leftmost+1 << " " << x2 << "\n";
		// if(fst[a] > fst[b]) std::swap(a, b);
		// std::cout << which[tree.query(fst[a], lst[b])] + 1 << std::endl;
	}
	return 0;
}