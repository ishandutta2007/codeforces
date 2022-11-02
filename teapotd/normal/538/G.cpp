#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

struct Solver {
	struct Linear {
		ll a, b; // a*S + b
		Linear operator+(const Linear& r) const { return {a+r.a, b+r.b}; }
		Linear operator-(const Linear& r) const { return {a-r.a, b-r.b}; }
		ll eval(ll s) const { return a*s + b; }
	};

	struct Elem {
		ll pref;
		Linear wanted;
		bool operator<(const Elem& r) const { return pref < r.pref; }
	};

	Solver(int l) : wrap(l) {}

	void add(ll t, ll x) {
		ll m = t / wrap, r = t % wrap;
		elems.pb({r, {-m, x}});
	}

	bool solve() {
		sort(all(elems));
		elems.pb({wrap, {1, 0}});

		Elem last = {0, {0, 0}};
		double minS = double(-wrap), maxS = double(wrap);

		each(e, elems) {
			ll len = e.pref - last.pref;
			auto wanted = e.wanted - last.wanted;

			if (wanted.a > 0) {
				minS = max(minS, double(-len-wanted.b) / double(wanted.a));
				maxS = min(maxS, double(len-wanted.b) / double(wanted.a));
			} else if (wanted.a < 0) {
				minS = max(minS, double(len-wanted.b) / double(wanted.a));
				maxS = min(maxS, double(-len-wanted.b) / double(wanted.a));
			}

			last = e;
		}

		rep(s, int(minS)-4, int(minS)+5) {
			if (build(s)) return 1;
		}
		return 0;
	}

	bool build(int s) {
		vector<Pii> segs;
		ll lastPref = 0, lastVal = 0;

		each(e, elems) {
			ll len = e.pref - lastPref;
			ll val = e.wanted.eval(s);
			ll wanted = val - lastVal;

			if ((wanted+len) % 2) return 0;
			ll k = (wanted+len) / 2;
			if (k < 0 || k > len) return 0;
			segs.pb({int(k), int(len-k)});

			lastPref = e.pref;
			lastVal = val;
		}

		each(seg, segs) {
			rep(i, 0, seg.x) answer.pb(1);
			rep(i, 0, seg.y) answer.pb(0);
		}

		return 1;
	}

	ll wrap;
	vector<Elem> elems;
	vector<bool> answer;
};

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(15);

	int n, l; cin >> n >> l;
	Solver sx(l), sy(l);

	rep(i, 0, n) {
		ll t, x, y; cin >> t >> x >> y;
		sx.add(t, x+y);
		sy.add(t, y-x);
	}

	if (!sx.solve() || !sy.solve()) {
		cout << "NO\n";
		return 0;
	}

	rep(i, 0, l) {
		int a = sx.answer[i], b = sy.answer[i];
		cout << "DRLU"[a+b*2];
	}
	cout << endl;
	return 0;
}