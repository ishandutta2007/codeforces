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

const int N = (int)1e6 + 7;
int n;
int a[N];
int d[N];
int cntDif[N];
int c[N][3];
bool u[N];

vector<pair<vector<int>, int>> getGcd(int ban) {
	int g = 0;
	for (int i = 0; i < n; i++) if (i != ban) {
		g = gcd(g, a[i]);
	}
	int gg = 0;
	vector<int> w;
	for (int i = 0; i < n; i++) if (i != ban) {
		int ng = gcd(gg, a[i]);
		if (ng == gg) continue;
		if (gg == 0 || cntDif[gg / g] != cntDif[ng / g]) {
			w.push_back(i);
		}
		gg = ng;
	}
	vector<pair<vector<int>, int>> ans;
	int sz = (int)w.size();
	assert(sz > 0);
	for (int mask = 1; mask < (1 << sz); mask++) {
		int t = 1;
		vector<int> cur;
		for (int i = 0; i < sz; i++) if ((mask >> i) & 1) {
			t ^= 1;
			cur.push_back(w[i]);
		}
		ans.push_back(mp(cur, t));
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 2; x < N; x++) {
		if (d[x] != 0) continue;
		c[x][0] = 0;
		c[x][1] = 30;
		c[x][2] = -1;
		for (int y = x; y < N; y += x)
			if (d[y] == 0)
				d[y] = x;
	}
	cntDif[1] = 0;
	for (int x = 2; x < N; x++) {
		int y = x;
		while(d[y] == d[x]) y /= d[x];
		cntDif[x] = cntDif[y] + 1;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		while(x > 1) {
			int p = d[x];
			int k = 0;
			while(x % p == 0) {
				x /= p;
				k++;
			}
			c[p][0]++;
			if (k < c[p][1]) {
				c[p][1] = k;
				c[p][2] = i;
			}
		}
	}
	for (int p = 2; p < N; p++) if (d[p] == p) {
		if (c[p][0] <= n - 2) continue;
		if (c[p][0] == n - 1) {
			int v = 0;
			while(a[v] % p == 0) v++;
			u[v] = 1;
		} else {
			u[c[p][2]] = 1;
		}
	}
	vector<int> zz;
	for (int i = 0; i < n; i++)
		if (u[i])
			zz.push_back(i);
	vector<pair<vector<int>, int>> ans;
	vector<pair<vector<int>, int>> ans0 = getGcd(-1);
	int w = 2 - (int)zz.size();
	if (w > 0) {
		for (int it = 0; it < w; it++)
			for (auto z : ans0)
				ans.push_back(z);
	} else {
		for (int it = 0; it < -w; it++)
			for (auto z : ans0)
				ans.push_back(mp(z.first, z.second ^ 1));
	}
	for (int x : zz) {
		ans0 = getGcd(x);
		for (auto z : ans0)
			ans.push_back(z);
	}
	printf("%d\n", (int)ans.size());
	for (auto z : ans) {
		printf("%d %d", z.second, (int)z.first.size());
		sort(all(z.first));
		for (int id : z.first)
			printf(" %d", id + 1);
		printf("\n");
	}

	return 0;
}