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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 21;
const int N = (1 << K) + 3;
int n;
int a[N];
int b[N];
int ans;

void solve(int x) {
	if (b[0] < 2) return;
	int y = 0;
	for (int k = K - 1; k >= 0; k--) {
		if ((x >> k) & 1) continue;
		if (b[y ^ (1 << k)] >= 2) {
			y ^= 1 << k;
		}
	}
	ans = max(ans, x | y);
}

void add(int x, int k) {
	if (b[x] >= 2) return;
	b[x]++;
	while(k < K) {
		if ((x >> k) & 1) {
			add(x ^ (1 << k), k + 1);
		}
		k++;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--) {
		solve(a[i]);
		add(a[i], 0);
	}
	printf("%d\n", ans);

	return 0;
}