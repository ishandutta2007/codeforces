#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[100020];
int a[100020];
int main() {
	scanf("%d", &n);
	int p = 0, q = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[p] < a[i]) {
			q = p;
			p = i;
			c[p]--;
		} else if (a[q] < a[i]) {
			q = i;
			c[p]++;
		}
	}
	int z = 1;
	for (int i = 1; i <= n; i++) {
		if (c[i] > c[z] || c[i] == c[z] && a[i] < a[z]) {
			z = i;
		}
	}
	printf("%d\n", a[z]);
	return 0;
}