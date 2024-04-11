#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using Vi  = vector<int>;
using Pii = pair<int,int>;
#define mp make_pair
#define pb push_back
#define x  first
#define y  second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x)  for(auto& a : (x))
#define all(x)     (x).begin(),(x).end()
#define sz(x)      int((x).size())
#define tem template<class t,class u,class...w> auto
#define pri(x,y,z) tem operator<<(t&o,u a)->decltype(z,o) { o << *x; y; z; return o << x[1]; }
pri("{}",, a.print())
pri("()",, o << a.x << ", " << a.y)
pri("[]", auto d=""; for (auto i : a) (o << d << i, d = ", "), all(a))
void DD(...) {}
tem DD(t s, u a, w... k) {
    for (int b=1; cerr << *s++, *s && *s - b*44;) b += 2 / (*s*2 - 81);
    cerr << ": " << a; DD(s, k...);
}
#ifdef LOC
#define deb(...) DD("[,\b :] "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

using Pll = pair<ll, ll>;

constexpr ll INF = 1e12;

vector<ll> a;
vector<Pll> dp;
ll l;

Pll getDP(ll minLen, ll maxLen) {
	dp.clear();
	dp.pb({0, 0});
	each(e, a) {
		if (max(dp.back().x, e-maxLen) > dp.back().y) {
			return {-INF, -INF};
		}
		if (dp.back().x > e) {
			return {INF, INF};
		}
		ll from = max(dp.back().x + minLen, e);
		ll to = min(dp.back().y, e) + maxLen;
		assert(from <= to);
		dp.pb({from, to});
	}
	return dp.back();
}

ll getMinLen(ll d) {
	ll b = 0, e = l+5;
	while (b+1 < e) {
		ll m = (b+e) / 2;
		auto tmp = getDP(m, m+d);
		if (tmp.x <= l) {
			b = m;
		} else {
			e = m;
		}
	}
	return b;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);

	int n;
	cin >> l >> n;

	a.resize(n);
	each(e, a) cin >> e;

	ll b = 0, e = l+5;
	while (b+1 < e) {
		ll d = (b+e-1) / 2;
		ll minLen = getMinLen(d);
		auto tmp = getDP(minLen, minLen+d);
		if (tmp.x <= l && l <= tmp.y) {
			e = d+1;
		} else {
			b = d+1;
		}
	}

	ll minLen = getMinLen(b);
	ll maxLen = minLen+b;
	auto tmp = getDP(minLen, maxLen);
	assert(tmp.x <= l && l <= tmp.y);

	ll end = l;
	vector<Pll> segs;

	for (int i = n; i > 0; i--) {
		b = min(a[i-1], end-minLen);
		b = min(b, dp[i-1].y);
		segs.pb({b, end});
		end = b;
	}

	reverse(all(segs));
	each(s, segs) cout << s.x << ' ' << s.y << '\n';
    return 0;
}