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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 2;
const ll MODS[K] = {(ll)1e9 + 7, (ll)1e9 + 9};
struct Num {
	ll x[K];

	Num() : x() {}
	Num(ll z) {
		for (int i = 0; i < K; i++)
			x[i] = ((z % MODS[i]) + MODS[i]) % MODS[i];
	}

	Num operator + (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < K; i++) {
			R.x[i] = x[i] + A.x[i];
			if (R.x[i] >= MODS[i]) R.x[i] -= MODS[i];
		}
		return R;
	}
	Num operator - (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < K; i++) {
			R.x[i] = x[i] - A.x[i];
			if (R.x[i] < 0) R.x[i] += MODS[i];
		}
		return R;
	}
	Num operator * (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < K; i++) {
			R.x[i] = (x[i] * A.x[i]) % MODS[i];
		}
		return R;
	}
};

const int L = 17;
const int N = (1 << L) + 3;
int ed[N][3];
int n, m;
vector<int> g[N];
int par[N];
int h[N];
bool usedEd[N];
int xorAll;
Num A[N], B[N];

void FFT(Num* C) {
	for (int k = 0; k < L; k++)
		for (int mask = 0; mask < (1 << L); mask++) {
			if ((mask >> k) & 1) continue;
			Num x = C[mask], y = C[mask ^ (1 << k)];
			C[mask] = x + y;
			C[mask ^ (1 << k)] = x - y;
		}
}

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

void addCycle(int id) {
	vector<int> all;
	int v = ed[id][0], u = ed[id][1];
	if (h[v] < h[u]) swap(v, u);
	all.push_back(id);
	while(v != u) {
		id = par[v];
		all.push_back(id);
		v = getOther(id, v);
	}
	for (int i = 0; i < (1 << L); i++)
		B[i] = Num(0);
	for (int id : all) {
		usedEd[id] = 1;
		int x = ed[id][2];
		B[x] = B[x] + Num(1);
	}
	FFT(B);
	for (int i = 0; i < (1 << L); i++)
		A[i] = A[i] * B[i];
}

void dfs(int v) {
	eprintf("dfs %d\n", v);
	for (int id : g[v]) {
		if (id == par[v]) continue;
		int u = getOther(id, v);
		if (par[u] == -1) {
			if (usedEd[id]) throw;
			par[u] = id;
			h[u] = h[v] + 1;
			dfs(u);
		} else {
			if (usedEd[id]) continue;
			addCycle(id);
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	A[0] = Num(1);
	FFT(A);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &ed[i][j]);
		ed[i][0]--;
		ed[i][1]--;
		g[ed[i][0]].push_back(i);
		g[ed[i][1]].push_back(i);
		xorAll ^= ed[i][2];
	}
	for (int i = 0; i < n; i++)
		par[i] = -1;
	par[0] = -2;
	dfs(0);

	FFT(A);
	int bst = N;
	ll cnt = 0;
	for (int mask = 0; mask < (1 << L); mask++) {
		bool bad = true;
		for (int i = 0; i < K; i++)
			bad &= A[mask].x[i] == 0;
		if (bad) continue;
		int m2 = mask ^ xorAll;
		if (m2 < bst) {
			bst = m2;
			cnt = A[mask].x[0];
		}
	}
	for (int i = 0; i < L; i++) {
		if (cnt & 1) cnt += MODS[0];
		cnt /= 2;
	}
	printf("%d %lld\n", bst, cnt);

	return 0;
}