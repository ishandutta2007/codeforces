#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
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
	int n;
	std::cin >> n;
	VI A(n), B(n);
	int ac = 0, bc = 0;
	FOR(i, n){
		char a;
		std::cin >> a;
		if(a == 'b') A[i] = 1, ac++;
	}
	FOR(i, n){
		char a;
		std::cin >> a;
		if(a == 'b') B[i] = 1, bc++;
	}
	if(ac%2 != bc%2){
		std::cout << -1 << "\n";
		return 0;
	}
	std::vector<PII> ch;
	VI gor, dol;
	FOR(i, n){
		if(A[i] != B[i]){
			if(A[i] == 1) gor.push_back(i);
			else dol.push_back(i);
		}
	}
	while(SZ(dol) >= 2){
		int a = dol.back();
		dol.pop_back();
		int b = dol.back();
		dol.pop_back();
		ch.push_back(MP(a, b));
	}
	while(SZ(gor) >= 2){
		int a = gor.back();
		gor.pop_back();
		int b = gor.back();
		gor.pop_back();
		ch.push_back(MP(a, b));
	}
	if(SZ(dol) == 1){
		ch.push_back(MP(dol.back(), dol.back()));
		ch.push_back(MP(gor.back(), dol.back()));
	}
	std::cout << SZ(ch) << "\n";
	TRAV(i, ch){
		std::cout << i.X+1 << " " << i.Y+1 << "\n";
	}



	return 0;
}