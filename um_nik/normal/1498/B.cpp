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

const int N = 100100;
const int K = 31;
int a[K];
int w;

bool solve(int x) {
	int bal = 0;
	for (int k = 0; k < K; k++) {
		bal += a[k];
		if ((w >> k) & 1) bal = max(0, bal - x);
		bal = (bal + 1) / 2;
	}
	return bal == 0;
}

void solve() {
	int r;
	scanf("%d%d", &r, &w);
	for (int k = 0; k < K; k++)
		a[k] = 0;
	for (int i = 0; i < r; i++) {
		int x;
		scanf("%d", &x);
		int k = 0;
		while(x > (1 << k)) k++;
		assert(x == (1 << k));
		a[k]++;
	}
	int l = 0;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}