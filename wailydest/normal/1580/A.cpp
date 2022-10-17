#include <cstdio>
#include <algorithm>

const int N = 405;
int t, n, m, amt[N][N];
char s[N];

inline int sum(int x1, int y1, int x2, int y2) 
{
	return amt[x2][y2] - amt[x1 - 1][y2] - amt[x2][y1 - 1] + amt[x1 - 1][y1 - 1];
}

inline int half(int i, int j, int k, int l) 
{
	return sum(i + 1, j + 1, k - 1, l - 1) + k - i + l - j - 2 - sum(i + 1, j, k - 1, j) - sum(i, j + 1, i, l - 1);
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s);
			for (int j = 1; j <= m; ++j) amt[i][j] = amt[i - 1][j] + amt[i][j - 1] - amt[i - 1][j - 1] + (s[j - 1] == '1');
		}
		int ans = 16;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) for (int k = i + 4; k <= n; ++k) for (int l = j + 3; l <= m && half(i, j, k, l) <= ans; ++l) {
			ans = std::min(ans, half(i, j, k, l) + k - i + l - j - 2 - sum(i + 1, l, k - 1, l) - sum(k, j + 1, k, l - 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}