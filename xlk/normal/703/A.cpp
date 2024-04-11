#include <bits/stdc++.h>
using namespace std;
int n, sa, sb, a, b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		sa += a > b;
		sb += a < b;
	}
	if (sa > sb) {
		printf("Mishka\n");
	} else if (sa < sb) {
		printf("Chris\n");
	} else {
		printf("Friendship is magic!^^\n");
	}
	return 0;
}