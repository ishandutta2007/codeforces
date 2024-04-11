#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	VI ile(2);
	FOR(i, n) ile[A[i]]++;
	FOR(_, q){
		int what;
		std::cin >> what;
		if(what == 1){
			int x;
			std::cin >> x;
			x--;
			ile[A[x]]--;
			A[x] = 1-A[x];
			ile[A[x]]++;
		}else{
			int k;
			std::cin >> k;
			if(ile[1] >= k) std::cout << 1 << "\n";
			else std::cout << 0 << "\n";
		}
	}

	return 0;
}