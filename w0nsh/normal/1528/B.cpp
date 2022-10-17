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

constexpr int MOD = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	int N = n + 5;
	VI d(N);
	for (int i = 1; i < N; ++i) {
		for (int j = 2*i; j < N; j += i) {
			d[j]++;
		}
	}

	std::vector<int> f(N);
	int sum = 2;
	f[0] = 1;
	f[1] = 1;
	REP (i, 2, N) {
		f[i] = (sum + d[i]) % MOD;
		sum = (sum + f[i]) % MOD;
	}

	std::cout << f[n] << "\n";

	return 0;
}