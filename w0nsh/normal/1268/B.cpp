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
	ll ans = 0;
	FOR(i, n){
		std::cin >> A[i];
		ans += A[i]/2;
	}
	VI stack;
	FOR(i, n){
		stack.push_back(A[i]%2);
		if(SZ(stack) >= 2 && stack.back() == stack[SZ(stack)-2]){
			if(stack.back() == 1) ans++;
			stack.pop_back();
			stack.pop_back();
		}
	}
	std::cout << ans;
	return 0;
}