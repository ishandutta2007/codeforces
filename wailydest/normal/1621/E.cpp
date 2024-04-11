#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 100005;
int a[N], tc, n, m, inc[N << 1], t[N << 1];
std::vector<int> v[N];

void add(int l, int r, int d, int v = 0, int tl = 0, int tr = N) 
{
	if (!(tl >= r || tr <= l)) {
		if (tl >= l && tr <= r) {
			inc[v] += d;
			t[v] += d;
		} else {
			int m = tl + tr >> 1;
			add(l, r, d, v + 1, tl, m);
			add(l, r, d, v + (tr - tl & ~1), m, tr);
			t[v] = std::min(t[v + 1], t[v + (tr - tl & ~1)]) + inc[v];
		}
	}
}

int main() 
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			add(0, a[i] + 1, 1);
		}
		for (int i = 0; i < m; ++i) {
			int k;
			scanf("%d", &k);
			v[i].resize(k);
			long long sum = 0;
			for (int j = 0; j < k; ++j) {
				scanf("%d", &v[i][j]);
				sum += v[i][j];
			}
			add(0, (sum - 1) / k + 2, -1);
		}
		for (int i = 0; i < m; ++i) {
			long long sum = 0;
			for (int j = 0; j < (int)v[i].size(); ++j) sum += v[i][j];
			add(0, (sum - 1) / v[i].size() + 2, 1);
			for (int j = 0; j < (int)v[i].size(); ++j) {
				sum -= v[i][j];
				add(0, (sum - 1) / (v[i].size() - 1) + 2, -1);
				if (t[0] >= 0) printf("1");
				else printf("0");
				add(0, (sum - 1) / (v[i].size() - 1) + 2, 1);
				sum += v[i][j];
			}
			add(0, (sum - 1) / v[i].size() + 2, -1);
		}
		printf("\n");
		for (int i = 0; i < m; ++i) {
			long long sum = 0;
			for (int j = 0; j < (int)v[i].size(); ++j) sum += v[i][j];
			add(0, (sum - 1) / v[i].size() + 2, 1);
		}
		for (int i = 0; i < n; ++i) add(0, a[i] + 1, -1);
	}
	return 0;
}