#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;

	std::set<int> set;
	FOR(i, n-2) if(s.substr(i, 3) == "abc") set.insert(i);

	FOR(_, q){
		int x;
		char a;
		std::cin >> x >> a;
		x--;

		s[x] = a;

		REP(add, -5, 5){
			int pos = x + add;
			if(pos < 0 || pos >= n-2) continue;
			if(s.substr(pos, 3) != "abc") set.erase(pos);
			else set.insert(pos);
		}

		std::cout << SZ(set) << "\n";
	}

	return 0;
}