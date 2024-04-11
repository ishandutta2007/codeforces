#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, d[105], s, t, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", d + i);
		sum += d[i];
	}
	scanf("%d%d", &s, &t);
	--s; --t;
	if (t < s) {
		swap(s, t);
	}
	int ans = 0;
	for (int i = s; i < t; ++i) {
		ans += d[i];
	}
	ans = min(ans, sum - ans);
	printf("%d\n", ans);
	return 0;
}