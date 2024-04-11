#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = (int)1e5 + 10;

ld x[maxn], y[maxn];
ld r[maxn];

int main() {
	ld a, b, c, d, x0, y0;

	cin >> a >> b >> c >> d >> x0 >> y0;

	a -= x0;
	b -= y0;
	c -= x0;
	d -= y0;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);

		x[i] -= x0;
		y[i] -= y0;
	}

	ld sum = 0;

	for (int i = 0; i < n; i++) {
		r[i] = hypot(x[i], y[i]);
		sum += r[i];
	}

	ld ans = sum - r[0] + hypot(x[0] - a, y[0] - b);

	vector <pair <ld, int> > g, f;

	for (int i = 0; i < n; i++) {
		ans = min(ans, sum - r[i] + hypot(x[i] - a, y[i] - b));
		g.push_back(mp(hypot(x[i] - a, y[i] - b) - r[i], i));
		ans = min(ans, sum - r[i] + hypot(x[i] - c, y[i] - d));
		f.push_back(mp(hypot(x[i] - c, y[i] - d) - r[i], i));
	}

	sort(g.begin(), g.end());
	sort(f.begin(), f.end());

	if (n == 1) {
		printf("%.10lf", ans + sum);
		return 0;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (f[i].second != g[j].second) {
				ans = min(ans, sum + f[i].first + g[j].first);
			}
		}
	}

	printf("%.10lf", ans + sum);

	return 0;
}