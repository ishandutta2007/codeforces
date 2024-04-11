#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int to[2][2];
int in[2], out[2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < 4; i++) {
		int u = i / 2, v = i % 2;
		std::cin >> to[u][v];
		out[u] += to[u][v];
		in[v] += to[v][u];
	}
	int f[2] = {0, 0};
	for(int i = 0; i < 2; i++) {
		while(f[i] * (f[i] - 1) / 2 < to[i][i]) f[i]++;
		if(f[i] * (f[i] - 1) / 2 != to[i][i]) {
			std::cout << "Impossible\n";
			return 0;
		}
	}
	if(to[0][1] || to[1][0]) {
		f[1] = std::max(f[1], 1);
		f[0] = std::max(f[0], 1);
	}
	if(f[0] == 0 && f[1] == 0) {
		f[0] = 1;
	}
	//std::cout << f[0] << ", " << f[1] << '\n';
	std::string ans;
	while(to[0][0] > 0 || to[0][1] > 0 || to[1][0] > 0 || to[1][1] > 0) {
		char ch;
		if(f[1] <= to[1][0]) {
			ch = '0';
		} else {
			ch = '1';
		}
		ans += ch;
		if(ch == '0') {
			f[0]--;
			to[0][0] -= f[0];
			to[1][0] -= f[1];
		} else {
			f[1]--;
			to[0][1] -= f[0];
			to[1][1] -= f[1];
		}
		if(to[0][0] < 0 || to[0][1] < 0 || to[1][1] < 0 || to[1][0] < 0 || f[0] < 0 || f[1] < 0) {
			std::cout << "Impossible\n";
			return 0;
		}
	}
	if(f[0]) {
		f[0]--;
		ans += "0";
	} else if(f[1]) {
		f[1]--;
		ans += "1";
	}
	if(to[0][0] != 0 || to[0][1] != 0 || to[1][0] != 0 || to[1][1] != 0 || f[0] != 0 || f[1] != 0) {
		//std::cout << ans << "!\n";
		ans = "Impossible";
	} else {
		std::reverse(ans.begin(), ans.end());
	}
	std::cout << ans << '\n';
}