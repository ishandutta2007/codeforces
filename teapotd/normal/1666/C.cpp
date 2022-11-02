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

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);

	Pii p[3];
	each(e, p) cin >> e.x >> e.y;
	sort(p, p+3);
	Pii p0 = p[0], p1 = p[1], p2 = p[2];

	vector<pair<Pii, Pii>> ans;
	auto add = [&](Pii a, Pii b) {
		assert(a.x == b.x || a.y == b.y);
		if (a != b) ans.pb({a, b});
	};

	add({p1.x, min(min(p0.y, p1.y), p2.y)}, {p1.x, max(max(p0.y, p1.y), p2.y)});
	add(p0, {p1.x, p0.y});
	add(p2, {p1.x, p2.y});

	cout << sz(ans) << '\n';
	each(e, ans) cout << e.x.x << ' ' << e.x.y << ' ' << e.y.x << ' ' << e.y.y << '\n';
    return 0;
}