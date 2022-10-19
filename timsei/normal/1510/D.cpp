#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int id[N][10], n, m, x, y, A[N], d;
long double dp[N][10];
vector <int> ans;

void out(int i, int d) {
	if(i == 1) return;
	if(id[i][d] == -1) {
		out(i - 1, d);
	} else {
		ans.push_back(A[i - 1]);
		out(i - 1, id[i][d]);
	}
}

void pd() {
	for(int i = 1; i <= n; ++ i) if(A[i] == 1) {
		puts("1");
		puts("1");
		return;
	}
	puts("-1");
}

int main() {
	cin >> n >> d;
	for(int i = 1; i <= n + 1; ++ i) {
		for(int j = 0; j <= 9; ++ j) dp[i][j] = -1;
	}
	for(int i = 0; i <= 9; ++ i) dp[1][i] = -1;
	dp[1][1] = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		long double now = log(A[i]);
		for(int j = 0; j < 10; ++ j) {
			if(dp[i][j] < 0) continue;
			if(dp[i + 1][j] < dp[i][j]) {
				id[i + 1][j] = -1;
				dp[i + 1][j] = dp[i][j];
			}
			int it = (A[i] * j) % 10;
			if(dp[i + 1][it] < dp[i][j] + now) {
				dp[i + 1][it] = dp[i][j] + now;
				id[i + 1][it] = j;
			}
		}
	}
	if(dp[n + 1][d] <= 0.001) {
		if(d == 1) {
			pd();
			return 0;
		}
		puts("-1");
		return 0;
	} else out(n + 1, d);
	cout << ans.size() << endl;;
	for(int i = 0; i < (int) ans.size(); ++ i)
	printf("%d ", ans[i]);
	puts("");
}