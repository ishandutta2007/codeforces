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


const int INF = 1000000666;

struct MinTree{
	int BOTTOM, DEPTH;
	VI t, u;
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
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
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
	void update(int a, int b, int val, int v=1, int lo=0, int hi=-2){
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


int n, m;
VI A, B;
const int N = 1000002;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	B.resize(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	VI pref(1000005);
	FOR(i, n) pref[A[i]]--;
	FOR(i, m) pref[B[i]]++;
	for(int i = N-1; i >= 0; --i) pref[i] = pref[i+1] + pref[i];
	MinTree tree;
	tree.build(1000005);
	FOR(i, N) tree.update(i, i, pref[i]);
	int q;
	std::cin >> q;
	FOR(_, q){
		int what;
		std::cin >> what;
		int a, b;
		std::cin >> a >> b;
		a--;
		if(what == 1){
			tree.update(0, b, -1);
			tree.update(0, A[a], 1);
			A[a] = b;
		}else{
			tree.update(0, b, 1);
			tree.update(0, B[a], -1);
			B[a] = b;
		}
		int left = 0;
		int right = N;
		while(left < right){
			int mid = (left+right)/2;
			if(tree.query(mid, N) < 0) left = mid+1;
			else right = mid;
		}
		if(left == 0) std::cout << -1 << "\n";
		else std::cout << left-1 << "\n";
	}
	return 0;
}