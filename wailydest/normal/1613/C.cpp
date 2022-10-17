#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, a[N];
long long h;

bool test(long long k) 
{
	long long h_ = h;
	for (int i = 0; i < n; ++i) h_ -= std::min(k, i == n - 1 ? ~((long long)1 << 63) : a[i + 1] - a[i]);
	return h_ <= 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &h);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		long long l = 1, r = h;
		while (l <= r) {
			long long m = l + r >> 1;
			if (test(m)) r = m - 1;
			else l = m + 1;
		}
		printf("%lld\n", r + 1);
	}
	return 0;
}