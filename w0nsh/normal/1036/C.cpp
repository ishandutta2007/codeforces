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

std::string str;

ll solve(int pos, bool all, int left){
	if(pos >= SZ(str) || left == 0) return 1;
	if(all) return 9ll*solve(pos+1, true, left-1) + solve(pos+1, true, left);
	if(str[pos] == '0') return solve(pos+1, false, left); 
	ll ret = solve(pos+1, true, left);
	if(str[pos] != '1') ret += 1ll*(str[pos]-'1')*solve(pos+1, true, left-1);
	return ret + solve(pos+1, false, left-1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll A, B;
		std::cin >> A >> B;
		str = std::to_string(A-1);
		ll lo = solve(0, false, 3);
		str = std::to_string(B);
		std::cout << solve(0, false, 3) - lo << "\n";
	}
	return 0;
}