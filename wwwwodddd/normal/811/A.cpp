#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1;; i++) {
		if (i & 1) {
			n -= i;
			if (n < 0) {
				printf("Vladik\n");
				break;
			}
		} else {
			m -= i;
			if (m < 0) {
				printf("Valera\n");
				break;
			}
		}
	}
	return 0;
}