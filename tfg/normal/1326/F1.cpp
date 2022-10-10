#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 14;
const int ms = 1 << me;

bool mat[me][me];
int bits[ms];
std::vector<long long> dp[ms][me];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) bits[i] = i % 2 + bits[i / 2];
	int n;
	std::cin >> n;
	for(int i = 0; i < (1<<n); i++) {
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) dp[i][j].assign((1<<bits[i]) / 2, 0);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char ch;
			std::cin >> ch;
			mat[i][j] = ch == '1';
		}
		dp[1<<i][i][0] = 1;
	}
	for(int i = 1; i < (1<<n); i++) {
		for(int j = 0; j < n; j++) {
			if((i & (1 << j)) == 0) continue;
			for(int to = 0; to < n; to++) {
				if(i & (1 << to)) continue;
				for(int k = 0; k < (int) dp[i][j].size(); k++) {
					int nxt = mat[j][to] ? k + (1 << (bits[i]-1)) : k;
					dp[i|(1<<to)][to][nxt] += dp[i][j][k];
				}
			}
		}
	}
	for(int i = 0; i < (1 << n) / 2; i++) {
		long long sum = 0;
		for(int j = 0; j < n; j++) {
			sum += dp[(1<<n)-1][j][i];
		}
		std::cout << sum << ' ';
	}
	std::cout << '\n';
}