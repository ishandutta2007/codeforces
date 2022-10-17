#include <cstdio>
#include <algorithm>
#include <cstdlib>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int amt = 0;
		long long s1 = 0, s2 = 0;
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			if (v & 1) {
				s1 += abs(i - amt * 2);
				s2 += abs(i - amt * 2 - 1);
				++amt;
			}
		}
		if (n & 1) {
			if (amt == n / 2) printf("%lld\n", s2);
			else if (amt == n / 2 + 1) printf("%lld\n", s1);
			else printf("-1\n");
		}
		else {
			if (amt == n / 2) printf("%lld\n", std::min(s1, s2));
			else printf("-1\n");
		}
	}
	return 0;
}