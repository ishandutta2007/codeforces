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

const int MOD = 1000000007;

int fib[1000005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fib[0] = 1;
	fib[1] = 1;
	REP(i, 2, 1000000) fib[i] = (fib[i-1]+fib[i-2])%MOD;
	std::string s;
	std::cin >> s;
	int cnt = 1;
	char last = '?';
	int ans = 1;
	s.push_back('?');
	TRAV(i, s){
		if(i== 'w' || i == 'm') ans = 0;
		if(i != last){
			if(last == 'n' || last == 'u') ans = (1ll*ans*fib[cnt])%MOD;
			last = i;
			cnt = 1;
		}else cnt++;
	}
	std::cout << ans;
	return 0;
}