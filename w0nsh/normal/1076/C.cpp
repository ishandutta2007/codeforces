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

int tests;
int n;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> tests;
	while(tests--){
		std::cout << std::flush;
		std::cin >> n;
		if(n == 0){
			std::cout << "Y 0.000000000000 0.000000000000" << "\n";
			continue;
		}else if(n < 4){
			std::cout << "N\n";
			continue;
		}else if(n == 4){
			std::cout << "Y 2.000000000 2.000000000" << "\n";
			continue;
		}
		double N = n;
		std::cout << "Y ";
		double left = 1.0;
		double right = 2.01;
		while(left + 0.00000000001 < right){
			double mid = (left+right)/2.0;
			double second = N-mid;
			if(mid*second < N) left = mid;
			else right = mid;
		}
		std::cout << std::fixed << std::setprecision(15) << left << " " << N-left << "\n";
	}
	return 0;
}