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
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}
	TRAV(pr, map) A.push_back(pr.Y);
	std::sort(A.begin(), A.end());
	int best = 0;
	REP(i, 1, n+1){
		int cnt = 0;
		int cur = i;
		auto pos = std::lower_bound(A.begin(), A.end(), cur);
		while(pos != A.end()){
			cnt += cur;
			cur *= 2;
			pos++;
			pos = std::lower_bound(pos, A.end(), cur);
		}
		best = std::max(best, cnt);
	}
	std::cout << best << "\n";
	return 0;
}