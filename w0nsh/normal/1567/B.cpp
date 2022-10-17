#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int xr(int a, int b){
	int ret = 0;
	while(a <= b && a % 4 != 0) {
		ret ^= a;
		a++;
	}
	while(a <= b && b % 4 != 3) {
		ret ^= b;
		b--;
	}

	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int a, b;
		std::cin >> a >> b;
		
		int mam = xr(0, a-1);

		mam ^= b;
		if(mam == a){
			std::cout << a + 2 << "\n";
		}else if(mam == 0){
			std::cout << a << "\n";
		}else{
			std::cout << a+1 << "\n";
		}
	}

	return 0;
}