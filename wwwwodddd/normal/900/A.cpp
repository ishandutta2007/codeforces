#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int a, b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		if (x < 0) {
			a++;
		} else {
			b++;
		}
	}
	if (a <= 1 || b <= 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}