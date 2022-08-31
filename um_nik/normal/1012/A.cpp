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
ll a[N];
ll ans = (ll)1e18 + 4;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + 2 * n);
	ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	ll bst = (ll)1e9 + 4;
	for (int i = 1; i <= n - 1; i++) {
		bst = min(bst, a[i + n - 1] - a[i]);
	}
	ans = min(ans, bst * (a[2 * n - 1] - a[0]));
	printf("%lld\n", ans);

	return 0;
}