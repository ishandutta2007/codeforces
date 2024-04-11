#include <cstdio>
#include <algorithm>

const int N = 1000000;
int t, n, m, a[N], g;

long long calc() 
{
	long long res = 0;
	for (int i = 0; i < g; ++i) {
		int amt = 0, pos = 0, mn = ~(1 << 31);
		long long sum = 0;
		for (int j = i; j < n; j += g) {
			++amt;
			sum += abs(a[j]);
			if (a[j] >= 0) ++pos;
			mn = std::min(mn, abs(a[j]));
		}
		if ((amt ^ pos) & 1) sum -= 2 * mn;
		res += sum;
	}
	return res;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		g = 0;
		for (int i = 0; i < m; ++i) {
			int ln;
			scanf("%d", &ln);
			g = std::__gcd(g, ln);
		}
		long long ans = calc();
		for (int i = 0; i < g; ++i) a[i] *= -1;
		printf("%lld\n", std::max(ans, calc()));
	}
	return 0;
}