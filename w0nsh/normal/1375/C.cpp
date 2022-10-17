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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI stack;
		FOR(i, n){
			int a;
			std::cin >> a;
			if(SZ(stack) == 0) stack.push_back(a);
			else{
				while(SZ(stack) > 1 && stack.back() < a) stack.pop_back();
				if(stack.back() > a) stack.push_back(a);
			}
		}
		bool good = SZ(stack) == 1;
		std::cout << (good ? "YES\n" : "NO\n");
	}

	return 0;
}