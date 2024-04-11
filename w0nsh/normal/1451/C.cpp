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
		int n, k;
		std::cin >> n >> k;
		std::string a, b;
		std::cin >> a >> b;
		std::map<char, int> map, want;

		auto get = [&](std::string s, std::map<char, int>& siema){
			TRAV(c, s) siema[c]++;
		};
		get(a, map);
		get(b, want);
		bool good = true;
		REP(ch, 'a', 'z'+1){
			if(map[ch] < want[ch]){
				good = false;
				break;
			}
			int more = (map[ch]-want[ch]);
			if(more % k != 0){
				good = false;
				break;
			}
			map[ch+1] += more;
		}

		std::cout << (good ? "YES\n" : "NO\n");
	}
	return 0;
}