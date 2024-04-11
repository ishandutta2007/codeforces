#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	std::map<int, int> dp;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i] -= i;
	std::set<int> block;
	FOR(i, k){
		int a;
		std::cin >> a;
		a--;
		block.insert(a);
	}

	int add = 0;
	dp[-2000000000] = 0;
	FOR(i, n){
		if(block.count(i)){
			auto it = dp.upper_bound(A[i]);
			if(it == dp.begin()){
				std::cout << -1 << "\n";
				return 0;
			}
			--it;
			int val = it->Y;
			dp.clear();
			dp[A[i]] = val;
		}else{
			add++;
			auto it = dp.upper_bound(A[i]);
			if(it != dp.begin()){
				it--;
				int val = it->Y;
				if(dp.count(A[i]) == 0) dp[A[i]] = 1000000666;
				dp[A[i]] = std::min(dp[A[i]], val-1);
				
				auto it = dp.lower_bound(A[i]);
				while(true){
					auto nxt = std::next(it);
					if(nxt != dp.end() && it->Y <= nxt->Y){
						dp.erase(nxt);
					}else{
						break;
					}
				}
			}
		}
		
		// std::cout << "po " << i << std::endl;
		// TRAV(pr, dp) std::cout << pr.X << " = " << pr.Y + add << std::endl;
	}

	assert(SZ(dp));
	std::cout << std::prev(dp.end())->Y + add << "\n";

	return 0;
}