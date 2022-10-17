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
	int l, r;
	std::cin >> l >> r;
	VI was(10);
	REP(i, l, r+1){
		int cur = i;
		bool good = true;
		while(cur > 0){
			if(was[cur%10] == i){
				good = false;
				break;
			}
			was[cur%10] = i;
			cur /= 10;
		}
		if(good) {
			std::cout << i << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
	return 0;
}