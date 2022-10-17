#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int a, b, c, d;
		std::cin >> a >>b >> c >> d;
		int mn = a+b;

		std::vector<bool> ans(4, true);

		if(mn % 2 == 0){
			ans[0] = ans[1] = false;
			if(b == 0 && c == 0) ans[2] = false;
			if(a == 0 && d == 0) ans[3] = false;
		}else{
			ans[2] = ans[3] = false;
			if(b == 0 && c == 0) ans[1] = false;
			if(a == 0 && d == 0) ans[0] = false;
		}


		FOR(i, 4) if(ans [i]) std::cout << "Ya "; else std::cout << "Tidak ";
		std::cout << "\n";
	}

	return 0;
}