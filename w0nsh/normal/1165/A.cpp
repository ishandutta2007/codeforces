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
	int n, x, y;
	std::cin >> n >> x >> y;
	std::string str;
	std::cin >> str;
	std::reverse(str.begin(), str.end());
	int ans = 0;
	FOR(i, x){
		if(i == y && str[i] != '1') ans++;
		if(i != y && str[i] != '0') ans++;
	}
	std::cout << ans;
	return 0;
}