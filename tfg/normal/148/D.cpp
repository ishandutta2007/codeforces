#include <iostream>
#include <iomanip>
#include <vector>

typedef long double ld;

const int ms = 1010;

ld memo[ms][ms][2];
bool visit[ms][ms][2];

ld dp(int n, int m, int t) {
	if(n <= 0 || m < 0) return 0;
	ld &ans = memo[n][m][t];
	if(visit[n][m][t]) return ans;
	visit[n][m][t] = true;
	ans = 0;
	if(t == 0) {
		ans = (ld) n / (n + m) + (ld) m / (n + m) * dp(n, m - 1, 1);
	} else if(n + m > 1 && m > 0) {
		ans = (ld) m / (n + m) * ((ld) n / (n + m - 1) * dp(n - 1, m - 1, 0) + (ld) (m - 1) / (n + m - 1) * dp(n, m - 2, 0));
	}
	//std::cout << "on (" << n << ", " << m << ", " << t << ") got " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cout << std::fixed << std::setprecision(20);
	int n, m;
	std::cin >> n >> m;
	std::cout << dp(n, m, 0) << std::endl;
}