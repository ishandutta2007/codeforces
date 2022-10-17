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
	int n, m, p;
	std::cin >>n >> m >> p;
	VI A(n), B(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	FOR(i, n) if(A[i]%p != 0){
		FOR(j, m) if(B[j]%p != 0){
			std::cout << i+j << std::endl;
			return 0;
		}
	}
	return 0;
}