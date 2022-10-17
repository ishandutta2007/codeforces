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

void ans(int what){
	if(what == 0) std::cout << "Alice\n";
	else std::cout << "Bob\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int n, k;
		std::cin >> n >> k;
		// std::vector<bool> win(n+1);
		// win[0] = false;
		// REP(i, 1, n+1){
		// 	win[i] = win[i] || !win[i-1];
		// 	if(i >= 2) win[i] =  win[i] || !win[i-2];
		// 	if(i >= k) win[i] = win[i] || !win[i-k];
		// }
		// FOR(i, n+1) std::cout << i << ": " << win[i] << "\n";
		// std::cout << std::endl;
		if(k % 3 != 0){
			if(n%3 == 0) ans(1);
			else ans(0);
		}else{
			int ile = k/3;
			int jump = ile*3+1;
			n = n%jump;
			if(n%3 == 0 && n != jump-1) ans(1);
			else ans(0);
		}
	}
	return 0;
}