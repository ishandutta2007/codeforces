#include <bits/stdc++.h>
using namespace std;
int n;
int a[5020];
int first[5020];
int last[5020];
int f[5020];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (first[a[i]] == 0) {
			first[a[i]] = i;
		}
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i], f[i - 1]);
		if (first[a[i]] == i) {
			int XOR = 0;
			int cnt = 0;
			for (int j = i; j <= n; j++) {
				if (first[a[j]] == j) {
					XOR ^= a[j];
					cnt++;
				}
				if (first[a[j]] < i) {
					break;
				}
				if (last[a[j]] == j) {
					cnt--;
				}
				if (cnt == 0) {
//					printf("%d %d %d\n", i, j, XOR);
					f[j] = max(f[j], f[i - 1] + XOR);
				}
			}
		}
	}
	printf("%d\n", f[n]);
	return 0;
}