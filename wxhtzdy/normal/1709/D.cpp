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

const int N = 200005;
const int LOG = 20;
int n, m;
int a[N];
int q;
int sparse[N][LOG];
int logs[N];

int getMax(int l, int r) {
	int k = logs[r - l + 1];
	return max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}
int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= m; i++)
		logs[i] = logs[i >> 1] + 1;
	for (int i = 0; i < m; i++)
		sparse[i][0] = a[i];
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i + (1 << j) <= m; i++)
			sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
	scanf("%d", &q);
	while (q--) {
		int x1, y1, x2, y2, k;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		--y1;
		--y2;
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (abs(x1 - x2) % k != 0 || (y2 - y1) % k != 0) {
			printf("NO\n");
			continue;
		}
		if (y1 == y2) {
			printf("YES\n");
			continue;
		}
		int maxH = x1 + (((n - x1) / k) * k);
		if (y1 + 1 < y2 && getMax(y1 + 1, y2 - 1) >= maxH) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}