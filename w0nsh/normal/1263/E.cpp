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

struct Tree{
	int BOTTOM;
	VI mn, mx, u;
	void build(int a){
		BOTTOM = 1;
		while(BOTTOM < a) BOTTOM *= 2;
		mn.resize(BOTTOM*2);
		mx.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
	}
	void upd(int v){
		if(u[v] != 0){
			mn[v] += u[v];
			mx[v] += u[v];
			if(v < BOTTOM){
				u[v<<1] += u[v];
				u[(v<<1)+1] += u[v];
			}
			u[v] = 0;
		}
	}
	int min(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return INF;
		if(a == lo && b == hi) return mn[v];
		int mid = (lo+hi)/2;
		return std::min(min(a, std::min(b, mid), v<<1, lo, mid),
					min(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}

	int max(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return -INF;
		if(a == lo && b == hi) return mx[v];
		int mid = (lo+hi)/2;
		return std::max(max(a, std::min(b, mid), v<<1, lo, mid),
					max(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void update(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), w, v<<1, lo, mid);
		update(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		mn[v] = std::min(mn[v<<1], mn[(v<<1)+1]);
		mx[v] = std::max(mx[v<<1], mx[(v<<1)+1]);
	}
};


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	Tree tree;
	tree.build(n);
	int pos = 0;
	int sum = 0;
	FOR(i, n){
		char a;
		std::cin >> a;
		if(a == 'L') pos = std::max(0, pos-1);
		else if(a == 'R') pos++;
		else if(a == '('){
			tree.update(pos, n-1, -A[pos]+1);
			sum -= A[pos];
			A[pos] = 1;
			sum += A[pos];
		}else if(a == ')'){
			sum -= A[pos];
			tree.update(pos, n-1, -A[pos]-1);
			A[pos] = -1;
			sum += A[pos];
		}else{
			sum -= A[pos];
			tree.update(pos, n-1, -A[pos]);
			A[pos] = 0;
		}
		if(tree.min(0, n-1) < 0 || sum != 0) std::cout << -1  << " ";
		else{
			std::cout << tree.max(0, n-1) << " ";
		}
	}
	return 0;
}