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

bool check(int n, int U, int R, int D, int L, int mask) {
	if (mask & 1) {
		U--;
		R--;
	}
	if (mask & 2) {
		U--;
		L--;
	}
	if (mask & 4) {
		D--;
		R--;
	}
	if (mask & 8) {
		D--;
		L--;
	}
	return 0 <= min(min(U, R), min(D, L)) && max(max(U, R), max(D, L)) <= n - 2;
}

bool solve() {
	int n, U, R, D, L;
	scanf("%d%d%d%d%d", &n, &U, &R, &D, &L);
	for (int mask = 0; mask < (1 << 4); mask++)
		if (check(n, U, R, D, L, mask))
			return true;
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}