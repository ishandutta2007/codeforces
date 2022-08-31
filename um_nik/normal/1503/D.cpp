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

const int N = 400400;
int n;
int a[N], b[N], fl[N];
pii ord[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
			fl[i] = 1;
		}
		ord[i] = mp(a[i], i);
	}
	sort(ord, ord + n);
	for (int i = 0; i < n; i++)
		if (ord[i].first != i + 1) {
			printf("-1\n");
			return 0;
		}
	int ans = 0;
	int cur = 0;
	int len = 0;
	int m1 = 2 * n + 1, m2 = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		int x = b[ord[i].second];
		if (x < m1) {
			m1 = x;
			cur += fl[ord[i].second];
		} else if (x < m2) {
			m2 = x;
			cur += fl[ord[i].second] ^ 1;
		} else {
			printf("-1\n");
			return 0;
		}
		len++;
		if (m1 == 2 * n - i) {
			m2 = m1;
			ans += min(cur, len - cur);
			cur = len = 0;
		}
	}
	assert(len == 0);
	printf("%d\n", ans);

	return 0;
}