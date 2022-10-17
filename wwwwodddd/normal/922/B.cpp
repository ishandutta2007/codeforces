#include <bits/stdc++.h>
using namespace std;
int n, z;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int k = i ^ j;
			if (j <= k && k <= n) {
				if (i + j > k) {
					z++;
				}
			}
		}
	}
	printf("%d\n", z);
}