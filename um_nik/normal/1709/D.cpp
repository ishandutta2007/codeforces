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

const int N = 200200;
const int LOG = 18;
int a[N];
int n, m;
int sparse[LOG][N];
int p2[N];

int getMax(int l, int r) {
	int k = p2[r - l];
	return max(sparse[k][l], sparse[k][r - (1 << k)]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sparse[0][i] = a[i];
	}
	for (int k = 0; k < LOG - 1; k++) {
		for (int i = 0; i + (1 << (k + 1)) <= n; i++)
			sparse[k + 1][i] = max(sparse[k][i], sparse[k][i + (1 << k)]);
	}
	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;
	int q;
	scanf("%d", &q);
	while(q--) {
		int x1, y1, x2, y2, k;
		scanf("%d%d%d%d%d", &y1, &x1, &y2, &x2, &k);
		if (abs(x1 - x2) % k) {
			printf("NO\n");
			continue;
		}
		if (abs(y1 - y2) % k) {
			printf("NO\n");
			continue;
		}
		if (x1 > x2) swap(x1, x2);
		int mx = getMax(x1 - 1, x2);
		int y = m - (m % k);
		y += y1 % k;
		while(y <= m) y += k;
		y -= k;
		if (y <= mx) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}

	return 0;
}