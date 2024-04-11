#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int w, h, n;
		std::cin >> w >> h >> n;
		ll xd = 1ll*w*h;
		while(w%2 == 0) w >>= 1;
		while(h%2 == 0) h >>= 1;
		if(n <= xd/(1ll*w*h)) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}