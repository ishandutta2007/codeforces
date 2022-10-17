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

bool vo(char a){
	return a == 'a' || a == 'e' || a == 'o' || a == 'i' || a == 'u';
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::map<char, std::vector<PII> > map;
	std::vector<std::string> words;
	FOR(i, n){
		std::string cur, s;
		std::cin >> cur;
		words.push_back(cur);
		TRAV(ch, cur) if(vo(ch)) s.push_back(ch);
		map[s.back()].push_back(MP(SZ(s), i));
	}
	std::vector<PII> notused;
	std::vector<PII> pars;
	TRAV(i, map){
		std::sort(i.Y.begin(), i.Y.end());
		PII last = MP(-1, -1);
		TRAV(a, i.Y){
			if(a.X == last.X){
				pars.push_back(MP(a.Y, last.Y));
				last = MP(-1, -1);
			}else if(last.X == -1){
				last = a;
			}else{
				notused.push_back(last);
				last = a;
			}
		}
		if(last.X != -1) notused.push_back(last);
	}
	std::vector<PII> p2;
	std::sort(notused.begin(), notused.end());
	PII last = MP(-1, -1);
	TRAV(a, notused){
		if(a.X == last.X){
			p2.push_back(MP(a.Y, last.Y));
			last = MP(-1, -1);
		}else{
			last = a;
		}
	}
	std::vector<PR<PII, PII> > final;
	while(SZ(pars) > 0){
		PII sec = pars.back();
		PII fs = MP(-1, -1);
		pars.pop_back();
		if(!p2.empty()) fs = p2.back(), p2.pop_back();
		else if(SZ(pars) > 0) fs = pars.back(), pars.pop_back();
		else break;
		final.push_back(MP(fs, sec));
	}
	std::cout << SZ(final) << "\n";
	TRAV(i, final){
		std::cout << words[i.X.X] << " " << words[i.Y.X] << "\n" << words[i.X.Y] << " " << words[i.Y.Y] << "\n";
	}
	return 0;
}