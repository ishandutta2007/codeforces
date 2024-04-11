#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 52;

// dp(pos, number of numbers, expected carry)
int memo[2][ms][ms*20][ms*10];

std::string str;
int n;

template<const int T>
int dp(int pos, int one, int carry) {
	if(pos == n) return carry == 0 ? 0 : (int) 1e9;
	if(carry+ms*5 >= ms*10 || carry+ms*5 < 0 || one+ms*10 >= ms*20 || one+ms*10 < 0) {
		return 1e9;
	}
	int &ans = memo[T == 1 ? 1 : 0][pos][one+ms*10][carry+ms*5];
	if(ans != -1) return ans;
	ans = std::min(dp<-1>(pos+1, one, carry*10+str[pos]-'0' - one), dp<T>(pos, one+T, carry) + n - pos);
	ans = std::min(dp<1>(pos+1, one, carry*10+str[pos]-'0' - one), ans);
	//std::cout << "at (" << pos << ", " << one << ", " << carry << ") got " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> str;
	str = "0" + str;
	n = (int) str.size();
	memset(memo, -1, sizeof memo);
	std::cout << dp<1>(0, 0, 0) << '\n';
}