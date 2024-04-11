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
//    T::id() -> T
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
		T lef, rig; lef = rig = T::id();
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

constexpr ll INF = 1000000666ll*1000000000ll;
struct T {
	ll min, cnt, ans;
	T(): min(0), cnt(1), ans(0) {}
	static T id() {
		T ret;
		ret.min = INF;
		ret.cnt = 0;
		ret.ans = 0;
		return ret;
	}
};
struct U {
	ll min, tick, add;
	U(): min(0), tick(0), add(0) {}
	U(ll a, ll b, ll c): min(a), tick(b), add(c) {}
};
T merge(const T& a, const T& b){
	T ret;
	ret.min = std::min(a.min, b.min);
	ret.cnt = (a.min == ret.min ? a.cnt : 0) + (b.min == ret.min ? b.cnt : 0);
	ret.ans = a.ans + b.ans;
	return ret;
}
void compose(U &u, const U& up){
	ll min = std::min(u.min, u.add + up.min);
	ll tick = (u.min == min ? u.tick : 0) + (u.add + up.min == min ? up.tick : 0);
	u.add += up.add;
	u.min = min;
	u.tick = tick;
}
void apply(T& t, const U& u){
	if(t.min + u.min == 0) t.ans += t.cnt * u.tick;
	t.min += u.add;
}

struct Event{
	int t, l, r, mul, id;
	friend bool operator<(Event a, Event b){
		return a.t == b.t ? a.id > b.id : a.t < b.t;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	VI A(n+1), inv(n+1);
	REP(i, 1, n+1) std::cin >> A[i], inv[A[i]] = i;

	VI lef(n+1), rig(n+1);
	VI stack;
	REP(i, 1, n+1){
		while(SZ(stack) && A[stack.back()] < A[i]) stack.pop_back();
		lef[i] = (SZ(stack) ? stack.back() + 1 : 1);
		stack.push_back(i);
	}
	stack.clear();
	for(int i = n; i >= 1; --i){
		while(SZ(stack) && A[stack.back()] < A[i]) stack.pop_back();
		rig[i] = (SZ(stack) ? stack.back() - 1 : n);
		stack.push_back(i);
	}

	std::vector<Event> evs;

	REP(i, 1, n+1){
		int c = inv[i];
		for(int x = 1; x * x < i; ++x) {
			if(i % x != 0) continue;
			int y = i / x;
			int a = inv[x];
			int b = inv[y];

			int mn = std::min({a, b, c});
			int mx = std::max({a, b, c});
			if(lef[c] <= mn && rig[c] >= mx){
				evs.push_back(Event{mx, lef[c], mn, 1, -1});
				evs.push_back(Event{rig[c] + 1, lef[c], mn, -1, -1});
			}
		}
	}

	std::vector<PR<ll, ll>> que(q);
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		evs.push_back(Event{b+1, a, b, 1, i});
		que[i] = MP(a, b);
	}

	std::sort(evs.begin(), evs.end());
	std::vector<ll> ans(q);
	auto it = evs.begin();

	auto tree = LazyTree<T, U>(n + 1);

	REP(i, 1, n+2){
		while(it != evs.end() && it->t == i && it->id > -1){
			ans[it->id] += tree.query(it->l, it->r).ans;
			++it;
		}
		while(it != evs.end() && it->t == i){
			tree.update(it->l, it->r, U(0, 0, it->mul));
			++it;
		}
		tree.update(1, n, U(0, 1, 0));
	}

	FOR(i, q){
		ll df = (que[i].Y - que[i].X + 1) * que[i].Y;
		std::cout << df - ans[i] << "\n";
	}

	return 0;
}