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

const int N = 500500;
int n, q;
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	n = 1 << n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		ans += a[i];
	}
	printf("%.13lf\n", (double)ans / n);
	while(q--) {
		int v;
		scanf("%d", &v);
		ans -= a[v];
		scanf("%lld", &a[v]);
		ans += a[v];
		printf("%.13lf\n", (double)ans / n);
	}

	return 0;
}