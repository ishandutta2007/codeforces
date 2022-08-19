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

const int N = 100100;
int n;
vector<pii> ans;
vector<int> g[N];
int sz[N];
int h[N];
set<pair<int, pii>> match[N];
set<int> comp[N];
ll want;

void dfsSz(int v, int par) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == par) continue;
		dfsSz(u, v);
		sz[v] += sz[u];
	}
}

int dfsMatch(int v, int par, int id) {
	comp[id].insert(v);
	int lft = -1;
	for (int u : g[v]) {
		if (u == par) continue;
		h[u] = h[v] + 1;
		int x = dfsMatch(u, v, id);
		if (x != -1) {
			if (lft == -1) {
				lft = x;
			} else {
				match[id].insert(mp(h[v], mp(lft, x)));
				lft = -1;
			}
		}
	}
	if (lft == -1) {
		return v;
	} else {
		match[id].insert(mp(h[v], mp(lft, v)));
		return -1;
	}
}

int findWithH(int v, int H) {
	assert(h[v] > H);
	int u = v;
	while(h[u] > H) {
		for (int w : g[u]) {
			if (h[w] < h[u]) {
				u = w;
				break;
			}
		}
	}
	return u;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &want);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfsSz(0, -1);
	int v = 0;
	while(true) {
		int w = v;
		for (int u : g[v]) {
			if (sz[u] > sz[v] || 2 * sz[u] < n) continue;
			w = u;
		}
		if (w == v) break;
		v = w;
	}
	dfsSz(v, -1);
	ll minVal = 0, maxVal = 0;
	for (int i = 0; i < n; i++) {
		minVal += sz[i] & 1;
		maxVal += sz[i];
	}
	maxVal -= n;
	//eprintf("centr = %d, minVal = %lld, maxVal = %lld\n", v, minVal, maxVal);
	if (want < minVal || want > maxVal || (want - minVal) % 2 == 1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	want = (maxVal - want) / 2;
	for (int u : g[v]) {
		h[u] = 1;
		dfsMatch(u, v, u);
	}
	set<pii> setik;
	for (int u : g[v])
		setik.insert(mp(sz[u], u));
	while(want > 0) {
		pii cur = *setik.rbegin();
		//eprintf("want = %lld, %d %d\n", want, cur.first, cur.second);
		assert(cur.first >= 2);
		setik.erase(cur);
		int u = cur.second;
		assert(!match[u].empty());
		auto p = *match[u].rbegin();
		if (p.first <= want) {
			want -= p.first;
			match[u].erase(p);
			ans.push_back(p.second);
			comp[u].erase(p.second.first);
			comp[u].erase(p.second.second);
			if (cur.first - 2 > 0)
				setik.insert(mp(cur.first - 2, u));
			continue;
		}
		int w = p.second.first;
		int z = findWithH(w, want);
		ans.push_back(mp(w, z));
		comp[u].erase(w);
		comp[u].erase(z);
		if (cur.first - 2 > 0)
			setik.insert(mp(cur.first - 2, u));
		break;
	}
	setik.insert(mp(1, v));
	comp[v].insert(v);
	while(!setik.empty()) {
		assert((int)setik.size() >= 2);
		pii c1 = *setik.rbegin();
		setik.erase(c1);
		pii c2 = *setik.rbegin();
		setik.erase(c2);
		int u = c1.second, w = c2.second;
		ans.push_back(mp(*comp[u].begin(), *comp[w].begin()));
		comp[u].erase(comp[u].begin());
		comp[w].erase(comp[w].begin());
		if (c1.first - 1 > 0)
			setik.insert(mp(c1.first - 1, u));
		if (c2.first - 1 > 0)
			setik.insert(mp(c2.first - 1, w));
	}
	for (auto t : ans)
		printf("%d %d\n", t.first + 1, t.second + 1);

	return 0;
}