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

const int K = 22;
const int N = (int)1e6 + 7;
int n;
int a[N];
int b[(1 << K) + 3];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < (1 << K); i++)
		b[i] = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[((1 << K) - 1) ^ a[i]] = i;
		//b[a[i]] = i;
	}
	for (int k = 0; k < K; k++) {
		for (int mask = 0; mask < (1 << K); mask++) {
			if (((mask >> k) & 1) == 0) continue;
			if (b[mask] == -1) continue;
			b[mask ^ (1 << k)] = b[mask];
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[a[i]] == -1)
			printf("-1 ");
		else
			printf("%d ", a[b[a[i]]]);
	}
	printf("\n");

	return 0;
}