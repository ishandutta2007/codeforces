#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int main()
{
	int n;
	int a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

	ll ans = 0;
	for (int sum = 1; sum <= 4 * n; sum++)
	{
		int lu = sum - b - a;
		int ru = sum - a - c;
		int ld = sum - b - d;
		int rd = sum - c - d;
		int minValue = min({lu, ru, ld, rd});
		int maxValue = max({lu, ru, ld, rd});
		if (minValue <= 1 || maxValue > 2 * n)
			continue;

		int l = max(1, maxValue - n);
		int r = min(n, minValue - 1);
		eprintf("%d: %d..%d\n", sum, l, r);
		ans += max(0, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}