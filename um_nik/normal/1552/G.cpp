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

const int L = 41;
const int M = 20;
int ppc[(1 << M) + 3];
int n, m;
ll a[M];
ll b[M][L];

int popcount(ll mask) {
	return ppc[mask & ((1LL << M) - 1)] + ppc[mask >> M];
}

void check(int p, ll used, ll mask) {
	if (p == m) {
		if ((used + 1) != (1LL << n)) {
			printf("REJECTED\n");
			exit(0);
		}
		if (mask & (mask + 1)) {
			printf("REJECTED\n");
			exit(0);
		}
		return;
	}
	ll hv = used & a[p];
	ll dhv = a[p] ^ hv;
	ll cur = hv & mask;
	mask ^= cur;
	used |= a[p];
	int l = popcount(cur);
	int r = l + popcount(dhv);
	for (int i = l; i <= r; i++)
		check(p + 1, used, mask | b[p][i]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int mask = 1; mask < (1 << M); mask++)
		ppc[mask] = ppc[mask / 2] + (mask & 1);

	scanf("%d%d", &n, &m);
	if (n == 1) {
		printf("ACCEPTED\n");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int s;
		scanf("%d", &s);
		int x;
		while(s--) {
			scanf("%d", &x);
			x--;
			a[i] |= 1LL << x;
		}
		int p = popcount(a[i]);
		int it = 0;
		b[i][0] = 0;
		for (int j = 0; j < n; j++) {
			if (((a[i] >> j) & 1) == 0) continue;
			it++;
			b[i][it] = b[i][it - 1] ^ (1LL << j);
		}
	}
	check(0, 0, 0);
	printf("ACCEPTED\n");

	return 0;
}