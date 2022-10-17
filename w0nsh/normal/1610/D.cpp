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

constexpr int MOD = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	constexpr int M = 35;
	VI cnt(M);

	FOR(i, n){
		int ile = 0;
		while(A[i] % 2 == 0) ile++, A[i] /= 2;
		cnt[ile]++;
	}

	VI pw(n+5);
	pw[0] = 1;
	REP(i, 1, n+5) pw[i] = (pw[i-1] + pw[i-1]) % MOD;

	int ans = (1ll * (pw[cnt[0]] - 1) * (pw[n - cnt[0]])) % MOD;
	if(ans < 0) ans += MOD;

	int mn = cnt[0];
	REP(i, 1, M){
		int nw = cnt[i];
		if(nw == 0) continue;

		mn += cnt[i];
		int left = n - mn;

		ans = (ans + 1ll * (pw[nw-1] - 1) * pw[left]) % MOD;
		if(ans < 0) ans += MOD;
	}

	std::cout << ans << "\n";

	return 0;
}