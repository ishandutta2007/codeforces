#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }


struct ABString {
	Vi parts;
	bool front;
	DBP(parts, front);

	void push(int count, bool type) {
		if (count == 0) return;
		if (parts.empty() || front != type) {
			parts.pb(0);
			front = type;
		}
		parts.back() += count;
	}

	pair<int, bool> pop() {
		if (parts.empty()) return {0,0};
		pair<int, bool> ret = {parts.back(), front};
		parts.pop_back();
		front = !front;
		return ret;
	}

	void read() {
		string tmp; cin >> tmp;
		parts.clear();
		for (int i = sz(tmp)-1; i >= 0; i--)
			push(1, tmp[i] == 'b');
	}

	bool satisfied() {
		return sz(parts) <= 1;
	}
};

struct State {
	ABString s, t;
	vector<Pii> ans;
	DBP(s, t, ans);

	void makeMove(int a, int b) {
		vector<pair<int, bool>> x, y;
		Pii move = {0,0};

		rep(i, 0, a) {
			x.pb(s.pop());
			move.x += x.back().x;
		}

		rep(i, 0, b) {
			y.pb(t.pop());
			move.y += y.back().x;
		}

		reverse(all(x));
		reverse(all(y));
		each(e, x) t.push(e.x, e.y);
		each(e, y) s.push(e.x, e.y);

		if (move.x != 0 || move.y != 0) {
			ans.pb(move);
		}
	}

	void greedy() {
		if (s.front == t.front) {
			if (sz(s.parts) > sz(t.parts)) {
				makeMove(1, 0);
			} else {
				makeMove(0, 1);
			}
		}

		while (!s.satisfied() || !t.satisfied()) {
			makeMove(1, 1);
		}
	}

	void solve() {
		bool swapped = false;
		if (sz(s.parts) < sz(t.parts)) {
			swap(s, t);
			swapped = true;
		}
		int mid = (sz(s.parts) - sz(t.parts)) / 2;

		State best;
		bool found = false;

		rep(a, max(mid-3, 0), min(mid+4, sz(s.parts))) {
			rep(b, 0, 2) {
				State alt = *this;
				alt.makeMove(a, b);

				if (!alt.s.satisfied() || !alt.t.satisfied()) {
					alt.greedy();
				}

				if (!found || sz(alt.ans) < sz(best.ans)) {
					best = move(alt);
					found = true;
				}
			}
		}

		*this = move(best);
		if (swapped)
			each(x, ans) swap(x.x, x.y);
	}
};

void run() {
	State state;
	state.s.read();
	state.t.read();
	state.solve();

	cout << sz(state.ans) << '\n';
	each(x, state.ans) cout << x.x << ' ' << x.y << '\n';
}