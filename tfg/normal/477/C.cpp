#include <iostream>
#include <string>
#include <cstring>

const int eps = 'z' - 'a' + 1;
const int ms = 2020;

std::string t, p;


int dp[ms][ms], nxt[ms][eps];

int main() {
	std::cin >> t >> p;
	for(int i = 0; i < eps; i++) {
		nxt[t.size()][i] = t.size();
	}
	for(int i = t.size() - 1; i >= 0; i--) {
		for(int j = 0; j < eps; j++) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][t[i] - 'a'] = i;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() / p.size() + 3; j++) {
			//std::cout << "dp[" << i << ", " << j << "] = " << dp[i][j] << "\n";
			dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
		}
		int pos = i;
		bool can = true;
		for(int j = 0; j < p.size() && pos <= t.size(); j++) {
			pos = nxt[pos][p[j] - 'a'] + 1;
		}
		//std::cout << "from " << i << " got to " << pos << "\n";
		if(pos <= t.size()) {
			for(int j = 0; j < t.size() / p.size() + 3; j++) {
				dp[pos][j + 1] = std::min(dp[pos][j + 1], dp[i][j] + pos - i - (int)p.size());
			}
		}
	}
	for(int i = 0; i <= t.size(); i++) {
		int cur_ans = 0;
		for(int j = 0; j < t.size() / p.size() + 3; j++) {
			int got = dp[t.size()][j];
			if(got > i || (int) t.size() - i < j * p.size()) {
				continue;
			}
			cur_ans = j;
		}
		std::cout << cur_ans << (i == t.size() ? '\n' : ' ');
	}
}