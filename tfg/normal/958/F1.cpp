#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[105];
int k[105], ksm;
int cnt[105];

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) scanf("%d", c+i), c[i]--;
	for (int i = 0; i < m; ++i) scanf("%d", k+i), ksm += k[i];

	for (int i = 0; i < ksm - 1; ++i) cnt[c[i]]++;
	for (int i = 0; i <= n - ksm; ++i) {
		cnt[c[i+ksm-1]]++;
		int j;
		for (j = 0; j < m; ++j) if (cnt[j] ^ k[j]) break;
		if (j == m) return printf("YES\n"), 0;
		cnt[c[i]]--;
	}

	printf("NO\n");
}