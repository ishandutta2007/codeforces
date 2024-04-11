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

const int N = 101;
int a[N];
int l[N], r[N];
int n;

int query() {
	printf("?");
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n");
	fflush(stdout);
	int k;
	scanf("%d", &k);
	return k;
}

void addPair(int v, int u) {
	r[v] = u;
	l[u] = v;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			a[j] = 1 + (int)(i == j);
		int k = query();
		if (k != 0 && k != i) addPair(i, k);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			a[j] = 2 - (int)(i == j);
		int k = query();
		if (k != 0 && k != i) addPair(k, i);
	}
	
	int v = 1;
	while(l[v] != 0) v++;
	for (int i = 1; i <= n; i++) {
		assert(v != 0);
		a[v] = i;
		v = r[v];
	}
	assert(v == 0);
	printf("!");
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}