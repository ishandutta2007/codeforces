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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

const ll INF = (ll)1e18;
const int N = 200200;
const int LOG = 18;
vector<int> g[N];
int par[N][LOG];
ll costPar[N][LOG];
int h[N];
ll a[N], b[N];
int c[N];
int n, m, q;
int Q[N];
pair<pii, ll> allQ[3 * N];
int st[N];
int stSz;
ll pref[N];

void read() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	c[n] = n;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	set<int> setik;
	setik.insert(0);
	setik.insert(n);
	allQ[m++] = mp(mp(n, 0), 0);
	for (int i = 0; i < q; i++) {
		scanf("%d", &Q[i]);
		Q[i]--;
		if (Q[i] == 0) continue;
		if (setik.count(Q[i])) {
			setik.erase(Q[i]);
			auto it = setik.lower_bound(Q[i]);
			assert(it != setik.end());
			assert(it != setik.begin());
			int r = *it;
			it--;
			int l = *it;
			allQ[m++] = mp(mp(r, l), 0);
		} else {
			auto it = setik.lower_bound(Q[i]);
			assert(it != setik.end());
			assert(it != setik.begin());
			int r = *it;
			it--;
			int l = *it;
			allQ[m++] = mp(mp(Q[i], l), 0);
			allQ[m++] = mp(mp(r, Q[i]), 0);
			setik.insert(Q[i]);
		}
	}
	sort(allQ, allQ + m);
	m = unique(allQ, allQ + m) - allQ;
}

ll getCostUp(int v, int u) {
	eprintf("getCostUp %d %d\n", v, u);
	assert(h[u] <= h[v]);
	ll res = 0;
	for (int k = LOG - 1; k >= 0; k--) {
		if (h[v] < h[u] + (1 << k)) continue;
		res += costPar[v][k];
		v = par[v][k];
	}
	assert(v == u);
	return res;
}

void precalc() {
	for (int i = 0; i <= n; i++) {
		while(stSz > 0 && c[st[stSz - 1]] < c[i]) {
			stSz--;
			int v = st[stSz];
			eprintf("addEdge %d %d\n", v, i);
			par[v][0] = i;
			g[i].push_back(v);
		}
		st[stSz++] = i;
	}
	assert(stSz == 1);
	for (int k = 0; k < LOG; k++) {
		par[n][k] = n;
		costPar[n][k] = 0;
	}
	for (int v = n - 1; v >= 0; v--) {
		h[v] = h[par[v][0]] + 1;
		costPar[v][0] = min(b[v], a[v] + getCostUp(v + 1, par[v][0]));
		for (int k = 0; k < LOG - 1; k++) {
			par[v][k + 1] = par[par[v][k]][k];
			costPar[v][k + 1] = costPar[v][k] + costPar[par[v][k]][k];
		}
	}
	stSz = 0;
	int ptr = 0;
	for (int v = 0; v <= n; v++) {
		while(stSz > 0 && c[st[stSz - 1]] < c[v]) {
			stSz--;
		}
		if (stSz > 0) {
			pref[stSz] = pref[stSz - 1] + a[st[stSz - 1]] + getCostUp(st[stSz - 1] + 1, v);
		}
		st[stSz++] = v;
		while(ptr < m && allQ[ptr].first.first == v) {
			int u = allQ[ptr].first.second;
			int pos = lower_bound(st, st + stSz, u) - st;
			allQ[ptr].second = getCostUp(u, st[pos]) + pref[stSz - 1] - pref[pos];
			ptr++;
		}
	}
}

ll query(int l, int r) {
	int pos = lower_bound(allQ, allQ + m, mp(mp(r, l), -INF)) - allQ;
	assert(pos < m && allQ[pos].first == mp(r, l));
	return allQ[pos].second;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	precalc();
	ll ans = query(0, n);
	set<int> setik;
	setik.insert(0);
	setik.insert(n);
	for (int i = 0; i < q; i++) {
		if (Q[i] != 0) {
			if (setik.count(Q[i])) {
				setik.erase(Q[i]);
				auto it = setik.lower_bound(Q[i]);
				assert(it != setik.end());
				assert(it != setik.begin());
				int r = *it;
				it--;
				int l = *it;
				ans -= query(l, Q[i]);
				ans -= query(Q[i], r);
				ans += query(l, r);
			} else {
				auto it = setik.lower_bound(Q[i]);
				assert(it != setik.end());
				assert(it != setik.begin());
				int r = *it;
				it--;
				int l = *it;
				ans += query(l, Q[i]);
				ans += query(Q[i], r);
				ans -= query(l, r);
				setik.insert(Q[i]);
			}
		}
		printf("%lld\n", ans);
	}


	return 0;
}