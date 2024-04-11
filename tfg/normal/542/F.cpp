#include <iostream>
#include <utility>
#include <algorithm>

const int ms = 1010;
const int INF = 1e9;
const int mh = 101;

typedef std::pair<int, int> ii;

ii a[ms];

int dp[mh][ms];

int main() {
	int n, t;
	std::cin >> n >> t;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		ans = std::max(ans, a[i].second);
	}
	for(int i = 0; i < mh; i++) {
		for(int j = 0; j < ms; j++) {
			dp[i][j] = -INF;
		}
	}
	for(int i = 1; i < mh; i++) {
		dp[i][0] = 0;
	}
	int pt = mh - 1;
	std::sort(a, a + n);
	for(int i = 0; i < n; i++) {
		int min_time = t - a[i].first;
		if(min_time == 0) {
			break;
		}
		while(pt > min_time) {
			pt--;
			for(int j = 0; j < ms; j++) {
				dp[pt][(j + 1) / 2] = std::max(dp[pt][(j + 1) / 2], dp[pt + 1][j]);
			}
		}
		int cost = a[i].second;
		for(int j = ms - 1; j > 0; j--) {
			dp[min_time][j] = std::max(dp[min_time][j], dp[min_time][j - 1] + cost);
		}
	}
	while(pt > 1) {
		pt--;
		for(int j = 0; j < ms; j++) {
			dp[pt][(j + 1) / 2] = std::max(dp[pt][(j + 1) / 2], dp[pt + 1][j]);
		}
	}
	ans = std::max(ans, std::max(dp[1][1], dp[1][2]));
	std::cout << ans << '\n';//
}