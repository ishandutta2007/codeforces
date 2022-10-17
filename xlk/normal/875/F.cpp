#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
pair<int, pair<int, int> > a[200020];
int f[200020];
int v[200020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
	}
	sort(a, a + m);
	reverse(a, a + m);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x = a[i].second.first;
		int y = a[i].second.second;
		x = F(x);
		y = F(y);
		if (x != y && v[x] + v[y] < 2) {
			f[x] = y;
			v[y] += v[x];
			ans += a[i].first;
		} else if (x == y && v[x] == 0) {
			v[x] = 1;
			ans += a[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}