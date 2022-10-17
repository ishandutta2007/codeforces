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
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		int cur = 1;
		VI ans;
		while(n/cur > 0){
			ans.push_back(n/cur);
			int xd = n/cur;
			cur = (n+1)/xd;
			if((n+1)%xd != 0) cur++;
		}
		ans.push_back(0);
		std::sort(ans.begin(), ans.end());
		std::cout << SZ(ans) << "\n";
		FOR(i, SZ(ans)){
			if(i > 0) std::cout << " ";
			std::cout << ans[i];
		}
		std::cout << "\n";
	}
	return 0;
}