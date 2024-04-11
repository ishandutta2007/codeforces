#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int INF = 1000000666;

int ask(int a){
	std::cout << "? " << a << std::endl;
	int x;
	std::cin >> x;
	if(x == 0) x = INF;
	return x;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int left = 1;
	int right = 2005 * 2005;
	while (left < right) {
		int mid = (left + right) / 2;
		if (ask(mid) > 1) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	ll ans = left;
	for (int i = 2; i <= n; ++i) {
		int xd = left / i;
		ans = std::min(ans, 1ll * xd * ask(xd));
	}

	std::cout << "! " << ans << "\n";

	return 0;
}