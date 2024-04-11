#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
long long ans, t, T, x, cost;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
	  scanf("%I64d %I64d %I64d %I64d", &t, &T, &x, &cost);
		ans += (T -= t) > 0 ? min((m + T - 1) / T * cost, m * x + cost) : m * x + cost;
	}
	printf("%I64d\n", ans);
	return 0;
}