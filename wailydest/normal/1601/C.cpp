#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 1000005;
int T, n, m, t[N << 2], tt[N], b[N], add[N << 2];
std::pair<int, int> a[N];

void update(int l, int r, int d, int v = 0, int tl = 0, int tr = n + 1) 
{
	if (!(tl >= r || tr <= l)) {
		if (tl >= l && tr <= r) {
			t[v] += d;
			add[v] += d;
		}
		else {
			int m = tl + tr >> 1;
			update(l, r, d, (v << 1) + 1, tl, m);
			update(l, r, d, (v << 1) + 2, m, tr);
			t[v] = std::min(t[(v << 1) + 1], t[(v << 1) + 2]) + add[v];
		}
	}
}

void inc(int i) 
{
	while (i < n) {
		++tt[i];
		i |= i + 1;
	}
}

int get(int i) 
{
	int s = 0;
	while (i >= 0) {
		s += tt[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() 
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		memset(t, 0, n + 2 << 4);
		memset(add, 0, n + 2 << 4);
		for (int i = 0; i < n; ++i) update(i + 1, n + 1, 1);
		for (int i = 0; i < m; ++i) scanf("%d", b + i);
		std::sort(a, a + n);
		std::sort(b, b + m);
		long long ans = 0;
		for (int i = 0, j = 0, p = 0; i < m; ++i) {
			int l = j;
			while (j < n && a[j].first <= b[i]) {
				update(a[j].second + 1, n + 1, -1);
				++j;
			}
			while (p < n && a[p].first < b[i]) {
				update(0, a[p].second + 1, 1);
				++p;
			}
			ans += *t;
		}
		memset(tt, 0, n + 2 << 2);
		for (int i = 0; i < n;) {
			int j = i;
			do {
				ans += j - get(a[i].second);
				++i;
			} while (i < n && a[i].first == a[i - 1].first);
			for (; j < i; ++j) inc(a[j].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}