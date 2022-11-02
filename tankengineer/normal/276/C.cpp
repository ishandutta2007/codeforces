#include<cstdio>
#include<algorithm>

const int N = 200005;

int n, m;

int a[N], cnt[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		++cnt[l];
		--cnt[r + 1];
	}
	for (int i = 1; i < n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	std::sort(cnt, cnt + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (long long)a[i] * cnt[i];
	}
	printf("%I64d\n", ans);
	return 0;
}