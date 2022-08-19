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

const int N = 200200;
int n;
int a[N], b[N];

bool solve(int k) {
	for (int i = 0; i < k; i++)
		b[2 * i + 1] = a[i];
	for (int i = 0; i <= k; i++)
		b[2 * i] = a[n - k - 1 + i];
	for (int i = k; i < n - k - 1; i++)
		b[k + i + 1] = a[i];
	for (int i = 0; i < k; i++) {
		if (b[2 * i + 1] >= b[2 * i]) return false;
		if (b[2 * i + 1] >= b[2 * i + 2]) return false;
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	
	int l = 0, r = (n - 1) / 2 + 1;
	while(r - l > 1) {
		int k = (l + r) / 2;
		if (solve(k))
			l = k;
		else
			r = k;
	}
	solve(l);
	printf("%d\n", l);
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}