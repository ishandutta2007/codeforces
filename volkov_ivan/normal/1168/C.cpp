#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 7, K = 20;
int a[MAX_N];
int dp[MAX_N][K];
int last[K];

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < K; i++) {
		last[i] = n;
		dp[n][i] = n;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < K; j++) dp[i][j] = n;
		for (int j = 0; j < K; j++) {
			if (!(a[i] & (1 << j))) continue;
			int v = last[j];
			dp[i][j] = v;
			for (int t = 0; t < K; t++) dp[i][t] = min(dp[i][t], dp[v][t]);
			last[j] = i;
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		bool flag = 0;
		for (int j = 0; j < K; j++) {
			if (a[r] & (1 << j)) {
				if (dp[l][j] <= r) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "Shi\n";
		else cout << "Fou\n";
	}
	return 0;
}