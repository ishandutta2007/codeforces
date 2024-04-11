#pragma GCC optimize "O3"
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

// min & add
using ll = long long;
constexpr ll INF = 1000000000ll*1000000000ll;
struct T {
	ll val;
	T(): val(0) {}
	T(ll x): val(x) {}
	static T id() {
		return T(-INF);
	}
};
struct U {
	ll add;
	U(): add(0) {}
	U(ll x): add(x) {}
};
T merge(const T& a, const T& b) { return T(std::max(a.val, b.val)); }
void compose(U& u, const U& up) { u.add += up.add; }
void apply(T& t, const U& u) { t.val += u.add; }

using MaxTree = LazyTree<T, U>;

void solve(){
  int n, m;
  std::cin >> n >> m;
  std::vector<PR<PII, int>> A(n);
  std::vector<PII> events;
  VI moments;
  FOR(i, n){
    int x, p;
    std::cin >> x >> p;
    A[i].X.X = x;
    A[i].X.Y = p;
    A[i].Y = i;
    events.push_back(MP(x - p, 1));
    events.push_back(MP(x, -2));
    events.push_back(MP(x + p, 1));
    moments.push_back(x - p);
    moments.push_back(x);
    moments.push_back(x + p);
  }

  std::sort(moments.begin(), moments.end());
  moments.resize(std::unique(moments.begin(), moments.end()) - moments.begin());
  auto kto = [&](int v){
    return (int)(std::lower_bound(moments.begin(), moments.end(), v) - moments.begin());
  };
  // TRAV(ev, events) ev.X = kto(ev.X);
  std::sort(events.begin(), events.end());

  ll last = -1000000666;
  std::vector<ll> val(SZ(moments));
  ll dod = 0;
  ll have = 0;
  TRAV(ev, events){
    ll cur = ev.X;
    ll dif = cur - last;
    have += dod * dif;
    dod += ev.Y;
    val[kto(cur)] = have;
    last = cur;
  }

  TRAV(i, val) i = std::max(0ll, i - m);

  int cnt = SZ(moments);

  // FOR(i, cnt) std::cout << moments[i] << " ";
  // std::cout << "\n";
  // FOR(i, cnt) std::cout << val[i] << " ";
  // std::cout << "\n";

  std::vector<ll> pref(cnt);
  std::vector<ll> suf(cnt);
  FOR(i, cnt){
    pref[i] = val[i] - moments[i];
    suf[i] = val[i] + moments[i];
  }
  auto tt = MaxTree(val);
  auto tp = MaxTree(pref);
  auto ts = MaxTree(suf);

  std::vector<bool> ans(n, true);
  int ind = 0;
  TRAV(pr, A){
    int x = pr.X.X;
    int p = pr.X.Y;

    int prev = kto(x - p);
    int cur = kto(x);
    int post = kto(x + p);

    if(tt.query(0, prev).val > 0 || tt.query(post, cnt-1).val > 0) ans[ind] = false;
    if(tp.query(prev, cur).val > p - x) ans[ind] = false;
    if(ts.query(cur, post).val > p + x) ans[ind] = false;
    ind++;
  }

  FOR(i, n) std::cout << (ans[i] ? "1" : "0");
  std::cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  while(t--) solve();

  return 0;
}