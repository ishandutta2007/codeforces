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

std::vector<bool> prime;

void solve(){
	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	VI divs;
	divs.push_back(1);
	REP(i, 1, n) if(n % i == 0 && prime[n / i]) divs.push_back(i);

	std::vector<std::multiset<ll>> sets(SZ(divs));
	std::vector<std::vector<ll>> sum(SZ(divs));

	FOR(ind, SZ(divs)){
		int d = divs[ind];
		sum[ind].resize(d);
		FOR(k, d){
			for(int i = k; i < n; i += d){
				sum[ind][k] += A[i];
			}
			sets[ind].insert(sum[ind][k]);
		}
	}

	auto ans = [&]{
		ll ret = 0;
		FOR(ind, SZ(divs)){
			ret = std::max(ret, *std::prev(sets[ind].end()) * divs[ind]);
		}
		return ret;
	};

	std::cout << ans() << "\n";
	FOR(i, q){
		int p, x;
		std::cin >> p >> x;
		p--;
		int delta = x - A[p];
		A[p] = x;

		FOR(ind, SZ(divs)){
			int d = divs[ind];
			sets[ind].erase(sets[ind].find(sum[ind][p % d]));
			sum[ind][p % d] += delta;
			sets[ind].insert(sum[ind][p % d]);
		}

		std::cout << ans() << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	prime.resize(200005, true);
	for(int i = 2; i < 200003; ++i){
		if(prime[i]){
			for(int j = i + i; j < 200003; j += i){
				prime[j] = false;
			}
		}
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}