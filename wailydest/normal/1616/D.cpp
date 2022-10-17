#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 50005;
int t, n, d[N], x;
long long a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
		scanf("%d", &x);
		std::vector<int> vec;
		vec.push_back(0);
		int pos = 0;
		a[1] -= x;
		for (int i = 1, j = 0; i <= n; ++i) {
			j = std::max(j, pos);
			if (i + 1 <= n) {
				a[i + 1] += a[i] - x;
				int l = 0, r = vec.size() - 1;
				while (l <= r) {
					int m = l + r >> 1;
					if (a[vec[m]] > a[i + 1]) l = m + 1;
					else r = m - 1;
				}
				if (!l) pos = -1;
				else pos = vec[l - 1] + 1;
			}
			while (!vec.empty() && a[i] > a[vec.back()]) vec.pop_back();
			vec.push_back(i);
			d[i] = d[j ? j - 1 : 0] + i - j;
		}
		printf("%d\n", d[n]);
	}
	return 0;
}