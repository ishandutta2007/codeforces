#include <iostream>
#include <cstdio>

const int ms = 200200;

int a[ms];
long long sum[ms];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	int pos = k;
	long long ans[3] = {-1, -1, -1};
	for(int i = k + 1; i + k - 1 <= n; i++) {
		if(sum[i - 1] - sum[i - k - 1] > sum[pos] - sum[pos - k]) {
			pos = i - 1;
		}
		long long cur = sum[i + k - 1] - sum[i - 1] + sum[pos] - sum[pos - k];
		if(cur > ans[0]) {
			ans[0] = cur;
			ans[1] = pos - k + 1;
			ans[2] = i;
		}
		//std::cout << "on pos " << i << ", got " << cur << std::endl;
	}
	std::cout << ans[1] << ' ' << ans[2] << std::endl;
}