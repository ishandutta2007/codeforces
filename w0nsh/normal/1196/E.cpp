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

void solve(int w, int b, int add){
	// if((w-1)/3 + ((w-1)%3 == 0 ? 0 : 1) > b){
	// 	std::cout << "NO\n";
	// 	return;
	// }
	PII pos = MP(3, 3);
	std::vector<PII> wk;
	std::vector<PII> bk;
	while(b > SZ(bk)){
		wk.push_back(pos);
		pos.Y++;
		bk.push_back(pos);
		pos.Y++;
	}
	if(SZ(wk) < w) wk.push_back(pos);
	FOR(i, SZ(bk)){
		if(w == SZ(wk)) break;
		wk.push_back(MP(bk[i].X-1, bk[i].Y));
		if(w == SZ(wk)) break;
		wk.push_back(MP(bk[i].X+1, bk[i].Y));
	}
	if(SZ(wk) < w) std::cout << "NO\n";
	else{
		std::cout << "YES\n";
		TRAV(i, wk) std::cout << i.X+add << " " << i.Y << "\n";
		TRAV(i, bk) std::cout << i.X+add << " " << i.Y << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int b, w;
		std::cin >> b >> w;
		if(b > w) solve(b, w, 1);
		else solve(w, b, 0);
	}
	return 0;
}