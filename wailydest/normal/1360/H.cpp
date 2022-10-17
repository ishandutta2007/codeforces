#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100, L = 61;
long long a[N];
char buf[L];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int amt = 0;
		for (int i = 0; i < n; ++i) {
			long long k = 1;
			scanf("%s", buf);
			a[i] = 0;
			for (int j = m - 1; j >= 0; --j, k <<= 1) if (buf[j] == '1') a[i] |= k;
			k >>= 1;
			if (a[i] < k) ++amt;
		}
		long long k = (long long)1 << (m - 1);
		sort(a, a + n);
		long long ans;
		if (2 * amt <= n) {
			int x = (n - 2 * amt) / 2;
			long long i = k - 1;
			int j = amt - 1;
			while (j >= 0 && i <= a[j]) {
				if (i == a[j]) --i;
				--j;
			}
			while (x--) {
				--i;
				while (j >= 0 && i == a[j]) {
					if (i == a[j]) --i;
					--j;
				}
			}
			ans = i;
		}
		else {
			int x = (2 * amt - n - 1) / 2;
			long long i = k;
			int j = amt;
			while (j < n && i >= a[j]) {
				if (i == a[j]) ++i;
				++j;
			}
			while (x--) {
				++i;
				while (j < n && i == a[j]) {
					if (i == a[j]) ++i;
					++j;
				}
			}
			ans = i;
		}
		while (k) {
			if (k & ans) printf("1");
			else printf("0");
			k >>= 1;
		}
		printf("\n");
	}
	return 0;
}