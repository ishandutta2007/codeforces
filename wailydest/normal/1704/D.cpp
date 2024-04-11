#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, m;
std::pair<long long, int> a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			a[i].first = 0;
			long long s = 0;
			for (int j = 0; j < m; ++j) {
				int x;
				scanf("%d", &x);
				s += x;
				a[i].first += s;
			}
			a[i].second = i;
		}
		std::sort(a, a + n);
		printf("%d %lld\n", a[0].second + 1, a[1].first - a[0].first);
	}
	return 0;
}