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
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		std::sort(A.begin(), A.end());
		int ans = 0;
		if(n == 1) ans = 1;
		else if(n == 2){
			if(A[0] == A[1]) ans = 2;
			else ans = 1;
		}else{
			int sum = 0;
			FOR(i, n) sum += A[i];
			sum -= A.back();
			if(A.back() > sum) ans = 1;
			else ans = (sum + A.back() + 1)%2+1;
		}

		std::cout << (ans == 1 ? "T" : "HL") << "\n";
	}

	return 0;
}