#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;

const int ms = 6060;

int n;
ii a[ms];
int dp[4][ms];

void acum(int* sum) {
	for(int i = 1; i < ms; i++) {
		sum[i] += sum[i - 1];
	}
}

void decum(int* sum) {
	for(int i = ms - 1; i > 0; i--) {
		sum[i] -= sum[i - 1];
	}
}

int qry(int* sum, int l, int r) {
	return sum[r] - sum[l - 1];
}

int to[5];
std::vector<int> solve(int x) {
	std::vector<int> ans;
	memset(dp, 0, sizeof dp);
	dp[0][n + 1]++;
	to[0] = n + 1;
	for(int j = 1; j <= 3; j++) {
		acum(dp[j - 1]);
		int cur_ans = 0;
		for(int i = (3 - j) * x + 1; i <= n; i++) {
			if(qry(dp[j - 1], i + x, i + 2 * x) == 0) {
				continue;
			}
			if(a[i].first - a[i - 1].first > cur_ans) {
				cur_ans = a[i].first - a[i - 1].first;
			}
		}
		ans.push_back(cur_ans);
		for(int i = (3 - j) * x + 1; i <= n; i++) {
			if(qry(dp[j - 1], i + x, i + 2 * x) == 0) {
				continue;
			}
			if(a[i].first - a[i - 1].first == cur_ans) {
				dp[j][i]++;
			}
		}
	}
	ans.push_back(0);
	for(int i = 1; i <= n; i++) {
		if(dp[3][i]) {
			ans.back() = std::max(ans.back(), a[i].first - a[i - 1].first);
			if(ans.back() == a[i].first - a[i - 1].first) {
				to[3] = i;
			}
		}
	}
	to[4] = 1;
	for(int j = 3; j > 0; j--) {
		decum(dp[j - 1]);
		for(int i = to[j] + x; i <= n; i++) {
			if(dp[j - 1][i]) {
				to[j - 1] = i;
				break;
			}
		}
	}
	ans.push_back(x);
	return ans;
}

int typ[ms];
int trans[4] = {1, 2, 3, -1};

int main() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a + 1, a + 1 + n);
	std::vector<int> ans;
	for(int i = 1; i * 3 <= n; i++) {
		ans = std::max(ans, solve(i));
		/*std::cout << i << ":";
		for(auto hmm : ans) {
			std::cout << ' ' << hmm;
		}
		std::cout << '\n';*/
	}
	solve(ans.back());
	for(int j = 3; j >= 0; j--) {
		//std::cout << "[" << to[j + 1] << ", " << to[j] << "[\n";
		for(int i = to[j + 1]; i < to[j]; i++) {
			typ[a[i].second] = trans[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		std::cout << typ[i] << (i == n ? '\n' : ' ');
	}
}