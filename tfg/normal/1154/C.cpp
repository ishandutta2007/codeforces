#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int wtf[] = {0, 0, 1, 2, 0, 2, 1};

int sim(int day, int a, int b, int c) {
	if(wtf[day] == 0 && a == 0) return 0;
	if(wtf[day] == 1 && b == 0) return 0;
	if(wtf[day] == 2 && c == 0) return 0;
	return 1 + sim((day+1)%7, a-(wtf[day]==0), b-(wtf[day]==1), c-(wtf[day]==2));
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b, c;
	std::cin >> a >> b >> c;
	long long weeks = std::min(std::min(a / 3, b / 2), c / 2);
	a -= 3 * weeks;
	b -= 2 * weeks;
	c -= 2 * weeks;
	long long bans = weeks * 7;
	long long ans = bans;
	for(int i = 0; i < 7; i++) {
		ans = std::max(ans, bans + sim(i, a, b, c));
	}
	std::cout << ans << '\n';
}