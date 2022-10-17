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
	int n;
	std::cin >> n;
	int have = 0;
	std::string s;
	std::cin >> s;
	int ans = 0;
	int last = 0;
	FOR(i, n){
		int cur = (s[i] == '(' ? 1 : -1);
		have += cur;
		if(have < 0){
			last = 1;
			ans++;
		}else{
			if(last == 1) ans++;
			last = 0;
		}
	}
	if(have == 0) std::cout << ans;
	else std::cout << -1;
	return 0;
}