#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 500;
double x[MAXN + 5], ans;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lf", &x[i]);
	for(int i=1;i<=m;i++) {
		int a, b; double c; scanf("%d%d%lf", &a, &b, &c);
		ans = max(ans, (x[a] + x[b]) / c);
	}
	printf("%.9f\n", ans);
}
/*
5 6
13 56 73 98 17
1 2 56
1 3 29
1 4 42
2 3 95
2 4 88
3 4 63
*/