#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 100005;
typedef pair<int, int> pii;
int n, d;
pii a[maxn];
ll ans, now;
int main() {
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	ans = 0;
	int r = 1;
	ans = a[1].second;
	while (r + 1 <= n && a[r + 1].first - a[1].first < d) ans += a[++r].second;
	now = ans;
	for (int i = 2; i <= n; ++i) {
		now -= a[i - 1].second;
		while (r + 1 <= n && a[r + 1].first - a[i].first < d) now += a[++r].second;
		if (now > ans) ans = now;
	}
	cout << ans << endl;
}