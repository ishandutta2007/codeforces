#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int a[200010];
int IT[530010];
int b, n;
int fl(int x) {
	int v = IT[x += b];
	while (x!=0) {
		if (x % 2 == 0) x--;
		x /= 2;
		if ((IT[x] | v) != v) break;
	}
	while (x < b) {
		if ((IT[x * 2 + 1] | v) != v) x = x * 2 + 1;
		else x = x * 2;
	}
	return x - b + 1;
}
int fr(int x) {
	int v = IT[x += b];
	while (x != 0) {
		if (x % 2 == 1) x++;
		x /= 2;
		if ((IT[x] | v) != v) break;
	}
	while (x < b) {
		if ((IT[x * 2] | v) != v) x = x * 2;
		else x = x * 2 + 1;
	}
	return x - b - 1;
}
long long nc2(int n) {
	return 1ll * n*(n - 1) / 2;
}
vector<pair<int, int>> l;
int main() {
	long long ans = 0, t;
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	ans = nc2(n);
	for (b = 1; b <= n; b *= 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		l.emplace_back(a[i], i);
		IT[b + i] = a[i];
	}
	sort(l.begin(), l.end());
	IT[b] = IT[b + n + 1] = 2147483647;
	for (int i = b - 1; i >= 1; i--) IT[i] = (IT[i * 2] | IT[i * 2 + 1]);
	for (int i = 0, j; i < n; i=j) {
		int x, y;
		x = fl(l[i].second) - 1;
		y = fr(l[i].second);
		ans -= nc2(y - x);
		for (j = i; j < n && l[j].first == l[i].first; j++) {
			if (fr(l[j].second) != y) break;
			ans += nc2(l[j].second - x - 1);
			x = l[j].second;
		}
		ans += nc2(y - x);
	}
	printf("%lld\n", ans);
	return 0;
}