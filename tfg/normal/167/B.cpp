#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef long double ld;

const int ms = 220;

int n, l, k;

ii pa[ms];
int a[ms], p[ms];
bool visit[ms][ms][ms];
ld memo[ms][ms][ms];

ld dp(int on, int won, int spaces) {
	if(spaces < 0) return 0;
	spaces = std::min(n - on, spaces);
	won = std::min(won, l);
	if(on == n) {
		if(won == l) return 1;
		else return 0;
	}
	ld &ans = memo[on][won][spaces];
	if(visit[on][won][spaces]) return ans;
	visit[on][won][spaces] = true;
	ld prob = p[on] / 100.0;
	ans = (1 - prob) * dp(on + 1, won, spaces);
	if(a[on] == -1) {
		ans += prob * dp(on + 1, won + 1, spaces - 1);
	} else {
		ans += prob * dp(on + 1, won + 1, spaces + a[on]);
	}
	return ans;
}

int main() {
	std::cin >> n >> l >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> pa[i].second;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> pa[i].first;
	}
	std::sort(pa, pa + n, std::greater<ii>());
	for(int i = 0; i < n; i++) {
		a[i] = pa[i].first;
		p[i] = pa[i].second;
	}
	std::cout << std::fixed << std::setprecision(20) << dp(0, 0, k) << std::endl;
}