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

constexpr int MAX_N = 200000;
constexpr int MAX_VAL = 6000000;
constexpr int MAX_FACTORS = 8;

int dp[MAX_VAL][MAX_FACTORS];
int prefs[MAX_FACTORS*2];

Vi factor(MAX_VAL+1);

void sieve() {
	for (int i = 2; i*i <= MAX_VAL; i++)
		if (!factor[i])
			for (int j = i*i; j <= MAX_VAL; j += i)
				if (!factor[j])
					factor[j] = i;

	rep(i,0,MAX_VAL+1) if (!factor[i]) factor[i]=i;
}

Vi factorize(ll n) {
	Vi ret;
	while (n > 1) {
		int f = factor[n];
		if (ret.empty() || ret.back() != f) ret.pb(f);
		else ret.pop_back();
		n /= f;
	}
	return ret;
}

void run() {
	int n, m;
	cin >> n >> m;

	Vi elems(n);
	each(e, elems) cin >> e;

	vector<Pii> queries(m);
	each(q, queries) {
		cin >> q.x >> q.y;
		q.x--;
	}

	Vi answers(m, -1);
	Vi sorted(m);
	iota(all(sorted), 0);
	sort(all(sorted), [&](int l, int r) { return queries[l].x > queries[r].x; });

	rep(i, 0, MAX_VAL) rep(j, 0, MAX_FACTORS) dp[i][j] = 1e9;
	rep(j, 0, MAX_FACTORS*2) prefs[j] = 1e9;

	int cur = 0;
	sieve();

	for (int begin = n-1; begin >= 0; begin--) {
		Vi factors = factorize(elems[begin]);

		rep(i, 0, 1<<sz(factors)) {
			int div = 1;
			int inter = __builtin_popcount(i);
			rep(j, 0, sz(factors)) if ((i>>j) & 1) div *= factors[j];

			rep(count, 0, MAX_FACTORS) {
				int pos = dp[div][count];
				int val = sz(factors) + count - 2*inter;
				prefs[val] = min(prefs[val], pos);
			}

			dp[div][sz(factors)] = begin;
		}

		while (cur < m && queries[sorted[cur]].x == begin) {
			rep(i, 0, MAX_FACTORS*2) {
				if (prefs[i] < queries[sorted[cur]].y) {
					answers[sorted[cur]] = i;
					break;
				}
			}
			cur++;
		}
	}

	each(a, answers) cout << a << '\n';
}