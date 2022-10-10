#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const int me = 21;

int to[ms][me];

std::string solve(const std::string &str, int k, int d) {
	int n = (int) str.size();
	std::string ans(n, '#');
	for(int i = 0, pt = -1; i < d; i++) {
		for(int j = i; j < k; j += d) {
			to[j][0] = pt++;
		}
	}
	for(int i = 1; i < me; i++) {
		for(int j = 0; j < k; j++) {
			to[j][i] = to[j][i-1];
			if(to[j][i] != -1) {
				to[j][i] = to[to[j][i]][i-1];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		int pos = i < k ? i : k-1;
		int runs = i < k ? n - k + 1 : n - i;
		int st = i < k ? 0 : i - k + 1;
		for(int j = me; j >= 0; j--) {
			if((1 << j) <= runs && to[pos][j] != -1) {
				runs -= 1 << j;
				st += 1 << j;
				pos = to[pos][j];
			}
		}
		ans[st + pos] = str[i];
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int q;
	std::cin >> q;
	while(q--) {
		int k, d;
		std::cin >> k >> d;
		str = solve(str, k, d);
		std::cout << str << '\n';
	}
}