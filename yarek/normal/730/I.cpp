#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int n, a, b, A[MAXN], B[MAXN], dp[MAXN][MAXN], state[MAXN][MAXN], order[MAXN];
vector<int> taken[3];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &B[i]);

	for (int i = 1; i <= n; i++) order[i] = i;

	sort(order+1, order+n+1, [](int x, int y){
		if (A[x] != A[y]) return A[x] > A[y];
		return B[x] > B[y];
	});

	for (int p = 0; p <= n; p++)
		for (int x = 0; x <= b+1; x++)
			dp[p][x] = -1000000000;
	dp[0][0] = 0;

	for (int p = 1; p <= n; p++) {
		int xx = order[p];
		for (int x = 0; x <= min(p, b); x++) {
			if ((x > 0) && (dp[p][x] < dp[p-1][x-1] + B[xx])) {
				dp[p][x] = dp[p-1][x-1] + B[xx];
				state[p][x] = 2;
			}
			if ((p-1-x < a) && (dp[p][x] < dp[p-1][x] + A[xx])) {
				dp[p][x] = dp[p-1][x] + A[xx];
				state[p][x] = 1;
			}
			if (dp[p][x] < dp[p-1][x]) {
				dp[p][x] = dp[p-1][x];
				state[p][x] = 0;
			}
		}
	}

	/*
	for (int p = 1; p <= n; p++) {
		for (int x = 0; x <= min(p, b); x++)
			printf("%3d (%d),  ", dp[p][x], state[p][x]);
		printf("\n");
	}
	*/

	printf("%d\n", dp[n][b]);
	int bb = b;
	for (int nn = n; nn > 0; nn--) {
		taken[state[nn][bb]].push_back(order[nn]);
		if (state[nn][bb] == 2) bb--;
	}

	sort(taken[1].begin(), taken[1].end());
	sort(taken[2].begin(), taken[2].end());

	for (int i = 0; i < taken[1].size(); i++)
		printf("%d ", taken[1][i]);
	printf("\n");
	for (int i = 0; i < taken[2].size(); i++)
		printf("%d ", taken[2][i]);
	printf("\n");

	return 0;
}