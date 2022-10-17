#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define fe(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
int n, m;
vector<ii>a[100020];
int z[100020];
double r[100020];
double ans;
int s[100020];
void dfs(int x, int y) {
	s[x] = 1;
	fe(i, a[x]) {
		if (i -> X != y) {
			dfs(i -> X, x);
			s[x] += s[i -> X];
			double u = n - s[i -> X];
			double v = s[i -> X];
			r[i -> Y] = 0;
			r[i -> Y] += u * (u - 1) * v * 3;
			r[i -> Y] += v * (v - 1) * u * 3;
			r[i -> Y] /= n;
			r[i -> Y] /= n - 1;
			r[i -> Y] /= n - 2;
			ans += r[i -> Y] * z[i -> Y];
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d %d", &x, &y, &z[i]);
		a[x].push_back(ii(y, i));
		a[y].push_back(ii(x, i));
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans -= r[x] * (z[x] - y);
		z[x] = y;
		printf("%.10f\n", ans * 2);
	}
	return 0;
}