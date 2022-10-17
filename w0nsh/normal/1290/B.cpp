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

int pref[26][200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	s = "#"+s;
	FOR(c, 26){
		REP(i, 1, SZ(s)){
			pref[c][i] = pref[c][i-1] + (s[i] == 'a'+c ? 1 : 0);
		}
	}
	int q;
	std::cin >> q;
	while(q--){
		int l, r;
		std::cin >> l >> r;
		int ile = 0;
		FOR(i, 26){
			if(pref[i][r]-pref[i][l-1] > 0) ile++;
		}
		if(ile > 2 || l == r || s[l] != s[r]){
			std::cout << "Yes\n";
		}else{
			std::cout << "No\n";
		}
	}

	return 0;
}