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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n), B(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, n) std::cin >> B[i];
		std::sort(A.begin(), A.end());
		std::sort(B.begin(), B.end());
		
		auto check = [&](int m){
			int rnd = m + n;
			int ile = rnd - (rnd / 4);

			ll my_score = 0;
			int with_max = std::min(m, ile);
			ile -= with_max;
			my_score += 100ll * with_max;
			assert(ile <= n);
			for(int i = n-1; ile > 0; --ile, --i){
				my_score += A[i];
			}

			ile = rnd - (rnd / 4);
			ll his_score = 0;
			for(int i = n-1; ile > 0 && i >= 0; --ile, --i){
				his_score += B[i];
			}

			return my_score >= his_score;
		};

		int left = 0;
		int right = 1000000000;
		while(left < right){
			int mid = (left+right)/2;
			if(!check(mid)) left = mid+1;
			else right = mid;
		}
		std::cout << left << "\n";
	}

	return 0;
}