#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


struct Fenwick {
	vector<ll> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<ll>(n, 0)) {}

	void add(int p, ll x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	ll get(int r) {
		ll res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	ll getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;

const int N = (int)1e6 + 7;
ll forCol[N];
char t[10];

struct Segm {
	int l, r, c;

	Segm() : l(), r(), c() {}
	Segm(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}

	void scan() {
		scanf("%d%d%d", &l, &r, &c);
		l--;
	}

	bool operator < (const Segm &S) const {
		return l < S.l;
	}
};
set<Segm> segms;

void cutBy(int x) {
	auto it = segms.lower_bound(Segm(x, 0, 0));
	if (it == segms.begin()) return;
	it--;
	if (it->r == x) return;
	auto S = *it;
	segms.erase(S);
	segms.insert(Segm(S.l, x, S.c));
	segms.insert(Segm(x, S.r, S.c));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	segms.insert(Segm(0, n, 1));
	fenv = Fenwick(n);
	while(q--) {
		scanf("%s", t);
		if (t[0] == 'C') {
			//eprintf("color\n");
			Segm S;
			S.scan();
			cutBy(S.l);
			cutBy(S.r);
			auto it = segms.lower_bound(S);
			while(it != segms.end() && it->l < S.r) {
				fenv.add(it->l, forCol[it->c]);
				fenv.add(it->r, -forCol[it->c]);
				segms.erase(it);
				it = segms.lower_bound(S);
			}
			fenv.add(S.l, -forCol[S.c]);
			fenv.add(S.r, forCol[S.c]);
			segms.insert(S);
		} else if (t[0] == 'A') {
			int c;
			ll x;
			scanf("%d%lld", &c, &x);
			forCol[c] += x;
		} else if (t[0] == 'Q') {
			int v;
			scanf("%d", &v);
			v--;
			auto it = segms.lower_bound(Segm(v + 1, 0, 0));
			assert(it != segms.begin());
			it--;
			printf("%lld\n", fenv.get(v) + forCol[it->c]);
		} else assert(false);
	}

	return 0;
}