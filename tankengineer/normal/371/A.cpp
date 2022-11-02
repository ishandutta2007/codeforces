#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, cnt[105][2];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++cnt[i % k][a - 1];
	}
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += min(cnt[i][0], cnt[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}