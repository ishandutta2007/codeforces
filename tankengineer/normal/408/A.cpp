#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m[105];

int main() {
	scanf("%d", &n);
	int ans = 999999999;
	for (int i = 0; i < n; ++i) {
		scanf("%d", m + i);
	}
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int j = 0; j < m[i]; ++j) {
			int a;
			scanf("%d", &a);
			t += a * 5 + 15;
		}
		ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}