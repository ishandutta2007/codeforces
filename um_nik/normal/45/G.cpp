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

const int N = (int)2e7;
bool p[N];
int a[6767];

void printTwo(int n, int x, int y) {
	for (int i = n; i > 0; i--) {
		if (i <= x) {
			a[i] = 1;
			x -= i;
		} else if (i <= y) {
			a[i] = 2;
			y -= i;
		} else throw;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


void printThree(int n, int x, int y) {
	a[3] = 3;
	for (int i = n; i > 0; i--) {
		if (i == 3) continue;
		if (i <= x) {
			a[i] = 1;
			x -= i;
		} else if (i <= y) {
			a[i] = 2;
			y -= i;
		} else throw;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = 0;
	}
/*
	for (int i = 0; i < 20; i++)
		eprintf("%d", (int)p[i]);
	eprintf("\n");
*/
	int n;
	scanf("%d", &n);
	int s = n * (n + 1) / 2;
	if (p[s]) {
		for (int i = 0; i < n; i++)
			printf("1 ");
		printf("\n");
		return 0;
	}
	for (int x = 1; x < s; x++) {
		if (p[x] && p[s - x]) {
			printTwo(n, x, s - x);
			return 0;
		}
	}
	assert(s & 1);
	for (int x = 1; x < s - 3; x++) {
		if (p[x] && p[s - x - 3]) {
			printThree(n, x, s - x - 3);
			return 0;
		}
	}

	return 0;
}