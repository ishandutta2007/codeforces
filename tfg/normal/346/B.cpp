#include <iostream>
#include <cstring>
#include <string>

std::string a, b, virus;

int to[101][26];

int memo[101][101][101];
int use[101][101][101];

int dp(int s1, int s2, int s3) {
	if(s3 == virus.size()) {
		return -1e9;
	} else if(s1 == a.size() || s2 == b.size()) {
		return 0;
	}
	int &ans = memo[s1][s2][s3];
	if(ans != -1) {
		return ans;
	}
	ans = dp(s1 + 1, s2, s3);
	if(ans < dp(s1, s2 + 1, s3)) {
		use[s1][s2][s3] = 1;
		ans = dp(s1, s2 + 1, s3);
	}
	if(a[s1] == b[s2] && ans < 1 + dp(s1 + 1, s2 + 1, to[s3][a[s1] - 'A'])) {
		ans = 1 + dp(s1 + 1, s2 + 1, to[s3][a[s1] - 'A']);
		use[s1][s2][s3] = 2;
	}
	return ans;
}

int main() {
	std::cin >> a >> b >> virus;
	to[0][virus[0] - 'A'] = 1;
	for(int i = 1, l = 0; i < virus.size(); i++) {
		for(int j = 0; j < 26; j++) {
			to[i][j] = to[l][j];
		}
		to[i][virus[i] - 'A'] = i + 1;
		l = to[l][virus[i] - 'A'];
	}
	memset(memo, -1, sizeof memo);
	if(dp(0, 0, 0) == 0) {
		std::cout << "0\n";
	} else {
		for(int s1 = 0, s2 = 0, s3 = 0; s1 < a.size() && s2 < b.size();) {
			if(use[s1][s2][s3] == 0) {
				s1++;
			} else if(use[s1][s2][s3] == 1) {
				s2++;
			} else {
				std::cout << a[s1];
				s3 = to[s3][a[s1] - 'A'];
				s1++;
				s2++;
			}
		}
		std::cout << '\n';
	}
}