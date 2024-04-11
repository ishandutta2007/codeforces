#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, l, r;
	std::cin >> n >> l >> r;
	int min = 0;
	int cur = 1;
	int ile = 0;
	FOR(i, n){
		if(ile < l) min += cur;
		else min += 1;
		ile++;
		cur *= 2;
	}
	std::cout << min << " ";
	int max = 0;
	 cur = 1;
	 ile = 0;
	FOR(i, n){
		max += cur;
		ile++;
		if(ile < r) cur *= 2;
	}
	std::cout << max << "\n";
	return 0;
}