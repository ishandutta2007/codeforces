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

const int N = 100100;
int n;
int par[N], sz[N];
int getPar(int v) {
	return (par[v] == v ? v : par[v] = getPar(par[v]));
}
bool unite(int v, int u) {
	eprintf("unite %d %d\n", v, u);
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

struct Segm {
	int l, r, id, col;

	Segm() : l(), r(), id(), col() {}
	Segm(int _l, int _r, int _id, int _col) : l(_l), r(_r), id(_id), col(_col) {}

	void read(int _id) {
		id = _id;
		scanf("%d%d%d", &col, &l, &r);
	}

	bool operator < (const Segm &S) const {
		return l < S.l;
	}
};

Segm a[N];
set<pii> setik[2];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	int ans = n;
	for (int i = 0; i < 2; i++)
		setik[i].clear();
	for (int i = 0; i < n; i++)
		a[i].read(i);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int v = a[i].id;
		int c = a[i].col;
		setik[c].insert(mp(-a[i].r, v));
		c ^= 1;
		pii f = mp(-1, -1);
		while(!setik[c].empty() && setik[c].begin()->first <= -a[i].l) {
			int id = setik[c].begin()->second;
			if (f.second == -1) {
				f = *setik[c].begin();
			}
			setik[c].erase(setik[c].begin());
			ans -= (int)unite(v, id);
		}
		if (f.second != -1) setik[c].insert(f);
	}
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}