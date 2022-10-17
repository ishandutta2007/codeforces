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
	std::cin >> n;
	VI A(n);
	int sum = 0;
	FOR(i, n) std::cin >> A[i], sum += A[i];
	int have = A[0];
	VI pr;
	pr.push_back(0);
	REP(i, 1, n){
		if(A[0] >= 2*A[i]){
			pr.push_back(i);
			have += A[i];
		}
	}
	if(have*2 > sum){
		std::cout << SZ(pr) << "\n";
		TRAV(i, pr) std::cout << i+1 << " ";
	}else std::cout << 0;
	return 0;
}