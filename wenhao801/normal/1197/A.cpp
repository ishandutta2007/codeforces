#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
 
int n;
int bucket[100100] = {};
int sum[100100] = {};
 
int main () {
	int T = read();
	while (T--) {
		memset(bucket, 0, sizeof(bucket));
		memset(sum, 0, sizeof(sum));
		n = read();
		int i, j;
		for (i = 1; i <= n; i++)
			bucket[read()]++;
		for (i = 1; i <= 100000; i++)
			sum[i] = sum[i - 1] + bucket[i];
		int ans = 0;
		for (i = n - 2; i >= 1; i--)
			if (sum[100000] - sum[i] >= 2) {
				ans = i;
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}