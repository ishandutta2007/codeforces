#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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

	int mod = 1000000007;

	int N = 2000005;
	VI A(N);
	A[1] = A[2] = 1;
	A[3] = 3;
	REP(i, 4, N){
		A[i] = (2ll*A[i-2]+A[i-1])%mod;
		if(i%3 == 1) A[i] = (A[i]+1)%mod;
	}

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		if(n <= 2) std::cout << 0 << "\n";
		else std::cout << (4ll*A[n-2])%mod << "\n";
	}

	return 0;
}