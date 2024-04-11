#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int INF = 1000000666;

struct Tree{
	int BOTTOM;
	VI t, u;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = VI(BOTTOM*2);
		u = VI(BOTTOM*2);
	}

	void upd(int v){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}

	void add(int a, int b, int val, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), val, v<<1, lo, mid);
		add(std::max(a, mid+1), b, val, (v<<1)+1, mid+1, hi);
		t[v] = std::min(t[v<<1], t[(v<<1)+1]);
	}

	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi= BOTTOM-1;
		upd(v);
		if(a>b) return INF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
			query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

template<class T>
struct BIT{
	std::vector<T> t;
	inline int LSB(int a){ return a&(-a); }
	BIT(){}
	BIT(int sz){ t.resize(sz+1); }
	void add(int x, T val){
		x++;
		while(x < (int)t.size()) t[x] += val, x += LSB(x); // change operation here
	}
	T query(int x){
		x++;
		T r = 0;
		while(x > 0) r += t[x], x -= LSB(x); // change operation here
		return r;
	}
};

ll cnt_inv(const VI& A, int mx){
	BIT<int> bit(mx);
	ll ret = 0;
	int all = 0;
	TRAV(i, A){
		ret += all - bit.query(i);
		bit.add(i, 1);
		all++;
	}

	return ret;
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	VI B(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];

	VI vals;
	TRAV(i, A) vals.push_back(i);
	std::sort(vals.begin(), vals.end());
	vals.resize(std::unique(vals.begin(), vals.end()) - vals.begin());
	VI C;
	C.reserve(n);
	TRAV(i, A) C.push_back(2 + (int)(std::lower_bound(vals.begin(), vals.end(), i) - vals.begin()));

	ll ans = cnt_inv(C, SZ(vals)+10);

	Tree tree;
	tree.build(n+1);
	std::vector<PII> heh(2*n);
	std::vector<bool> was(n);
	FOR(i, n){
		heh[2*i] = MP(A[i], i);
		heh[2*i+1] = MP(A[i]+1, i);

		tree.add(i+1, n, 1);
	}

	std::sort(heh.begin(), heh.end());
	std::sort(B.begin(), B.end());
	auto it = heh.begin();
	TRAV(i, B){
		while(it != heh.end() && it->X <= i){
			int v = it->Y;
			if(was[v]){
				tree.add(0, v, 1);
			}else{
				was[v] = true;
				tree.add(v+1, n, -1);
			}
			it++;
		}

		ans += tree.query(0, n);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}