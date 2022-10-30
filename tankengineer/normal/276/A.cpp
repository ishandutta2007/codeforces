#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 2000000000;

int main() {
	int n, k, ans = -INF;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int fi, ti;
		scanf("%d%d", &fi, &ti);
		ans = max(ans, fi - max(0, ti - k));
	}
	printf("%d\n", ans);
	return 0;
}