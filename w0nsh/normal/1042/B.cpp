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

struct S{
	bool done[3];
	int c;
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<S> A, B, C, AB, AC, BC;
	int n;
	std::cin >> n;
	std::vector<S> in;
	FOR(i, n){
		int c;
		std::string str;
		std::cin >> c >> str;
		S s;
		s.c = c;
		s.done[0] = str.find('A') != std::string::npos;
		s.done[1] = str.find('B') != std::string::npos;
		s.done[2] = str.find('C') != std::string::npos;
		in.push_back(s);
	}
	FOR(i, n) if(in[i].done[0] && !in[i].done[1] && !in[i].done[2]) A.push_back(in[i]);
	FOR(i, n) if(in[i].done[1] && !in[i].done[0] && !in[i].done[2]) B.push_back(in[i]);
	FOR(i, n) if(in[i].done[2] && !in[i].done[0] && !in[i].done[1]) C.push_back(in[i]);
	FOR(i, n) if(in[i].done[0] && in[i].done[1] && !in[i].done[2]) AB.push_back(in[i]);
	FOR(i, n) if(in[i].done[1] && in[i].done[2] && !in[i].done[0]) BC.push_back(in[i]);
	FOR(i, n) if(in[i].done[2] && in[i].done[0] && !in[i].done[1]) AC.push_back(in[i]);
	int ans = 1000000000*2;
	FOR(i, n) if(in[i].done[1] && in[i].done[2] && in[i].done[0]) ans = std::min(ans, in[i].c);
	TRAV(i, A){
		TRAV(j, B) TRAV(k, C) ans = std::min(ans, i.c+j.c+k.c);
		TRAV(j, BC) ans = std::min(ans, i.c+j.c);
	}
	TRAV(i, B){
		TRAV(j, AC) ans = std::min(ans, i.c+j.c);
	}
	TRAV(i, C){
		TRAV(j, AB) ans = std::min(ans, i.c+j.c);
	}
	TRAV(i, AB) TRAV(j, AC) ans = std::min(ans, i.c+j.c);
	TRAV(i, AB) TRAV(j, BC) ans = std::min(ans, i.c+j.c);
	TRAV(i, AC) TRAV(j, BC) ans = std::min(ans, i.c+j.c);
	if(ans == 1000000000*2) std::cout << -1 << "\n";
	else std::cout << ans << "\n";

	return 0;
}