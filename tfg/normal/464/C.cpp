#include <iostream>
#include <vector>

const int ms = 100100;
const int MOD = 1e9 + 7;

std::string to[ms];
char base[ms];

int value[ms][10];
int size[ms][10];

long long fexp(long long x, int e) {
	long long ans = 0;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	int m;
	std::cin >> str >> m;
	for(int i = 0; i < m; i++) {
		std::string wut;
		std::cin >> wut;
		to[i] = wut.substr(3, wut.size() - 3);
		base[i] = wut[0];
	}
	for(int i = 0; i < 10; i++) {
		value[m][i] = i;
		size[m][i] = 10;
	}
	for(int i = m - 1; i >= 0; i--) {
		for(int j = 0; j < 10; j++) {
			value[i][j] = value[i+1][j];
			size[i][j] = size[i+1][j];
		}
		int x = base[i] - '0';
		value[i][x] = 0;
		size[i][x] = 1;
		for(auto v : to[i]) {
			value[i][x] = ((long long) value[i][x] * size[i+1][v-'0'] + value[i+1][v-'0']) % MOD;
			size[i][x] = (long long) size[i][x] * size[i+1][v-'0'] % MOD;
		}
	}
	int ans = 0;
	for(auto v : str) {
		ans = ((long long) ans * size[0][v-'0'] + value[0][v-'0']) % MOD;
	}
	std::cout << ans << std::endl;
}