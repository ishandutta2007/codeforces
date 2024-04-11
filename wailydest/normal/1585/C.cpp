#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, k, x[N];

long long calc() 
{
	long long ans = 0;
	int loc = 0, amt = k, z = std::lower_bound(x, x + n, 0) - x, cur = n;
	while (cur > z) {
		if (!amt) {
			amt = k;
			ans += loc;
			loc = 0;
		} else {
			--cur;
			ans += abs(loc - x[cur]);
			loc = x[cur];
			--amt;
		}
	}
	ans += loc;
	cur = loc = 0;
	amt = k;
	while (cur < z) {
		if (!amt) {
			amt = k;
			ans -= loc;
			loc = 0;
		} else {
			ans += abs(loc - x[cur]);
			loc = x[cur];
			--amt;
			++cur;
		}
	}
	ans -= loc;
	return ans - std::max(x[n - 1], -x[0]);
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", x + i);
		std::sort(x, x + n);
		printf("%lld\n", calc());
	}
	return 0;
}