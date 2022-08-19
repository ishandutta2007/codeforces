#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 300300;
const int LOG = 19;
vector<pii> g[N];
int par[N][LOG];
int mx[N][LOG];
int h[N];
int n;
set<pii> segms;
set<pii> valSegm;
set<pii> valGap;

int p2[N];
int sparse[LOG][N];
int getSparse(int l, int r) {
	if (l >= r) return 0;
	int k = p2[r - l];
	return max(sparse[k][l], sparse[k][r - (1 << k)]);
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k] != par[u][k]) {
			v = par[v][k];
			u = par[u][k];
		}
	}
	return par[v][0];
}
int maxUp(int v, int dh) {
	int res = 0;
	for (int k = 0; k < LOG; k++) if ((dh >> k) & 1) {
		res = max(res, mx[v][k]);
		v = par[v][k];
	}
	return res;
}
int getMax(int v, int u) {
	int w = LCA(v, u);
	return max(maxUp(v, h[v] - h[w]), maxUp(u, h[u] - h[w]));
}

void dfs(int v) {
	for (pii e : g[v]) {
		int u = e.first;
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		mx[u][0] = e.second;
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[u][k];
			par[u][k + 1] = par[w][k];
			mx[u][k + 1] = max(mx[u][k], mx[w][k]);
		}
		dfs(u);
	}
}

void myInsert(int l, int r) {
	valSegm.insert(mp(getSparse(l, r - 1), l));
	auto it = segms.lower_bound(mp(l, r));
	pii R = mp(-1, -1);
	if (it != segms.end()) R = *it;
	pii L = mp(-1, -1);
	if (it != segms.begin()) L = *prev(it);
	if (L.first != -1 && R.first != -1) valGap.erase(mp(getMax(L.first, R.first), L.first));
	if (L.first != -1) valGap.insert(mp(getMax(L.first, l), L.first));
	if (R.first != -1) valGap.insert(mp(getMax(l, R.first), l));
	segms.insert(mp(l, r));
}
void myErase(int l, int r) {
	valSegm.erase(mp(getSparse(l, r - 1), l));
	auto it = segms.lower_bound(mp(l, r));
	assert(it != segms.end() && *it == mp(l, r));
	pii R = mp(-1, -1);
	it++;
	if (it != segms.end()) R = *it;
	it--;
	pii L = mp(-1, -1);
	if (it != segms.begin()) L = *prev(it);
	if (L.first != -1) valGap.erase(mp(getMax(L.first, l), L.first));
	if (R.first != -1) valGap.erase(mp(getMax(l, R.first), l));
	if (L.first != -1 && R.first != -1) valGap.insert(mp(getMax(L.first, R.first), L.first));
	segms.erase(mp(l, r));
}


void turnOff(int l, int r) {
	auto it = segms.lower_bound(mp(l, -1));
	if (it != segms.begin()) {
		it--;
		pii s = *it;
		if (s.second > l) {
			myErase(s.first, s.second);
			if (s.second > r) {
				myInsert(s.first, l);
				myInsert(r, s.second);
				return;
			} else {
				myInsert(s.first, l);
			}
		}
	}
	while(true) {
		it = segms.lower_bound(mp(l, -1));
		if (it == segms.end()) break;
		pii s = *it;
		if (s.first >= r) break;
		myErase(s.first, s.second);
		if (s.second > r) {
			myInsert(r, s.second);
			break;
		}
	}
}
void turnOn(int l, int r) {
	turnOff(l, r);
	myInsert(l, r);
}

void eprintAll() {
	eprintf("segms: ");
	for (pii s : segms) eprintf("(%d %d) ", s.first, s.second);
	eprintf("\n");
	eprintf("valSegm: ");
	for (pii s : valSegm) eprintf("(%d %d) ", s.first, s.second);
	eprintf("\n");
	eprintf("valGap: ");
	for (pii s : valGap) eprintf("(%d %d) ", s.first, s.second);
	eprintf("\n");
	
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	int q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	h[1] = 0;
	dfs(1);
	for (int i = 1; i < n; i++)
		sparse[0][i] = getMax(i, i + 1);
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 1; i + (1 << (k + 1)) <= n; i++)
			sparse[k + 1][i] = max(sparse[k][i], sparse[k][i + (1 << k)]);
	while(q--) {
		//eprintAll();
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			r++;
			turnOn(l, r);
		} else if (t == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			r++;
			turnOff(l, r);
		} else {
			int v;
			scanf("%d", &v);
			int ans = 0;
			if (!segms.empty()) ans = max(ans, getMax(v, segms.begin()->first));
			if (!valSegm.empty()) ans = max(ans, valSegm.rbegin()->first);
			if (!valGap.empty()) ans = max(ans, valGap.rbegin()->first);
			if (ans == 0) ans = -1;
			printf("%d\n", ans);
		}
	}

	return 0;
}