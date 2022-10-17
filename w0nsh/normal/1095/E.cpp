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

int n, pref[1000005];
std::string str;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	str.resize(n);
	FOR(i, n) std::cin >> str[i];
	REP(i, 1, n+1) pref[i] = pref[i-1] + (str[i-1] == '(' ? 1 : -1);
	if(pref[n] == -2){
		FOR(i, n) if(pref[i+1] < -2){
			std::cout << 0;
			return 0;
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(str[i-1] == ')') cnt++;
			if(pref[i] < 0) break;
		}
		std::cout << cnt;
	}else if(pref[n] == 2){
		FOR(i, n) if(pref[i+1] < 0){
			std::cout << 0;
			return 0;
		}
		int cnt = 0;
		for(int i = n; i >= 1; --i){
			if(pref[i] < 2) break;
			if(str[i-1] == '(') cnt++;
		}
		std::cout << cnt;
	}else{
		std::cout << 0;
	}
	return 0;
}