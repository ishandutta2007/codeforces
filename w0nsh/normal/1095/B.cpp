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
	int n;
	VI A;
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	if(n == 2) std::cout << 0 << "\n";
	else{
		std::cout << std::min(A.back()-A[1], A[SZ(A)-2] - A[0]) << "\n";
	}
	return 0;
}