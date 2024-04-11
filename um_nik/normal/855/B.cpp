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
int n;
ll a[N];
ll b[N], c[N];
ll p, q, r;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld%lld", &n, &p, &q, &r);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i] * p;
		c[i] = a[i] * r;
		a[i] *= q;
	}
	for (int i = 1; i < n; i++)
		b[i] = max(b[i], b[i - 1]);
	for (int i = n - 2; i >= 0; i--)
		c[i] = max(c[i], c[i + 1]);
	ll ans = a[0] + b[0] + c[0];
	for (int i = 0; i < n; i++)
		ans = max(ans, a[i] + b[i] + c[i]);
	printf("%lld\n", ans);

	return 0;
}