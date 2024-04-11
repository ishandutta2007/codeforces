#include <bits/stdc++.h>
using namespace std;
int f[1020];
int l[1020];
int cnt[1020];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &f[i]);
		l[f[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] == 0) {
			cnt[f[i]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] < 3 && l[i] == 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}