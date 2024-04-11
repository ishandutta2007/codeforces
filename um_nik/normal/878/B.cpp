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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
int a[N];
ll b[N];
int sz;
ll k, m, ans;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld", &n, &k, &m);
	ans = n * m;
	while(n--) {
		int x;
		scanf("%d", &x);
		if (sz > 0 && a[sz - 1] == x) {
			b[sz - 1]++;
			if (b[sz - 1] == k) {
				ans -= m * k;
				sz--;
			}
		} else {
			a[sz] = x;
			b[sz] = 1;
			sz++;
		}
	}
	if (sz <= 1) {
		ans %= k;
		printf("%lld\n", ans);
		return 0;
	}
	for (int i = 0; i < sz - 1 - i; i++) {
		if (a[i] != a[sz - 1 - i]) {
			printf("%lld\n", ans);
			return 0;
		}
		ll z = b[i] + b[sz - 1 - i];
		if (z < k) {
			printf("%lld\n", ans);
			return 0;
		}
		ans -= (m - 1) * k;
		if (z > k) {
			printf("%lld\n", ans);
			return 0;
		}
	}
	if (sz % 2 == 0) throw;
	ll w = b[sz / 2] * m;
	ans -= (w / k) * k;
	if (w % k != 0) {
		printf("%lld\n", ans);
		return 0;
	}
	printf("0\n");

	return 0;
}