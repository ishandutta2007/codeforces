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

int dp[100005][2];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string A, B;
		std::cin >> A >> B;
		
		int ans = 0;
		bool zero = false;
		bool one = false;
		FOR(i, n){
			bool z = (A[i] == '0' || B[i] == '0');
			bool o = (A[i] == '1' || B[i] == '1');

			bool cut = false;
			if(zero && one){
				cut = true;
			}else if(zero){
				if(z){
					cut = true;
				}
			}

			if(cut){
				if(zero && one) ans += 2;
				else if(zero) ans += 1;
				zero = false;
				one = false;
			}
			zero |= z;
			one |= o;
		}
		if(zero && one) ans += 2;
		else if(zero) ans += 1;

		std::cout << ans << "\n";
	}

	return 0;
}