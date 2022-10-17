#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n;
std::map<int, int> map;
std::vector<int> vec;
std::vector<PII> A;
std::bitset<100> dp[10005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
		vec.push_back(a);
	}
	TRAV(pr, map) A.push_back(pr);
	if(SZ(A) <= 2){
		std::cout << n << "\n";
		return 0;
	}
	int best = 1;
	// FOR(i, SZ(A)){
	// 	auto pr = A[i];
	// 	if(pr.Y == 1) continue;
	// 	int sum = 0;
	// 	TRAV(val, vec) if(val != pr.X) sum += val;
	// 	int have = pr.Y;
	// 	while(have > 1){
	// 		if(sum != have || have != ){
	// 			best = std::max(best, have);
	// 		}
	// 		have++;
	// 		sum += pr.X;
	// 	}
	// }
	FOR(i, SZ(A)){
		auto pr = A[i];
		if(pr.Y == 1) continue;
		FOR(j, 10005) dp[j].reset();
		int sum = 0;
		TRAV(val, vec) if(val != pr.X){
			sum += val;
			for(int j = 10000; j-val >= 0; --j) dp[j] |= dp[j-val]<<1; 
			dp[val][0] = true;
		}
		REP(j, 2, pr.Y+1){
			for(int k = 10000; k-pr.X >= 0; --k) dp[k] |= dp[k-pr.X]<<1;
			dp[pr.X][0] = true;
			// bool change = dp[sum+(pr.Y-j)*pr.X][0];
			// dp[sum+(pr.Y-j)*pr.X][0] = false;
			// if(dp[sum+(pr.Y-j)*pr.X].none()){
			// 	std::cout << "good XD " << j << "\n";
			// 	best = std::max(best, j);
			// }
			// dp[sum+(pr.Y-j)*pr.X][0] = change;
			if(!dp[j*pr.X][j-1]){
				best = std::max(best, j);
			}
		}
		// dp[sum][0] = false;
		// if(dp[sum].none()) best = std::max(best, pr.Y);
		// dp[sum][0] = true;
	}
	std::cout << best << "\n";
	return 0;
}