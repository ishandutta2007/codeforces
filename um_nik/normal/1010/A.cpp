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

const double INF = 1e10;

const int IT = 150;

const int N = 2020;
int n;
double a[N];
double m;

bool solve(double x) {
	x += m;
	for (int i = 0; i < n; i++) {
		x -= x / a[i];
	}
	return x > m;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lf", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[2 * i]);
	scanf("%lf", &a[2 * n - 1]);
	for (int i = 1; i < 2 * n - 2; i += 2)
		scanf("%lf", &a[i]);

	n *= 2;
	for (int i = 0; i < n; i++) {
		if (a[i] < 1.5) {
			printf("-1\n");
			return 0;
		}
	}

	double L = 0, R = INF;
	for (int it = 0; it < IT; it++) {
		double x = (L + R) / 2;
		if (solve(x))
			R = x;
		else
			L = x;
	}
	printf("%.13lf\n", R);

	return 0;
}