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

constexpr ll M = 10004205361450474;
constexpr ll MAX_Q = 10000;

#ifdef LOC

ll _secret = -1, _counter = 0;

int ask(const vector<ll>& vec) {
	if (_secret < 0) cin >> _secret;

	assert(sz(vec) > 0 && sz(vec) <= _secret);
	rep(i, 1, sz(vec)) {
		assert(vec[i-1] < vec[i]);
		assert(vec[i] <= M);
	}

	//deb(++_counter, _secret, sz(vec), vec);
	deb(++_counter, _secret, sz(vec));
	assert(_counter <= 5);

	if (_secret < vec[0]) return 0;
	if (_secret > vec.back()) return sz(vec);

	rep(i, 0, sz(vec)) {
		if (vec[i] == _secret) exit(0);
		if (vec[i] > _secret) return i;
	}
	assert(0);
}

#else

int ask(const vector<ll>& vec) {
	cout << sz(vec) << ' ';
	each(x, vec) cout << x << ' ';
	cout << endl;

	int i; cin >> i;
	if (i < 0) exit(0);
	return i;
}

#endif

struct DecisionTree {
	Vi E;
	vector<ll> toAsk;
	DBP(E, toAsk);
};

vector<DecisionTree> tree;

pair<ll, ll> bounds(const vector<ll>& vec, int i, ll knownBegin, ll knownEnd) {
	if (i == 0) {
		return { knownBegin, vec[0] };
	} else if (i == sz(vec)) {
		return { vec.back()+1, knownEnd };
	} else {
		return { vec[i-1]+1, vec[i] };
	}
}

pair<int, ll> computeTree(ll begin, ll questions) {
	if (begin+1 >= 10000) {
		ll add = 10000;
		rep(i, 1, questions) {
			add = (add+1)*10000 + add;
		}
		return { -1, begin+add };
	}

	int i = sz(tree);
	tree.emplace_back();

	if (questions == 1) {
		tree[i].toAsk.resize(begin+1);
		iota(all(tree[i].toAsk), begin+1);
		return { i, begin*2+1 };
	}

	ll count = begin+1;

	rep(j, 0, count+1) {
		auto a = computeTree(begin, questions-1);
		tree[i].E.pb(a.x);
		begin = a.y+1;
		tree[i].toAsk.pb(begin);
	}

	tree[i].toAsk.pop_back();
	return { i, begin-1 };
}

void run() {
	computeTree(0, 5);
	pair<ll, ll> x{1, M+1};
	int i = 0;

	while (i != -1) {
		int e = ask(tree[i].toAsk);
		x = bounds(tree[i].toAsk, e, x.x, x.y);
		i = tree[i].E[e];
	}

	while (true) {
		vector<ll> toAsk;
		ll offset = (x.y-x.x+MAX_Q) / (MAX_Q+1);

		if (offset == 0) {
			toAsk.pb(x.x);
		} else {
			rep(j, 0, MAX_Q) {
				toAsk.pb(x.x + offset*(j+1) - 1);
				if (toAsk.back() > M) {
					toAsk.pop_back();
					break;
				}
			}
		}
		x = bounds(toAsk, ask(toAsk), x.x, x.y);
	}
}