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

struct Tree{
	int BOTTOM;
	VI t, u;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2, -1);
		u.resize(BOTTOM*2);
	}
	void upd(int v){
		if(u[v] != 0){
			t[v] = u[v];
			if(v < BOTTOM){
				u[v<<1] = u[v];
				u[(v<<1)+1] = u[v];
			}
			u[v] = 0;
		}
	}
	void set(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] = w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		set(a, std::min(b, mid), w, v<<1, lo, mid);
		set(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		if(t[v<<1] == -1 || t[(v<<1)+1] == -1) t[v] = -1;
		else t[v] = 1;
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return 1;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		int l = query(a, std::min(b, mid), v<<1, lo, mid);
		int r = query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		// std::cout << "(" << a << "," << b << ") " << l << " " << r << std::endl;
		if(l == -1 || r == -1) return -1;
		return 1;
	}
};


int n;
std::vector<PII> ord;
std::vector<VI> g;
VI pr;
Tree tree;

int tick;
void dfs(int v, int par=-1){
	ord[v].X = tick++;
	pr[v] = par;
	TRAV(ch, g[v]) if(ch != par) dfs(ch, v);
	ord[v].Y = tick++;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	pr.resize(n, -1);
	ord.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	tree.build(2*n);
	int q;
	std::cin >> q;
	while(q--){
		int w, a;
		std::cin >> w >> a;
		a--;
		if(w == 1){
			if(tree.query(ord[a].X, ord[a].Y) == -1 && pr[a] != -1){
				tree.set(ord[pr[a]].X, ord[pr[a]].X, -1); 
				tree.set(ord[pr[a]].Y, ord[pr[a]].Y, -1); 
			}
			tree.set(ord[a].X, ord[a].Y, 1);
		}else if(w == 2){
			tree.set(ord[a].X, ord[a].X, -1);
			tree.set(ord[a].Y, ord[a].Y, -1);
		}else{
			std::cout << (tree.query(ord[a].X, ord[a].Y)+1)/2 << "\n";
		}
	}


	return 0;
}