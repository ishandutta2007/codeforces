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

constexpr int MOD = 998244353;

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

void run() {
	int n; cin >> n;
	Vi a(n);
	each(e, a) cin >> e;

	if (n == 2) {
		cout << (a[0] != a[1] ? 1 : 0) << '\n';
		return;
	}

	vector<ll> c;
	sort(all(a));

	rep(i, 0, n) {
		if (i > 0 && a[i-1] == a[i]) continue;
		int j = i+1;
		while (j < n && a[i] == a[j]) j++;
		c.pb(j-i);
	}

	if (c.back() > 1) {
		cout << "0\n";
		return;
	}
	c.pop_back();

	ll before = 0;
	vector<ll> cur(n+1), last(n+1);

	each(e, c) {
		cur.swap(last);
		cur.assign(n+1, 0);

		ll j = before+e-3;
		if (j >= 0 && j <= n) cur[j] = before * (before-1) * e % MOD;
		before += e;

		rep(k, 0, n+1-e) cur[k+e] += last[k];
		rep(k, max(0, 2-int(e)), min(n+1, n+3-int(e))) cur[k+e-2] += k*e*last[k] % MOD;
		each(f, cur) f %= MOD;
	}

	vector<ll> fac = {1};
	rep(i, 1, n+5) fac.pb(fac[i-1] * i % MOD);

	ll down = 1;
	each(e, c) down = down * fac[e] % MOD;

	ll ans = cur[0] * modInv(down, MOD) % MOD;
	if (ans < 0) ans += MOD;
	cout << ans << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
	int t; cin >> t;
	while (t--) run();
    return 0;
}