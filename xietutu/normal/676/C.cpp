#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;
const int maxn = 100010;
char s[maxn];
int n, k, ans, a[maxn];
void work() {
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'b') a[i] = a[i - 1] + 1;
		else a[i] = a[i - 1];
	for (int i = 1; i <= n; ++i) {
		int r;
		if (s[i] == 'a') r = lower_bound(a + i, a + n + 1, a[i] + k + 1) - a;
		else r = lower_bound(a + i, a + n + 1, a[i] + k) - a;
		ans = max(ans, r - i);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	work();
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'a') s[i] = 'b';
		else s[i] = 'a';
	work();
	printf("%d\n", ans);
}