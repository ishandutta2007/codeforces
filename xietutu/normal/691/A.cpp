#include <bits/stdc++.h>
using namespace std;
int n, ret;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if (x == 1) ++ret;
	}
	if ((n == 1 && ret == 1) || (n > 1 && ret == n - 1)) printf("YES\n");
	else printf("NO\n");
}