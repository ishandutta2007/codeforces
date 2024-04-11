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

std::vector<PR<ll, ll>> get(VI A, int k){
	int n = SZ(A);
	std::vector<PR<ll, ll>> ret;
	TRAV(x, A){
		ll ile = 1;
		while(x % k == 0) ile *= k, x /= k;
		if(SZ(ret) && ret.back().X == x) ret.back().Y += ile;
		else ret.push_back(MP(x, ile));
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, m, k;
		std::cin >> n >> k;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		std::cin >> m;
		VI B(m);
		FOR(i, m) std::cin >> B[i];

		auto a = get(A, k);
		auto b = get(B, k);
		if(a == b) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}