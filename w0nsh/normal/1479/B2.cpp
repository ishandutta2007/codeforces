#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
constexpr int INF = 1000000666;
struct Tree{
	int BOTTOM;
	VI t, u;

	void upd(int v){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = VI(BOTTOM*2);
		u = VI(BOTTOM*2);
	}

	void add(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), w, (v<<1), lo, mid);
		add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}

	
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return -INF;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::max(
		query(a, std::min(b, mid), (v<<1), lo, mid),
		query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

Tree tree;
void wyjeb(int v){
	tree.add(v, v, -INF);
}

void wracaj(int v){
	tree.add(v, v, INF);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	tree.build(n+5);

	REP(i, 1, n+1) tree.add(i, i, -INF);

	REP(i, 1, n){
		if(A[i] != A[i-1]){
			tree.add(A[i], A[i], 1);
			int mx = tree.query(0, n);
			tree.add(A[i], A[i], -1);
			int co = tree.query(A[i-1], A[i-1]);
			int delt = std::max(co, mx) - co;
			tree.add(A[i-1], A[i-1], delt);
		}else{
			tree.add(A[i], A[i], 1);
			int mx = tree.query(0, n);
			tree.add(A[i], A[i], -1);
			tree.add(0, n, 1); // ok?
			int co = tree.query(A[i], A[i]);
			int delt = std::max(co, mx) - co;
			tree.add(A[i], A[i], delt);
		}
	}
	
	std::cout << n - tree.query(0, n) << "\n";

	return 0;
}