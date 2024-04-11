#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 5;
vector<long long> a[N];
vector<long long> s[N];
int l[N];
int n, m, x;
long long y;
long long fuck(int x, long long h) {
	if (x > n) {
		return 0;
	}
	int p = lower_bound(a[x].begin(), a[x].end(), h) - a[x].begin();
	return p * h - s[x][p];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		scanf("%d", l + i);
	}
	for (int i = n; i > 0; i--) {
		a[i].push_back(0);
		sort(a[i].begin(), a[i].end());
		s[i].resize(a[i].size() + 1);
		for (int j = 0; j < a[i].size(); j++) {
			s[i][j + 1] = s[i][j] + a[i][j];
		}
		if (i > 1) {
			for (int j: a[i]) {
				a[i / 2].push_back(j + l[i]);
			}
		}
	}
	while (m--) {
		scanf("%d%lld", &x, &y);
		long long ans = fuck(x, y);
		for (; x > 1; x /= 2) {
			y -= l[x];
			if (y < 0) {
				break;
			}
			ans += y + fuck(x ^ 1, y - l[x ^ 1]);
		}
		printf("%lld\n", ans);
	}
}