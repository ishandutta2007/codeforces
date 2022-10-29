#include <bits/stdc++.h>
using namespace std;
int n, sum[505], a[505];
int main() {
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	int minv = 360;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			int ret = sum[j] - sum[i];
			minv = min(minv, abs(360 - ret - ret)); 
		}
	printf("%d\n", minv);
}