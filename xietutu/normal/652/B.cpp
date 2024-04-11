#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	for (int i = 1; i <= n; ++i)
		if (i % 2) printf("%d ", a[l++]);
		else printf("%d ", a[r--]);
}