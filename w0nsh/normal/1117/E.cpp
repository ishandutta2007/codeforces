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

struct SET{
	std::set<int> pos;
	VI place;
};

int n;
std::string str;
std::vector<SET> A;

std::set<int> pos[26];
void getpos(std::string &s){
	FOR(i, 26) pos[i].clear();
	FOR(i, n) pos[s[i]-'a'].insert(i);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str;
	n = SZ(str);
	A.push_back(SET());
	FOR(i, n) A.back().place.push_back(i), A.back().pos.insert(i);
	FOR(_, 3){
		std::vector<SET> nsets;
		std::string ask;
		FOR(i, n) ask.push_back('a');
		TRAV(set, A){
			FOR(i, SZ(set.place)){
				ask[set.place[i]] = (char)('a'+(i%26));
			}
		}
		std::cout << "? " << ask << std::endl;
		std::string s;
		std::cin >> s;
		getpos(s);
		TRAV(set, A){
			FOR(i, 26){
				SET a = SET();
				TRAV(xd, set.pos){
					if(pos[i].count(xd)) a.pos.insert(xd);
				}
				int ps = i;
				while(ps < SZ(set.place)){
					a.place.push_back(set.place[ps]);
					ps += 26;
				}
				nsets.push_back(a);
			}
		}
		A = nsets;
	}
	std::string ans = "";
	FOR(i, n) ans.push_back('a');
	TRAV(i, A){
		if(SZ(i.place) == 0) continue;
		ans[i.place[0]] = str[*i.pos.begin()];
	}
	std::cout << "! " <<  ans << std::endl;
	return 0;
}