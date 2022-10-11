#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int trans[50][2];
int fail[50];
std::string pat;
long long memo[50][50][50][2];

long long dp(int en, int n, int st, int g) {
	long long &ans = memo[en][n][st][g];
	if(ans != -1) {
		return ans;
	} else if(st == (int) pat.size() && g == 0) {
		return ans = dp(en, n, st, 1);
	} else if(n == 0) {
		return ans = st == en && g == 1 ? 1 : 0;
	} else {
		return ans = dp(en, n - 1, trans[st][0], g) + dp(en, n - 1, trans[st][1], g);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> pat;
	int states = (int) pat.size() + 1;
	trans[0][pat[0] - '0'] = 1;
	for(int i = 1; i < states; i++) {
		fail[i] = i == 1 ? 0 : trans[fail[i - 1]][pat[i - 1] - '0'];
		trans[i][0] = trans[fail[i]][0];
		trans[i][1] = trans[fail[i]][1];
		if(i < (int) pat.size()) {
			trans[i][pat[i] - '0'] = i + 1;
		}
	}
	long long ans = 0;
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < states; i++) {
		ans += dp(i, n, i, 0);
	}
	std::cout << ans << std::endl;
}