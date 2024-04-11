#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 24;
int n, a[N];

int dp[2][24][1 << 12];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);		
	}
if (n == 1) {
	puts(a[0] == 1 ? "YES" : "NO");
	return 0;
}
	sort(a, a + n);
	int leaf = 0, inter = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			++leaf;
		} else {
			++inter;
		}
	}
	if (a[n - 1] != n || inter >= leaf) {
		printf("NO\n");
		return 0;
	}
	memset(dp, 0, sizeof(dp));	
	int now = 0;
	dp[now][leaf][0] = true;
	for (int i = 0; i < inter; ++i) {
		int size = a[leaf + i], next = now ^ 1;
		for (int l = 0; l <= leaf; ++l) {
			for (int st = 0; st < (1 << i); ++st) {
				if (!dp[now][l][st]) {
					continue;
				}
				for (int rst = st; ; rst = (st) & (rst - 1)) {
					int sum = 1, cnt = 0;
					for (int j = 0; j < i; ++j) {
						if (rst >> j & 1) {
							sum += a[leaf + j];
							++cnt;
						}
					}
					if (sum <= size && l + sum >= size) {
						int useleaf = size - sum;
						cnt += useleaf;
						if (cnt >= 2) {
							dp[next][l - useleaf][st ^ rst | (1 << i)] = true;
						}
					}
					if (rst == 0) {
						break;
					}
				}
				dp[now][l][st] = false;
			}
		}
		now = next;
	}
	puts(dp[now][0][1 << inter - 1] ? "YES" : "NO");
	return 0;
}