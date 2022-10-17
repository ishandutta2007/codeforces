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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	VI next(n, -1);
	VI ans(n);
	int smal = -1;

	FOR(i, n){
		std::cout << "?";
		FOR(j, n) if(j != i) std::cout << " 1";
			else std::cout << " 2";
		std::cout << std::endl;

		int k;
		std::cin >> k;
		if(k){
			k--;
			if(k != i){
				next[i] = k;
			}
		}
	}

	FOR(i, n){
		std::cout << "?";
		FOR(j, n) if(j != i) std::cout << " 2";
			else std::cout << " 1";
		std::cout << std::endl;

		int k;
		std::cin >> k;
		if(k){
			k--;
			if(k != i){
				next[k] = i;
			}
		}else{
			smal = i;
		}
	}

	assert(smal != -1);
	int pos = smal;
	int ind = 1;
	FOR(_, n){
		ans[pos] = ind++;
		pos = next[pos];
	}

	std::cout << "!";
	FOR(i, n) std::cout << " " << ans[i];
	std::cout << std::endl;


	return 0;
}