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

	std::vector<PR<int, PII>> A;

	FOR(i, n){
		int a, b, s;
		std::cin >> a >> b >> s;
		A.push_back(MP(a, MP(b, s)));
		A.push_back(MP(b, MP(-1, -1)));
	}
	std::sort(A.begin(), A.end());

	auto get_pos = [&](int val){
		return (int)(std::lower_bound(A.begin(), A.end(), MP(val, MP(-2, -2))) - A.begin());
	};

	int ans = (A[0].X + 1) % MOD;

	int sum = 1;
	VI where(SZ(A));
	where[0] = 1;

	for(int i = SZ(A)-1; i >= 1; --i){
		int dst = (A[i].X - A[i-1].X) % MOD;

		if(where[i]) assert(A[i].Y.Y == -1);
		sum = (sum - where[i]) % MOD;
		if(sum < 0) sum += MOD;

		int dod = 0;
		if(A[i].Y.Y == 1){
			dod = sum;
		}else if(A[i].Y.Y == 0){
			dod = (1ll * sum - 1 + MOD) % MOD;
		}else{
			dod = 0;
		}

		if(A[i].Y.Y != -1){
			int ind = get_pos(A[i].Y.X);
			where[ind] = (where[ind] + dod) % MOD;
			sum = (sum + dod) % MOD;
		}

		ans = (ans + 1ll * sum * dst) % MOD;
	}

	std::cout << ans << "\n";

	return 0;
}