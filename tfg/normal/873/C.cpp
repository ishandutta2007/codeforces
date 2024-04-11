#include <iostream>

const int ms = 400;

int ans[2];
int a[ms][ms];
int n, m, k;

void solve(int* row) {
	for(int i = 1; i < ms; i++) {
		row[i] += row[i - 1];
	}
	int cur_ans = 0;
	int cur_cost = 0;
	for(int i = 1; i < ms / 2; i++) {
		int hmm = row[i + k - 1] - row[i - 1];
		int dude = row[i - 1];
		if(hmm > cur_ans) {
			cur_ans = hmm;
			cur_cost = dude;
		}
	}
	ans[0] += cur_ans;
	ans[1] += cur_cost;
}

int main() {
	std::cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cin >> a[j][i];
		}
	}
	for(int i = 1; i <= m; i++) {
		solve(a[i]);
	}
	std::cout << ans[0] << ' ' << ans[1] << '\n';
}