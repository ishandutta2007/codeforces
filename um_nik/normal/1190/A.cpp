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

const int N = 100100;
ll n, k;
ll a[N];
int m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%d%lld", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &a[i]);
		a[i] -= i + 1;
	}
	int pos = 0;
	int ans = 0;
	while(pos < m) {
		int r = pos + 1;
		while(r < m && (a[r] + r - pos) / k == a[pos] / k) r++;
		ans++;
		pos = r;
	}
	printf("%d\n", ans);

	return 0;
}