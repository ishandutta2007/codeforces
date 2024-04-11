#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string txt;
std::string pat[3];

const int ms = 251;

int nxt[100100][26];
int dp[ms][ms][ms];

void recalc(int i, int j, int k) {
	dp[i][j][k] = (int) txt.size() + 1;
	if(i) {
		dp[i][j][k] = std::min(dp[i][j][k], nxt[dp[i-1][j][k]][pat[0][i-1] - 'a'] + 1);
	}
	if(j) {
		dp[i][j][k] = std::min(dp[i][j][k], nxt[dp[i][j-1][k]][pat[1][j-1] - 'a'] + 1);
	}
	if(k) {
		dp[i][j][k] = std::min(dp[i][j][k], nxt[dp[i][j][k-1]][pat[2][k-1] - 'a'] + 1);
	}
	if(i + j + k == 0) {
		dp[i][j][k] = 0;
	}
	//std::cout << "dp(" << i << ", " << j << ", " << k << ") = " << dp[i][j][k] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::cin >> txt;
	for(int i = 0; i < 26; i++) {
		nxt[n][i] = n;
		nxt[n+1][i] = n;
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
			nxt[i][j] = nxt[i+1][j];
		}
		nxt[i][txt[i] - 'a'] = i;
	}
	while(q--) {
		char t;
		int i;
		std::cin >> t >> i;
		i--;
		if(t == '+') {
			char cc;
			std::cin >> cc;
			pat[i] += cc;
			if(i == 0) {
				int a = (int) pat[i].size();
				for(int b = 0; b <= (int) pat[1].size(); b++) {
					for(int c = 0; c <= (int) pat[2].size(); c++) {
						recalc(a, b, c);
					}
				}
			} else if(i == 1) {
				int a = (int) pat[i].size();
				for(int b = 0; b <= (int) pat[0].size(); b++) {
					for(int c = 0; c <= (int) pat[2].size(); c++) {
						recalc(b, a, c);
					}
				}
			} else {
				int a = (int) pat[i].size();
				for(int b = 0; b <= (int) pat[0].size(); b++) {
					for(int c = 0; c <= (int) pat[1].size(); c++) {
						recalc(b, c, a);
					}
				}
			}
		} else {
			pat[i].pop_back();
		}
		//std::cout << pat[0] << ", " << pat[1] << ", " << pat[2] << '\n';
		std::cout << (dp[pat[0].size()][pat[1].size()][pat[2].size()] <= (int) txt.size() ? "YES\n" : "NO\n");
	}
}