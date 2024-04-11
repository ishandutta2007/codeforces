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

const int N = 30303;
int n;
int a[N];
int ans[N];
int sz;

void solve() {
	sz = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		if ((i ^ a[i]) & 1) {
			printf("-1\n");
			return;
		}
	}
	for (int x = n - 2; x > 0; x -= 2) {
		int p = 0;
		while(a[p] != x + 1) p++;
		p++;
		ans[sz++] = p;
		reverse(a, a + p);
		p = 0;
		while(a[p] != x) p++;
		ans[sz++] = p;
		reverse(a, a + p);
		p += 2;
		ans[sz++] = p;
		reverse(a, a + p);
		assert(a[1] == x);
		assert(a[2] == x + 1);
		ans[sz++] = 3;
		reverse(a, a + 3);
		ans[sz++] = x + 2;
		reverse(a, a + x + 2);
	}
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d ", ans[i]);
	printf("\n");
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