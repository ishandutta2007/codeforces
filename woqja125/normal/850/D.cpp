#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> ans;
bool dp[32][65][2010];
int p[32][65][2010];
int a[32];
int map[100][100];

int cnt[100]; //  

int main() {
	int m, n;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", a + i);
	sort(a + 1, a + m + 1);
	dp[0][0][0] = 1;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= 64; j++) for (int k = j*(j - 1) / 2; k <= 2000; k++) {
		if (k - a[i] < 0) continue;
		dp[i][j][k] = dp[i][j - 1][k - a[i]];
		if (dp[i - 1][j - 1][k - a[i]]) {
			dp[i][j][k] = true;
			p[i][j][k] = 2;
		}
	}
	for (n = m; n <= 64; n++) {
		if (dp[m][n][n*(n - 1) / 2] == 1) break;
	}
	if (n == 65) {
		printf("=(\n");
		return 0;
	}
	int x = m, s = n*(n-1)/2;
	for (int i = n; i >= 1; i--) {
		ans.push_back(a[x]);
		s -= a[x];
		if (p[x][i][s+a[x]] == 2) x--;
	}
	for (int i = 0; i < n; i++) cnt[i] = n - 1 - ans[n - i - 1];
	vector<pair<int, int>> V;
	for (int i = 0; i < n; i++) {
		int c = ans[n-i-1];
		for (int j = 0; j < i; j++) c -= map[i][j];
		V.clear();
		for (int j = i + 1; j < n; j++) {
			V.emplace_back(-cnt[j], j);
		}
		sort(V.begin(), V.end());
		for (int j = 0; j < V.size(); j++) {
			int x = V[j].second;
			if (j < c) {
				map[i][x] = 1;
				cnt[x]--;
			}
			else {
				map[x][i] = 1;
			}
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d", map[i][j]);
		printf("\n");
	}
	return 0;
}