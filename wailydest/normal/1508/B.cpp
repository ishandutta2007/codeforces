#include <cstdio>

int t, n;
long long k;

long long amt(int n) 
{
	if (!n) return 1;
	if (n >= 63) return ~((long long)1 << 63);
	return (long long)1 << n - 1;
}

void testcase() 
{
	scanf("%d%lld", &n, &k);
	--k;
	if (k >= amt(n)) {
		printf("-1\n");
		return;
	}
	for (int i = n; i;) {
		for (int j = 1;; ++j) {
			if (amt(i - j) <= k) k -= amt(i - j);
			else {
				for (int l = j; l; --l) printf("%d ", l + n - i);
				i -= j;
				break;
			}
		}
	}
	printf("\n");
}

int main() 
{
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}