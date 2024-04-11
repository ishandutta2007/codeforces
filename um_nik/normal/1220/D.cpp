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

const int K = 63;
vector<ll> a[K];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		int k = 0;
		while(x % 2 == 0) {
			x /= 2;
			k++;
		}
		a[k].push_back(x);
	}
	int m = -1;
	for (int k = 0; k < K; k++) {
		if (m == -1 || (int)a[k].size() > (int)a[m].size())
			m = k;
	}
	printf("%d\n", n - (int)a[m].size());
	for (int k = 0; k < K; k++) {
		if (k == m) continue;
		for (ll x : a[k])
			printf("%lld ", x << k);
	}
	printf("\n");

	return 0;
}