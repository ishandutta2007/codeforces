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

int n, k;
const int N = 505;
int a[N];

bool check(int d) {
	int tot = d * k;
	tot -= n;
	assert(tot % 2 == 0);
	tot /= 2;
	for (int i = 0; i < n; i++) {
		a[i] = 1 + 2 * (tot / n);
		if (i < tot % n) a[i] += 2;
	}
	for (int it = 0; it < d; it++) {
		if (a[k - 1] == 0) return false;
		int p = k - 1, q = k - 1;
		while(p > 0 && a[p - 1] == a[p]) p--;
		while(q + 1 < n && a[q + 1] == a[q]) q++;
		for (int i = 0; i < p; i++)
			a[i]--;
		q++;
		int z = k - p;
		for (int i = q - z; i < q; i++)
			a[i]--;
	}
	return true;
}
void printAns(int d) {
	int ans = 0;
	int tot = d * k;
	tot -= n;
	assert(tot % 2 == 0);
	tot /= 2;
	for (int i = 0; i < n; i++) {
		a[i] = 1 + 2 * (tot / n);
		if (i < tot % n) a[i] += 2;
	}
	for (int it = 0; it < d; it++) {
		printf("?");
		assert(a[k - 1] > 0);
		int p = k - 1, q = k - 1;
		while(p > 0 && a[p - 1] == a[p]) p--;
		while(q + 1 < n && a[q + 1] == a[q]) q++;
		for (int i = 0; i < p; i++) {
			a[i]--;
			printf(" %d", i + 1);
		}
		q++;
		int z = k - p;
		for (int i = q - z; i < q; i++) {
			a[i]--;
			printf(" %d", i + 1);
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		ans ^= x;
	}
	printf("! %d\n", ans);
	fflush(stdout);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	if (n % 2 == 1 && k % 2 == 0) {
		printf("-1\n");
		return 0;
	}
	int d = n / k;
	while(d * k < n || (d * k - n) % 2 == 1) d++;
	while(!check(d)) {
		d++;
		if (k & 1) d++;
	}
//	eprintf("%d\n", d);
	printAns(d);

	return 0;
}