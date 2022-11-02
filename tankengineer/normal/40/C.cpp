#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, x, m, y;

int main() {
	scanf("%d%d%d%d", &n, &x, &m, &y);
	if (n < m) {
		swap(n, m);
		swap(x, y);
	}
	int d = abs(x - y);
	long long ans = n + m + 1 - max(min(m, n - d), 0);
	//cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		int l1 = (i <= d) ? d - i + 1 : i - d, r1 = d + i, l2 = 1, r2 = m;
		int ll = max(l1, l2), rr = min(r1, r2);
		int cnt = max(0, rr - ll + 1);
		ans += 2 * cnt - (int)(l1 <= r2) - 2 * (int)(r1 <= r2);
		//cout << i << ' ' << ans << ' ' << cnt << ' ' << l1 << ' ' << r1 << endl;
	}
	cout << ans << endl;
	return 0;
}