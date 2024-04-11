#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
typedef pair<int, int> pii;
int n, m, last, a[maxn], b[maxn], p[maxn];
pii ans[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
		a[i] = b[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		b[i] = lower_bound(a + 1, a + n + 1, b[i]) - a;
	
	last = 0;
	for (int i = 1; i <= n; ++i) {
		int type = b[i];
		if (p[type] && p[type] <= last) p[type] = 0;
		if (!p[type]) p[type] = i;
		else {
			ans[++m] = make_pair(last + 1, i);
			last = i;
			p[type] = 0;
		}
	}
	if (m == 0) printf("-1\n");
	else {
		ans[m].second = n;
		printf("%d\n", m);
		for (int i = 1; i <= m; ++i)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
}