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

// implement:
//    merge(const T&, const T&) -> T
//    apply(T&, const U&)
//    compose(U&, const U&)
//    T(), U() ctors
//    (optionally) T(X) ctor 
//    (optionally) U(X) ctor

template<class T, class U>
class LazyTree {
public:
	LazyTree() {}
	LazyTree(int sz) {
		_init(sz);
		for (int i = size - 1; i >= 1; --i) t[i] = merge(t[i << 1], t[(i << 1) | 1]);
	}
	template<class X>
	LazyTree(const std::vector<X>& vec) {
		_init(vec.size());
		for (int i = 0; i < vec.size(); ++i) t[size + i] = T(vec[i]);
		for (int i = size - 1; i >= 1; --i) t[i] = merge(t[i << 1], t[(i << 1) | 1]);
	}

	template<class X>
	void update(int l, int r, X w) {
		auto upd = U(w);
		l += size; r += size;
		for (int i = h; i > 0; --i) _prop(l >> i), _prop(r >> i);
		for (int a = l, b = r + 1; a < b; a >>= 1, b >>= 1) {
			if (a & 1) _app(a++, upd);
			if (b & 1) _app(--b, upd);
		}
		for (int i = 1; i <= h; ++i) _calc(l >> i), _calc(r >> i);
	}

	T query(int l, int r) {
		l += size; r += size;
		for (int i = h; i > 0; --i) _prop(l >> i), _prop(r >> i);
		T lef, rig;
		for (int a = l, b = r + 1; a < b; a >>= 1, b >>= 1) {
			if (a & 1) lef = merge(lef, t[a++]);
			if (b & 1) rig = merge(t[--b], rig);
		}
		return merge(lef, rig);
	}

private:
	std::vector<T> t;
	std::vector<U> u;
	int size, h;

	void _init(int sz) {
		size = 1; while(size < sz) size *= 2;
		h = __builtin_ctz(size);
		t = std::vector<T>(size * 2);
		u = std::vector<U>(size * 2);
	}
	void _app(int v, const U& upd) { apply(t[v], upd); if (v < size) compose(u[v], upd); }
	void _prop(int v) { _app(v << 1, u[v]); _app((v << 1) | 1, u[v]); u[v] = U(); }
	void _calc(int v) { t[v] = merge(t[v << 1], t[(v << 1) | 1]); apply(t[v], u[v]); }
};

constexpr ll INF = 1000000000ll*1000000000ll;
struct T {
	ll val;
	T(): val(INF) {}
	T(ll x): val(x) {}
};
struct U {
	ll dod;
	U(): dod(0) {}
	U(ll x): dod(x) {}
};
T merge(const T& a, const T& b) {
	return T(std::min(a.val, b.val));
}
void compose(U& u, const U& up) {
	u.dod += up.dod;
}
void apply(T& t, const U& u) {
	t.val += u.dod;
}



int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	auto tree = LazyTree<T, U>(A);
	int m;
	std::cin >> m;
	std::string query;
	std::getline(std::cin, query);
	FOR(_, m){
		std::getline(std::cin, query);
		std::stringstream ss(query);
		int a, b;
		ss >> a >> b;
		// std::cout << ss.eof() << std::endl;
		if(ss.eof()){
			ll ans;
			if(a <= b){
				ans = tree.query(a, b).val;
			}else{
				ans = std::min(tree.query(0, b).val, tree.query(a, n-1).val);
			}
			std::cout << ans << "\n";
		}else{
			int v;
			ss >> v;
			if(a <= b){
				tree.update(a, b, v);
			}else{
				tree.update(0, b, v);
				tree.update(a, n-1, v);
			}
		}
	}
	return 0;
}