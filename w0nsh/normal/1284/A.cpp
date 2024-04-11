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
	std::vector<std::string> A(n), B(m);
	FOR(i, n){
		std::cin >> A[i];
	
	}
	FOR(i, m) std::cin >> B[i];
	int q;
	std::cin >> q;
	while(q--){
		int a;
		std::cin >> a;
		a--;
		std::cout << A[a%n] << B[a%m] << "\n";
	}
	return 0;
}