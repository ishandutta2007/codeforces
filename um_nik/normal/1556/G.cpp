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

#define tm kiujyhtgrfed

const int M = 100100;
const int N = (int)15e5 + 8;
const int S = (int)6e7;
int n, q;
ll Q[M][3];
ll a[M];
ll b[N];
int tm[N];
int m, k;
char s[10];
int ed[S][2];
int ord[M];
int ans[M];
int ansSz;
int par[N];
int sz[N];

void myassert(bool f) {
	if (!f) exit(0);
}

int getPar(int v) {
	return (par[v] == v ? v : par[v] = getPar(par[v]));
}
void unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	scanf("%d%d", &n, &q);
	a[k++] = 0;
	a[k++] = 1LL << n;
	for (int i = 0; i < q; i++) {
		scanf("%s", s);
		if (s[0] == 'b') {
			Q[i][0] = 0;
			scanf("%lld%lld", &Q[i][1], &Q[i][2]);
			Q[i][2]++;
			a[k++] = Q[i][1];
			a[k++] = Q[i][2];
		} else {
			Q[i][0] = 1;
			scanf("%lld%lld", &Q[i][1], &Q[i][2]);
		}
	}

	/*
	n = 10;
	a[k++] = 0;
	a[k++] = 1LL << n;
	for (int i = 0; i < 77; i++)
		a[k++] = myRand(1LL << n);
	*/
	sort(a, a + k);
	k = unique(a, a + k) - a;
	b[m++] = 0;
	for (int i = 0; i < k - 1; i++) {
		ll x = a[i];
		while(x < a[i + 1]) {
			int p = 0;
			while(p < n && x + (1LL << (p + 1)) <= a[i + 1] && ((x >> p) & 1) == 0) p++;
			x += 1LL << p;
			assert(m < N);
			b[m++] = x;
		}
		myassert(x == a[i + 1]);
	}
	/*
	eprintf("m = %d\n", m);
	for (int i = 0; i < m; i++)
		eprintf("%lld ", b[i]);
	eprintf("\n");
	*/
	for (int i = 0; i < m - 1; i++)
		tm[i] = q;
	
	for (int i = 0; i < q; i++) {
		if (Q[i][0] == 0) {
			int p = lower_bound(b, b + m, Q[i][1]) - b;
			assert(b[p] == Q[i][1]);
			while(b[p] < Q[i][2]) {
				tm[p] = i;
				p++;
			}
			assert(b[p] == Q[i][2]);
		} else {
			for (int z = 1; z < 3; z++)
				Q[i][z] = upper_bound(b, b + m, Q[i][z]) - b - 1;
		}
	}

	for (int k = 0; k < n; k++) {
		//eprintf("k = %d\n", k);
		int p = 0, q = 0;
		while(q < m - 1) {
			while(q < m - 1 && ((b[q] >> k) & 1) == 0) q++;
			if (q == m - 1) break;
			while(p < m - 1 && ((b[p] >> k) & 1) == 1) p++;
			if (p == m - 1) break;
			if (p >= q) {
				q = p + 1;
				continue;
			}
			if (b[p] + (1LL << k) < b[q]) {
				p++;
				continue;
			}
			if (b[p] + (1LL << k) > b[q]) {
				q++;
				continue;
			}
			if (b[p + 1] - b[p] > b[q + 1] - b[q]) {
				//myassert(b[p + 1] - b[p] >= (1LL << k));
				ll fin = b[q] + b[p + 1] - b[p];
				while(b[q] < fin) {
					int z = min(tm[p], tm[q]);
					ord[z + 1]++;
					q++;
				}
				myassert(b[q] == fin);
				p++;
			} else {
				//myassert(b[q + 1] - b[q] >= (1LL << k));
				ll fin = b[p] + b[q + 1] - b[q];
				while(b[p] < fin) {
					int z = min(tm[p], tm[q]);
					ord[z + 1]++;
					p++;
				}
				myassert(b[p] == fin);
				q++;
			}
		}
	}
	for (int i = 1; i <= q + 1; i++)
		ord[i] += ord[i - 1];
	assert(ord[q + 1] < S);
	for (int k = 0; k < n; k++) {
		int p = 0, q = 0;
		while(q < m - 1) {
			while(q < m - 1 && ((b[q] >> k) & 1) == 0) q++;
			if (q == m - 1) break;
			while(p < m - 1 && ((b[p] >> k) & 1) == 1) p++;
			if (p == m - 1) break;
			if (p >= q) {
				q = p + 1;
				continue;
			}
			if (b[p] + (1LL << k) < b[q]) {
				p++;
				continue;
			}
			if (b[p] + (1LL << k) > b[q]) {
				q++;
				continue;
			}
			if (b[p + 1] - b[p] > b[q + 1] - b[q]) {
				ll fin = b[q] + b[p + 1] - b[p];
				while(b[q] < fin) {
					int z = min(tm[p], tm[q]);
					ed[ord[z]][0] = p;
					ed[ord[z]][1] = q;
					ord[z]++;
					q++;
				}
				//assert(b[q] == fin);
				p++;
			} else {
				ll fin = b[p] + b[q + 1] - b[q];
				while(b[p] < fin) {
					int z = min(tm[p], tm[q]);
					ed[ord[z]][0] = p;
					ed[ord[z]][1] = q;
					ord[z]++;
					p++;
				}
				//assert(b[p] == fin);
				q++;
			}
		}
	}
	/*
	eprintf("edges:\n");
	for (int i = 0; i < ord[q]; i++)
		eprintf("%d %d %d\n", ed[i][0], ed[i][1], min(tm[ed[i][0]], tm[ed[i][1]]));
	*/
	int pos = ord[q + 1] - 1;
	for (int i = 0; i < m - 1; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = q - 1; i >= 0; i--) {
		while(pos >= 0) {
			int v = ed[pos][0], u = ed[pos][1];
			int z = min(tm[v], tm[u]);
			if (z < i) break;
			unite(v, u);
			pos--;
		}
		if (Q[i][0] == 0) continue;
		ans[ansSz++] = (int)(getPar(Q[i][1]) == getPar(Q[i][2]));
	}
	reverse(ans, ans + ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d\n", ans[i]);

	return 0;
}