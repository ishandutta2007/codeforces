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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str;
	int sz = SZ(str);
	if(sz <= 3){
		std::cout << "Impossible\n";
		return 0;
	}
	bool same = true;
	char last = str[0];
	FOR(i, sz) if(str[i] != last && (sz % 2 == 0 || i != sz/2)) same = false;
	if(same){
		std::cout << "Impossible\n";
		return 0;
	}
	REP(i, 1, sz){
		std::string r = str.substr(0, i);
		std::string l = str.substr(i, sz-i);
		l += r;
		int p1 = (sz-1)/2;
		int p2 = (sz-1)/2 + ((sz-1)%2 == 0 ? 0 : 1);
		bool palin = true;
		while(p1 >= 0){
			if(l[p1] != l[p2]){
				palin = false;
				break;
			}
			p1--;
			p2++;
		}
		if(palin && str != l){
			std::cout << 1 << "\n";
			return 0;
		}
	}
	std::cout << 2 << "\n";
	return 0;
}