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
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	VI B(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	VI same;
	TRAV(i, A){
		bool is = false;
		TRAV(j, B) if(i == j) is = true;
		if(is) same.push_back(i);
	}
	std::sort(same.begin(), same.end());
	if(SZ(same)){
		std::cout << same[0] << "\n";
	}else{
		std::cout << std::min(A[0], B[0]) << std::max(A[0], B[0]) << "\n";
	}
	return 0;
}