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

ll ans;
int n;
std::map<int, int> map;

void cb(int a){
	FOR(i, 26){
		std::cout << (a&(1<<i) ? 1 : 0);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		std::string a;
		std::cin >> a;
		bool cur[26];
		FOR(j, 26) cur[j] = false;
		TRAV(ch, a) cur[ch-'a'] = !cur[ch-'a'];
		int have = 0;
		FOR(j, 26){
			have *= 2;
			if(cur[j]) have++;
		}
		ans += map[have];
		// add
		for(int j = 0; j < 26; ++j)
			if(map.find(have^(1<<j)) != map.end()) ans += map[have^(1<<j)];
		map[have]++;
	}
	std::cout << ans << "\n";
	return 0;
}