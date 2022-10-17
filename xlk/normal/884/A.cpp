#include <bits/stdc++.h>
using namespace std;
int n, t, x;
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		t -= 86400 - x;
		if (t <= 0) {
			printf("%d\n", i);
			break;
		}
	}
}