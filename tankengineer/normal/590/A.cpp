#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500005;

int n, a[N];

bool stable[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	stable[0] = true;
	stable[n - 1] = true;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && a[j] == a[i]) {
			++j;
		}
		int len = j - i;
		if (len >= 2) {
			for (int k = i; k < j; ++k) {
				stable[k] = true;
			}
		}
		i = j - 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!stable[i]) {
			int j = i;
			while (!stable[j]) {
				++j;
			}
			int len = j - i;
			ans = max(ans, (len + 1) / 2);
			int l = i, r = j - 1;
			while (l <= r) {
				a[l++] = a[i - 1];
				a[r--] = a[j];
			}
			i = j - 1;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}