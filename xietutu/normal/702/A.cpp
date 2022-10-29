#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[100010];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
	ans = m = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] > a[i - 1]) ++m;
		else m = 1;
		ans = max(ans, m);
	}
	printf("%d\n", ans);
}