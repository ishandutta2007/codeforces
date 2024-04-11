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
	REP(k, 1, 51){
		int cnt = 0;
		FOR(i, n){
			if(A[i] == k) cnt++;
		}
		if(cnt > 0){
			if(cnt > n/2) std::cout << "Bob";
			else std::cout << "Alice";
			return 0;
		}
	}
	return 0;
}