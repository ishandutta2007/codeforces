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

const int K = 16;
const int L = 1 << K;
int sparse[2][K + 1][L];
int k;
int n;
pair<pll, int> a[200200];
int p2[L + 3];

void setSparse(int p, int l, int r, int x) {
	int m = p2[r - l];
	sparse[p][m][l] |= x;
	sparse[p][m][r - (1 << m)] |= x;
}
int getSparse(int p, int l, int r) {
	int m = p2[r - l];
	return sparse[p][m][l] | sparse[p][m][r - (1 << m)];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i <= L; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%d%d", &k, &n);
	ll U = (1LL << k) - 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%d", &a[i].first.first, &a[i].first.second, &a[i].second);
		a[i].first.second++;
	}
	sort(a, a + n);
	int nn = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first.first >= a[nn].first.second) {
			nn++;
			a[nn] = a[i];
		} else {
			if (a[nn].second != a[i].second) {
				printf("impossible\n");
				return 0;
			}
			a[nn].first.second = max(a[nn].first.second, a[i].first.second);
		}
	}
	n = nn + 1;
	for (int i = 0; i < n; i++) {
		ll l = a[i].first.first, r = a[i].first.second;
		int x = a[i].second;
		eprintf("[%lld %lld) - %d\n", l, r, x);
		r--;
		int lb = l >> k, rb = r >> k;
		if (lb == rb) {
			setSparse(1, lb, rb + 1, x);
			setSparse(0, l & U, (r & U) + 1, x);
		} else {
			setSparse(1, lb, rb + 1, x);
			setSparse(0, l & U, U + 1, x);
			setSparse(0, 0, (r & U) + 1, x);
			if (lb + 1 != rb) setSparse(0, 0, U + 1, x);
		}
	}
	for (int w = k; w > 0; w--) {
		for (int l = 0; l + (1 << w) <= U + 1; l++) {
			for (int p = 0; p < 2; p++) {
				sparse[p][w - 1][l] |= sparse[p][w][l];
				sparse[p][w - 1][l + (1 << (w - 1))] |= sparse[p][w][l];
			}
		}
	}
	for (int w = 0; w < k; w++) {
		for (int l = 0; l + (1 << (w + 1)) <= U + 1; l++)
			for (int p = 0; p < 2; p++)
				sparse[p][w + 1][l] = sparse[p][w][l] | sparse[p][w][l + (1 << w)];
	}

	for (int i = 0; i <= U; i++)
		eprintf("%d\n", sparse[0][0][i]);
	for (int i = 0; i <= U; i++)
		eprintf("%d\n", sparse[1][0][i]);

	for (int i = 0; i < n; i++) {
		ll l = a[i].first.first, r = a[i].first.second;
		int x = a[i].second;
		r--;
		int lb = l >> k, rb = r >> k;
		int val = 0;
		if (lb == rb) {
			val |= getSparse(0, l & U, (r & U) + 1) & getSparse(1, lb, rb + 1);
		} else {
			val |= getSparse(0, l & U, U + 1) & getSparse(1, lb, lb + 1);
			val |= getSparse(0, 0, (r & U) + 1) & getSparse(1, rb, rb + 1);
			if (lb + 1 != rb)
				val |= getSparse(0, 0, U + 1) & getSparse(1, lb + 1, rb);
		}
		if (x != val) {
			printf("impossible\n");
			return 0;
		}
	}
	printf("possible\n");
	for (int i = 0; i <= U; i++)
		printf("%d\n", sparse[0][0][i]);
	for (int i = 0; i <= U; i++)
		printf("%d\n", sparse[1][0][i]);

	return 0;
}