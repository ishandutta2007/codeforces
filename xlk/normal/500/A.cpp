#include <stdio.h>
#include <iostream>
using namespace std;
int n, t, p;
int a[30020];
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	p = 1;
	while(p < t) {
		p += a[p];
	}
	printf("%s\n", p == t ? "YES" : "NO");
	return 0;
}