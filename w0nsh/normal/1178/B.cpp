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
	std::string str;
	std::cin >> str;
	int n = SZ(str);
	ll ans = 0;
	VI pre(n), post(n);
	int have = 0;
	REP(i, 1, n){
		if(str[i] == 'v' && str[i-1] == 'v') have++;
		if(str[i] == 'o') pre[i] = have; 
	}
	have = 0;
	for(int i = n-2; i >= 0; --i){
		if(str[i] == 'v' && str[i+1] == 'v') have++;
		if(str[i] == 'o') post[i] = have;
	}
	FOR(i, n){
		if(str[i] == 'o') ans += 1ll*pre[i]*post[i];
	}
	std::cout << ans;
	return 0;
}