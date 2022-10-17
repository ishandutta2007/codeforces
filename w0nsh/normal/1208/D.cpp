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
typedef std::pair<ll, int> PLL;
const ll INF = 200000066000006;

struct MinTree{
	int BOTTOM, DEPTH;
	std::vector<PLL> t;
	std::vector<ll> u;
	static inline int left(int a){return a<<1;}
	static inline int right(int a){return (a<<1)+1;}
	static inline int parent(int a){return a>>1;}
	void build(std::vector<ll> ar){
		int size = SZ(ar);
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM *= 2;
		}
		t.resize(BOTTOM*2, MP(INF, 1));
		u.resize(BOTTOM*2);
		FOR(i, SZ(ar)) t[BOTTOM+i] = MP(ar[i], -i);
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::min(t[i<<1], t[(i<<1)+1]);
	}
	void upd(int v){
		if(u[v] != 0){
			t[v].X += u[v];
			if(v < BOTTOM){
				u[left(v)] += u[v];
				u[right(v)] += u[v];
			}
			u[v] = 0;
		}
	}
	PLL query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return MP(INF, 1);
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), left(v), lo, mid),
						query(std::max(a, mid+1), b, right(v), mid+1, hi));
	}
	void update(int a, int b, ll val, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), val, left(v), lo, mid);
		update(std::max(a, mid+1), b, val, right(v), mid+1, hi);
		t[v] = std::min(t[left(v)], t[right(v)]);
	}
};


int n;
std::vector<ll> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	MinTree tree;
	tree.build(A);
	VI ans(n);
	FOR(i, n){
		PLL asd = tree.query(0, n-1);
		int xd = -asd.Y;
		assert(asd.X == 0);
		ans[xd] = i;
		if(xd != n-1) tree.update(xd+1, n-1, -i-1);
		tree.update(xd, xd, INF);
	}
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}