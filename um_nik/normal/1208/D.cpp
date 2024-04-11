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

const int N = 200200;
ll fenv[N];
void addFenv(int p, ll x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
ll getFenv(int r) {
	ll res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

int n;
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		addFenv(i + 1, i + 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		int l = 0, r = n;
		while(r - l > 1) {
			int m = (l + r) / 2;
			if (getFenv(m) <= a[i])
				l = m;
			else
				r = m;
		}
		a[i] = r;
		addFenv(r, -r);
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}