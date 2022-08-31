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

double ans = -1;
int a[N];
int n;
int U;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &U);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n - 2; i++) {
		int p = upper_bound(a, a + n, a[i] + U) - a - 1;
		if (p <= i + 1) continue;
		double res = (double)(a[p] - a[i + 1]) / (a[p] - a[i]);
		ans = max(ans, res);
	}

	if (ans < -0.5)
		printf("-1\n");
	else
		printf("%.12lf\n", ans);

	return 0;
}