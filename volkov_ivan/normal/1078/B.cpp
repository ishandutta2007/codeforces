#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int MAX_N = 107, MAX_M = 10007, M = 1e9 + 7;
long long dp[MAX_N][MAX_M];
long long c_n_k[MAX_N][MAX_N];
int a[MAX_N];
int used[MAX_N];

void precalc() {
	for (int i = 1; i < MAX_N; i++) c_n_k[i][1] = i;
	for (int i = 1; i < MAX_N; i++) {
		for (int j = 2; j <= i; j++) {
			c_n_k[i][j] = (c_n_k[i - 1][j] + c_n_k[i - 1][j - 1]) % M;
		}
	}
}

int main() {
	precalc();
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i <= 100; i++) used[i] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (used[a[i]] == 0) {
			cnt++;
		}
		used[a[i]]++;
	}
	if (cnt <= 2) {
		cout << n << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_M; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int s = MAX_M - 1; s >= a[i]; s--) {
			for (int j = n; j >= 1; j--) {
				//if (s <= 10 && i == 3) cout << s << ' ' << j << ' ' << dp[j][s] << ' ';
				dp[j][s] = (dp[j][s] + dp[j - 1][s - a[i]]) % M;
				//if (s <= 10 && i == 3) cout << dp[j][s] << endl;
			}
		}
		//cout << dp[1][4] << ' ' << dp[2][8] << endl;
	}
	for (int i = 1; i <= MAX_N; i++) {
		for (int j = 1; j <= used[i]; j++) {
			if (dp[j][i * j] == c_n_k[used[i]][j]) ans = max(ans, j); 
		}
	}
	cout << ans << endl;
	return 0;
}