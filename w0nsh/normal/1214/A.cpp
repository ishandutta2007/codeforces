#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

bool can[100000005+1000];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, d, e;
	std::cin >> n >> d >> e;
	e *= 5;
	can[1000] = true;
	REP(i, 1001, n+1+1000){
		can[i] = can[i-d]||can[i-e];
	}
	for(int i = n+1000; i >= 0; --i){
		if(can[i]){
			std::cout << n+1000-i << "\n";
			return 0;
		}
	}
	return 0;
}