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

	int t;
	std::cin >> t;
	while(t--){
		int n, x;
		std::cin >> n >> x;
		std::multiset<int> set;
		FOR(i, n){
			int a;
			std::cin >> a;
			set.insert(a);
		}

		auto it = set.begin();
		int ans = 0;
		while(it != set.end()){
			int kt = std::min(1000000006ll, 1ll * *it * x);
			auto fnd = set.find(kt);
			if(fnd == set.end()) ans++;
			else set.erase(fnd);
			++it;
		}

		std::cout << ans << "\n";
	}

	return 0;
}