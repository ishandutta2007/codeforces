#include <bits/stdc++.h>
using namespace std;
int n, t, a[105];
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += 86400 - a[i];
		if (ret >= t) {
			printf("%d\n", i);
			break;
		}
	}
}