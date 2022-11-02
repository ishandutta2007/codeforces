#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")//
// #pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")//
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
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


ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

constexpr int MOD = 998244353;
int n, m, q;

struct Query {
	int begin, end, k, answer, ord;

	bool operator<(const Query& r) const {
		if (k != r.k) return k < r.k;
		return ord < r.ord;
	}
};

vector<Query> queries;
Vi pattern, inPattern, counts;
int ansUp, ansDown, mult1;
int lastK = -1, lastBegin, lastEnd;

void addElem(int e) {
	ansUp = (ll(ansUp) * counts[e]--) % MOD;
	ansDown = (ll(ansDown) * mult1--) % MOD;
}

void delElem(int e) {
	ansUp = (ll(ansUp) * ++mult1) % MOD;
	ansDown = (ll(ansDown) * ++counts[e]) % MOD;
}

int handle(int begin, int end, int k) {
	if (lastK != k) {
		lastK = k;
		lastBegin = begin;
		lastEnd = begin;
		ansDown = ansUp = 1;

		mult1 = (ll(m)*k) % MOD;
		rep(i, 0, n) {
			mult1 += 1;
			ansUp = (ll(ansUp) * mult1) % MOD;
		}

		rep(i, 0, m) counts[i] = (inPattern[i] + k) % MOD;
	}

	while (lastBegin > begin) addElem(pattern[--lastBegin]);
	while (lastEnd < end)     addElem(pattern[lastEnd++]);
	while (lastBegin < begin) delElem(pattern[lastBegin++]);
	while (lastEnd > end)     delElem(pattern[--lastEnd]);
	
	ll ans = (ll(ansUp) * modInv(ansDown, MOD)) % MOD;
	if (ans < 0) ans += MOD;
	return ans;
}

ll hilbert(ll x, ll y, ll s, ll c = 0) {
	if (s <= 1) return c;
	s /= 2; c *= 4;
	if (y < s)
		return hilbert(x&(s-1), y, s, c+(x>=s)+1);
	if (x < s)
		return hilbert(2*s-y-1, s-x-1, s, c);
	return hilbert(y-s, x-s, s, c+3);
}

void run() {
	cin >> n >> m >> q;

	int moSize = 1;
	while (moSize < n) moSize *= 2;

	pattern.resize(n);
	inPattern.resize(m);
	counts.resize(m);

	each(p, pattern) {
		cin >> p; p--;
		inPattern[p]++;
	}

	queries.resize(q);
	each(p, queries) {
		cin >> p.begin >> p.end >> p.k;
		p.begin--;
		p.ord = hilbert(p.begin, p.end, moSize);
	}

	Vi sorted(q);
	iota(all(sorted), 0);
	sort(all(sorted), [](ll l, ll r) { return queries[l] < queries[r]; });

	each(i, sorted) {
		auto& p = queries[i];
		p.answer = handle(p.begin, p.end, p.k);
	}

	each(p, queries) cout << p.answer << '\n';
}