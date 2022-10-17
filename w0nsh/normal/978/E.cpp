#include <bits/stdc++.h>
#define ll long long
#define FOR(i, n) for(int i =0; i  < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define PR std::pair
#define PII std::pair<int, int>
#define SZ(i) ((int)((i).size()))
#define VI std::vector<int>
#define MP std::make_pair
#define X first
#define Y second

const int INF = 1000000666;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, w;
	std::cin >> n >> w;
	int min = 0;
	int max = 0;
	int pref = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		pref += a;
		max = std::max(max, pref);
		min = std::min(min, pref);
	}
	int ret = std::max(0, w-max+min+1);
	std::cout << ret;
	return 0;
}