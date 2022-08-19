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

const int INF = (int)2e9 + 77;
const int N = 100100;
const int M = 33;
const int S = (int)32e5 + 7;
int n, m, k;
int a[N][M];
map<int, int> go[S];
int c[6];
pii ord[N];
int cnt[S];
int ppc[M];

bool solve(int B) {
	memset(cnt, 0, sizeof cnt);
	int p = 0;
	for (int i = n - 1; i >= 0; i--) {
		while(p < n && ord[i].first + ord[p].first <= B) {
			for (int mask = 0; mask < (1 << m); mask++)
				cnt[a[ord[p].second][mask]]++;
			p++;
		}
		int cur = 0;
		int v = ord[i].second;
		for (int mask = 0; mask < (1 << m); mask++)
			cur += ppc[mask] * cnt[a[v][mask]];
		if (cur > 0) return true;
	}
	return false;
}

void brute(int pos, int v, int mask, int id) {
	if (pos == m) {
		a[id][mask] = v;
		return;
	}
	brute(pos + 1, v, mask, id);
	int cc = c[pos];
	if (go[v].count(cc) == 0) {
		go[v][cc] = k;
		v = k++;
	} else {
		v = go[v][cc];
	}
	brute(pos + 1, v, mask ^ (1 << pos), id);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int mask = 1; mask < M; mask++)
		ppc[mask] = ppc[mask >> 1] ^ (mask & 1);
	for (int mask = 0; mask < M; mask++)
		if (ppc[mask] == 0)
			ppc[mask] = 1;
		else
			ppc[mask] = -1;

	k = 1;

	scanf("%d%d", &n, &m);
	//n = 100000;
	//m = 5;

	int sz = 0;
	for (int r = 0; r < n; r++) {
		for (int i = 0; i < m; i++) {
			scanf("%d", &c[i]);
			//c[i] = myRand(1e9);
		}
		sort(c, c + m);
		int w;
		scanf("%d", &w);
		//w = myRand(1e9);
		bool ok = true;
		for (int i = 1; i < m; i++)
			ok &= c[i] != c[i - 1];
		if (!ok) continue;
		ord[sz] = mp(w, sz);
		brute(0, 0, 0, sz);
		sz++;
	}
	n = sz;
	sort(ord, ord + n);
	int l = -1, r = INF;
	while(r - l > 1) {
		int x = l + (r - l) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (r == INF) r = -1;
	printf("%d\n", r);

	return 0;
}