#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 5000005;
int n, t[N << 2], add[N << 2], d[N];
std::pair<int, int> a[N], b[N];

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
			t[v] = std::max(t[(v << 1) + 1], t[(v << 1) + 2]) + add[v];
		}
	}
}

int query(int l, int r, int v = 0, int tl = 0, int tr = n + 1) 
{
	if (tl >= r || tr <= l) return 0;
	if (tl >= l && tr <= r) return t[v];
	int m = tl + tr >> 1;
	return std::max(query(l, r, (v << 1) + 1, tl, m), query(l, r, (v << 1) + 2, m, tr)) + add[v];
}

int main() 
{
	scanf("%d%d", &n, &a[0].first);
	a[0].second = ~(1 << 31);
	int ans_add = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].second, &a[i].first);
		if (a[i].first <= a[0].first) {
			ans_add += a[i].second >= a[0].first;
			--i;
			--n;
		}
		else if (a[i].second < a[0].first) {
			--i;
			--n;
		}
	}
	std::sort(a, a + n + 1);
	for (int i = 0; i <= n; ++i) b[i] = std::make_pair(a[i].second, i);
	std::sort(b, b + n + 1);
	int ans = 0;
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j <= n && b[j].first < a[i].first) {
			if (b[j].second < i) update(0, b[j].second, -1);
			++j;
		}
		d[i] = query(0, std::lower_bound(a, a + i, std::make_pair(a[i].second + 1, 0)) - a) + 1;
		update(i, i + 1, d[i]);
		ans = std::max(ans, d[i]);
		if (a[i].second >= a[i].first) update(0, i, 1);
	}
	printf("%d\n", ans + ans_add);
	return 0;
}