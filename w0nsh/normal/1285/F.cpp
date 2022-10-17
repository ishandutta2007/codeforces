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

const int M = 100000;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<VI> divs(M+1);
	REP(i, 1, M+1) for(int j = i; j <= M; j += i) divs[j].push_back(i);
	VI lp(M+1);
	VI mob(M+1);
	mob[1] = 1;
	REP(i, 2, M+1){
		if(!lp[i]) for(int j = i; j <= M; j += i) if(!lp[j]) lp[j] = i;
		int cur = i;
		while(cur > 1){
			int cnt = 0;
			int d = lp[cur];
			while(cur%d == 0) cur /= d, ++cnt;
			if(cnt > 1){
				mob[i] = 0;
				break;
			}
			mob[i]++;
		}
		if(mob[i] != 0) mob[i] = (mob[i]%2 ? -1 : 1);
	}
	int n;
	std::cin >> n;
	std::vector<bool> here(M+1);
	ll best = 1;
	FOR(i, n){
		int a;
		std::cin >> a;
		here[a] = true;
		best = std::max(1ll*a, best);
	}
	VI mam(M+1);
	REP(i, 1, M+1){
		VI A;
		for(int j = i; j <= M; j += i)
			if(here[j]) A.push_back(j/i);
		std::reverse(A.begin(), A.end());
		std::stack<int> stack;
		TRAV(a, A){
			int ile = 0;
			TRAV(d, divs[a]) ile += mob[d]*mam[d];
			while(ile > 0){
				assert(SZ(stack));
				if(std::__gcd(stack.top(), a) == 1){
					ile--;
					best = std::max(best, 1ll*a*stack.top()*i);
				}
				TRAV(d, divs[stack.top()]) mam[d]--;
				stack.pop();
			}
			stack.push(a);
			TRAV(d, divs[a]) mam[d]++;
		}
		while(SZ(stack)){
			TRAV(d, divs[stack.top()]) mam[d]--;
			stack.pop();
		}
	}
	std::cout << best << "\n";
	
	return 0;
}