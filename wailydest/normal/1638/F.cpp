#include <cstdio>
#include <algorithm>

const int N = 10005;
int n, le[N], ri[N];
bool u[N];
std::pair<long long, int> a[N];
long long h[N], pref[N], mn[N], opt[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i + 1].first);
		h[i] = a[i + 1].first;
		a[i + 1].second = i;
	}
	std::sort(a, a + n + 1);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i];
		long long mn = ~((long long)1 << 63);
		for (int j = i; j >= 0; --j) {
			mn = std::min(mn, h[j]);
			pref[i + 1] = std::max(pref[i + 1], mn * (i - j + 1));
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		long long mn = ~((long long)1 << 63);
		for (int j = i; j < n; ++j) {
			mn = std::min(mn, h[j]);
			ans = std::max(ans, pref[i] + mn * (j - i + 1));
		}
	}
	for (int i = n; i; --i) {
		int id = a[i].second;
		u[id] = 1;
		le[id] = ri[id] = id;
		if (id && u[id - 1]) le[id] = le[id - 1];
		if (id + 1 < n && u[id + 1]) ri[id] = ri[id + 1];
		ri[le[id]] = ri[id];
		le[ri[id]] = le[id];
		int r = ri[id] + 1, l = le[id];
		mn[l] = mn[r - 1] = a[i].first;
		for (int j = l; j > 0; --j) mn[j - 1] = std::min(h[j - 1], mn[j]);
		opt[0] = mn[0] * r;
		for (int j = 1; j < l; ++j) opt[j] = std::max(opt[j - 1], mn[j] * (r - j));
		for (int j = r; j < n; ++j) mn[j] = std::min(mn[j - 1], h[j]);
		opt[n - 1] = (n - l) * mn[n - 1];
		for (int j = n - 2; j >= r; --j) opt[j] = std::max(opt[j + 1], mn[j] * (j - l + 1));
		for (int j = 0, k = r; j < l; ++j) {
			while (k < n && mn[k] + mn[j] > a[i].first) ++k;
			ans = std::max(ans, (r - j) * mn[j] + std::max(opt[k], (k - l) * (a[i].first - mn[j])));
		}
		for (int j = n - 1, k = l; j >= r; --j) {
			while (k >= 0 && mn[k] + mn[j] > a[i].first) --k;
			ans = std::max(ans, (j - l + 1) * mn[j] + std::max(k >= 0 ? opt[k] : 0, (r - k - 1) * (a[i].first - mn[j])));
		}
		for (int j = l - 1, k = r; j >= 0 && k < n;) {
			ans = std::max(ans, std::min(mn[j], mn[k]) * (k - j + 1) + (a[i].first - std::min(mn[j], mn[k])) * (r - l));
			if (j && (k == n - 1 || mn[j - 1] > mn[k + 1])) --j;
			else ++k;
		}
	}
	printf("%lld\n", ans);
	return 0;
}