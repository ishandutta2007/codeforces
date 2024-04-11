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

int n, sz;
std::vector<std::string> A;

std::string rotate(std::string str, int a){
	return str.substr(a) + str.substr(0, a);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	sz = SZ(A[0]);
	int best = 2000000666;
	FOR(fst, sz){
		int cnt = fst;
		std::string wzor = rotate(A[0], fst);
		bool bad = false;
		REP(i, 1, n){
			bool good = false;
			FOR(j, sz){
				if(rotate(A[i], j) == wzor){
					good = true;
					cnt += j;
					break;
				}
			}
			if(!good){
				bad = true;
				break;
			}
		}
		if(!bad) best = std::min(best, cnt);
	}
	if(best == 2000000666) std::cout << -1;
	else std::cout << best;
	return 0;
}