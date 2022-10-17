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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int max = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a > max){
			std::cout << i+1 << "\n";
			return 0;
		}
		max = std::max(a+1, max);
	}
	std::cout << -1 << "\n";
	return 0;
}