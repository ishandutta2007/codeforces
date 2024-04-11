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
	int n, m, k;
	std::cin >> n >> m >> k;
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
	}
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
	}

	std::vector<char> op;
	FOR(i, n-1) op.push_back('U');
	FOR(i, m-1) op.push_back('L');
	FOR(i, n){
		if(i%2 == 0){
			FOR(j, m-1) op.push_back('R');
			if(i < n-1) op.push_back('D');
		}else{
			FOR(j, m-1) op.push_back('L');
			if(i < n-1) op.push_back('D');
		}
	}
	assert(SZ(op) <= 2*n*m);
	std::cout << SZ(op) << "\n";
	TRAV(i, op) std::cout << i;


	return 0;
}