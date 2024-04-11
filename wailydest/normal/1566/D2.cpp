#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 300;
const int NN = 90000;
int t, n, m, b[N][N], pos[NN];
std::pair<int, int> a[NN];

void add(int ind, int i) 
{
	while (i < m) {
		++b[ind][i];
		i |= i + 1;
	}
}

int get(int ind, int i) 
{
	int s = 0;
	while (i >= 0) {
		s += b[ind][i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) memset(b[i], 0, m << 2);
		for (int i = 0; i < n * m; ++i) {
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		std::sort(a, a + n * m);
		for (int i = 0; i < n * m;) {
			int j = i;
			do {
				++i;
			} while (i < n * m && i / m == (i - 1) / m && a[i].first == a[i - 1].first);
			for (int k = j; k < i; ++k) pos[a[k].second] = i + j - k - 1;
		}
		long long ans = 0;
		for (int i = 0; i < n * m; ++i) {
			ans += get(pos[i] / m, pos[i] % m);
			add(pos[i] / m, pos[i] % m);
		}
		printf("%lld\n", ans);
	}
	return 0;
}