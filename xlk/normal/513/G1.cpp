#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int a[100];
double dfs(int x) {
	if (x == 0) {
		double re = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					re += 1;
				}
			}
		}
		return re;
	}
	double re = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			reverse(a + i, a + j + 1);
			re += dfs(x - 1);
			reverse(a + i, a + j + 1);			
		}
	}
	return re / ((n + 1) * n / 2);
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%.15f\n", dfs(k));
	return 0;
}