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
	int n, s;
	std::cin >> n >> s;
	
	VI A(n);
	int left = s;
	FOR(i, n){
		A[i] = left/(n-i);
		left -= A[i];
	}

	if(A[0] == 1) std::cout << "NO\n";
	else{
		std::cout << "YES\n";
		FOR(i, n) std::cout << A[i] << " ";
		std::cout << "\n";
		std::cout << 1 << "\n";
	}

	return 0;
}