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

const int N = 7007;
int n;
ll a[N];
ll b[N];
int deg[N];
int q[N];
int topQ;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((a[i] ^ (a[i] & a[j])) == 0)
				deg[i]++;
		}
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			q[topQ++] = i;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int j = 0; j < n; j++) {
			if (v == j) continue;
			if (deg[j] == 0) continue;
			if ((a[j] ^ (a[j] & a[v])) == 0) {
				deg[j]--;
				if (deg[j] == 0)
					q[topQ++] = j;
			}
		}
	}
	if (topQ >= n - 1) {
		printf("0\n");
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += b[i];
	for (int i = 0; i < topQ; i++)
		ans -= b[q[i]];
	printf("%lld\n", ans);

	return 0;
}