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

const int K = 555;
int k;
int p[K][2];
vector<int> a[K];

void brute(int pos, int d, int mask) {
	if (pos == k) {
		if (mask != 0) a[mask].push_back(d);
		return;
	}
	for (int i = 0; i <= p[pos][1]; i++) {
		brute(pos + 1, d, mask);
		d *= p[pos][0];
		mask |= 1 << pos;
	}
}

vector<int> solve(int k) {
	if (k == 3) return {4, 6, 2, 3, 1, 5, 7};
	vector<int> ord = solve(k - 1);
	int x = ord[0], y = ord.back();
	if (x != ((1 << (k - 1)) - 1)) {
		x |= 1 << (k - 1);
		y = (1 << k) - 1;
	} else {
		y |= 1 << (k - 1);
		x = (1 << k) - 1;
	}
	ord.push_back(y);
	for (int mask = (1 << (k - 1)); mask < (1 << k); mask++) {
		if (mask != x && mask != y)
			ord.push_back(mask);
	}
	ord.push_back(x);
	return ord;
}

void solve() {
	int n;
	scanf("%d", &n);
//	eprintf("solve %d\n", n);
	k = 0;
	for (int x = 2; x * x <= n; x++) {
		if (n % x) continue;
		p[k][0] = x;
		p[k][1] = 0;
		while(n % x == 0) {
			p[k][1]++;
			n /= x;
		}
		k++;
	}
	if (n > 1) {
		p[k][0] = n;
		p[k][1] = 1;
		k++;
	}
	assert(k <= 9);
	for (int i = 0; i < (1 << k); i++) {
		a[i].clear();
	}
//	eprintf("k = %d\n", k);
//	eprintf("before brute\n");
	brute(0, 1, 0);
//	eprintf("after brute\n");
	if (k == 1) {
		for (int x : a[1])
			printf("%d ", x);
		printf("\n0\n");
	} else if (k == 2) {
		if ((int)a[3].size() == 1) {
			printf("%d %d %d\n1\n", a[1][0], a[2][0], a[3][0]);
		} else {
			printf("%d ", a[3][0]);
			for (int x : a[1])
				printf("%d ", x);
			printf("%d ", a[3][1]);
			for (int x : a[2])
				printf("%d ", x);
			for (int i = 2; i < (int)a[3].size(); i++)
				printf("%d ", a[3][i]);
			printf("\n0\n");
		}
	} else {
		vector<int> ord = solve(k);
		for (int mask : ord)
			for (int x : a[mask])
				printf("%d ", x);
		printf("\n0\n");
	}
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