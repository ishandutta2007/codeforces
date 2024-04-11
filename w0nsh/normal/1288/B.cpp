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
	int t;
	std::cin >> t;
	while(t--){
		int a, b;
		std::cin >> a >> b;
		ll num = 9;
		int cnt = 0;
		while(num < 1000000000){
			if(num <= b) cnt++;
			num *= 10;
			num += 9;
		}
		std::cout << 1ll*a*cnt << "\n";
	}
	
	return 0;
}