#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 500005;
const int X = 1000005;
int t, n, a[N], cnt[X], mn[N];
long long ans;
std::vector<int> di[X];

void eval(int l, int r, int m, bool type) {
	mn[m] = ~(1 << 31);
	int mxr, mnr = ~(1 << 31), mnl = mnr;
	for (int i = m, j = m - 1; i < r;) {
		mxr = a[i];
		while (j >= l && (type ? a[j] < mxr : a[j] <= mxr)) {
			mnl = std::min(mnl, a[j]);
			mn[j] = mnl;
			++cnt[mnl];
			--j;
		}
		int total = 0, more = 0, dit;
		for (dit = 0; dit < di[mxr].size(); ++dit) total += cnt[di[mxr][dit]];
		bool any = 1;
		do {
			if (mnr > a[i]) {
				any = 1;
				mnr = std::min(mnr, a[i]);
			}
			while (dit && di[mxr][dit - 1] >= mnr) {
				total -= cnt[di[mxr][dit - 1]];
				--dit;
			}
			if (any) {
				if (!(mxr % mnr)) more = m - (std::lower_bound(mn + j + 1, mn + m, mnr) - mn);
				else more = 0;
			}
			ans += more + total;
			++i;
			any = 0;
		} while (i < r && a[i] <= mxr);
		if (i == r) for (++j; j < m; ++j) cnt[mn[j]] = 0;
	}
}

void calc(int l, int r) {
	if (r - l == 1) return;
	eval(l, r, l + r >> 1, 0);
	std::reverse(a + l, a + r);
	eval(l, r, l + r + 1 >> 1, 1);
	std::reverse(a + l, a + r);
	int m = l + r >> 1;
	calc(l, m);
	calc(m, r);
}

int main() {
	for (int i = 1; i < X; ++i) for (int j = i; j < X; j += i) di[j].push_back(i);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		calc(0, n);
		printf("%lld\n", ans + n);
	}
	return 0;
}