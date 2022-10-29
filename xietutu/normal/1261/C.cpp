#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[1000005];

vector <vector <int> > sum, mp, chk, fire;

int main() {
	scanf("%d%d", &n, &m);
	
	sum.resize(n + 1);
	mp.resize(n + 1);
	chk.resize(n + 1);
	for (int i = 0; i <= n; ++ i) {
		sum[i].resize(m + 1);
		mp[i].resize(m + 1);
		chk[i].resize(m + 1);
	}
	
	for (int i = 1; i <= n; ++ i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++ j)
			if (s[j] == '.') mp[i][j] = 0;
			else mp[i][j] = 1;
	}
	
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			sum[i][j] = mp[i][j];
			if (i - 1 > 0) sum[i][j] += sum[i - 1][j];
			if (j - 1 > 0) sum[i][j] += sum[i][j - 1];
			if (i - 1 > 0 && j - 1 > 0) sum[i][j] -= sum[i - 1][j - 1];
		}

	// 2 * x + 1 <= min(n, m)
	int l = 0, r = min(n, m) / 2;
	while (r - l + 1 > 0) {
		int mid = (l + r) >> 1;
		int K = mid * 2 + 1;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j) {
				chk[i][j] = 0;
				if (i - K >= 0 && j - K >= 0) {
					if (sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K] == K * K) chk[i][j] = 1;
				}
			}
		for (int i = n; i; -- i)
			for (int j = m; j; -- j) {
				if (i + 1 <= n) chk[i][j] += chk[i + 1][j];
				if (j + 1 <= m) chk[i][j] += chk[i][j + 1];
				if (i + 1 <= n && j + 1 <= m) chk[i][j] -= chk[i + 1][j + 1];
			}
		bool flag = true;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j) {
				int num = chk[i][j];
				if (i + K <= n) num -= chk[i + K][j];
				if (j + K <= m) num -= chk[i][j + K];
				if (i + K <= n && j + K <= m) num += chk[i + K][j + K];
				if (mp[i][j] && (num == 0)) {
					flag = false;
					break;
				}
				if (!mp[i][j]) assert(num == 0);
			}
		if (flag) l = mid + 1;
		else r = mid - 1;
	}
	
	printf("%d\n", r);
	int K = r * 2 + 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			chk[i][j] = 0;
			if (i - K >= 0 && j - K >= 0) {
				if (sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K] == K * K) chk[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (i - r >= 1 && i + r <= n && j - r >= 1 && j + r <= m && chk[i + r][j + r]) printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}