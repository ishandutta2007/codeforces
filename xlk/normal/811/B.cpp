#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x;
int p[10020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &l, &r, &x);
		int cnt = 0;
		for (int j = l; j <= r; j++) {
			 if (p[j] < p[x]) {
			 	cnt++;
			 }
		}
		printf("%s\n", cnt == x - l ? "Yes" : "No");
	}
	return 0;
}