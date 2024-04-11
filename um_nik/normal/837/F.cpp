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

const int N = 200200;
int n;
ll k;
ll a[N];
const ll INF = (ll)1e18 + 4;

ll mult(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	if (2 * INF / x < y) return INF;
	return min(INF, x * y);
}

ll getC(ll n, int k)
{
	ll res = 1;
	for (int i = 1; i <= k; i++) {
		if (7 * INF / res < n + 1 - i) return INF;
		res *= n + 1 - i;
		res /= i;
		if (res >= INF) return res;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i == 0 && a[i] == 0) {
			i--;
			n--;
			continue;
		}
		if (a[i] >= k) {
			printf("0\n");
			return 0;
		}
	}
	if (n < 2) throw;
	
	if (n > 5) {
		for (int it = 1;; it++) {
			for (int i = 1; i < n; i++) {
				a[i] += a[i - 1];
				if (a[i] >= k) {
					printf("%d\n", it);
					return 0;
				}
			}
		}
	}

	ll l = 0, r = k + 1;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mult(a[i], getC(m - 1 + n - i - 1, n - i - 1));
		}
		if (sum >= k)
			r = m;
		else
			l = m;
	}
	printf("%lld\n", r);

	return 0;
}