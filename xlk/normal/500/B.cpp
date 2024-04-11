#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int p[320];
int a[320][320];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int k = 1; k <= n; k++) {	
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] && a[k][j]) {
					a[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int u = i;
		for (int j = i; j <= n; j++) {
			if (a[i][j] == 1 && p[j] < p[u]) {
				u = j;
			}
		}
		swap(p[i], p[u]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", p[i], i == n ? '\n' : ' ');
	}
	return 0;
}