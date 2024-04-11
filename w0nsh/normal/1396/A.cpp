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

	int n;
	std::cin >> n;
	std::vector<ll> A(n);
	FOR(i, n){
		std::cin >> A[i];
	}

	if(n == 1){
		std::cout << "1 1\n1\n1 1\n1\n";
		A[0] += 2;
		std::cout << "1 1\n" << -A[0] << "\n";
		return 0;
	}

	std::cout << "1 " << n << "\n";
	std::cout << "0";
	REP(i, 1, n){
		std::cout << " ";
		ll md = A[i]%(n-1);
		md = (n-1)-md;
		md %= n-1;
		std::cout << md*n;
		A[i] += md*n;
	}
	std::cout << "\n";

	std::cout << "1 1\n";
	std::cout << -A[0] << "\n";

	std::cout << "2 " << n << "\n";
	REP(i, 1, n){
		std::cout << -A[i] << " ";
	}

	return 0;
}