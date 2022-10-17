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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	VI A(m);
	FOR(i, m) std::cin >> A[i];

	ll sum = 0;
	FOR(i, m) sum += A[i];
	if(sum < n){
		std::cout << -1 << "\n";
		return 0;
	}

	ll pos = 0;
	VI ans;
	FOR(i, m){
		if(pos > n - A[i]){
			std::cout << -1 << "\n";
			return 0;
		}
		ans.push_back(pos);
		sum -= A[i];
		pos = std::max(1ll * pos + 1, 1ll * n - sum);
	}

	TRAV(i, ans) std::cout << i+1 << " ";

	return 0;
}