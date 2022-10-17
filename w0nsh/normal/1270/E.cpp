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

void ans1(std::vector<PII> A){
	VI ans;
	int ind = 1;
	TRAV(i, A){
		if((i.X+i.Y)%2 == 0) ans.push_back(ind);
		ind++;
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	std::exit(0);
}
void ans2(std::vector<PII> A){
	VI ans;
	int ind = 1;
	TRAV(i, A){
		if(i.X%2 == 0) ans.push_back(ind);
		ind++;
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	while(true){
		int np = 0;
		int p = 0;
		TRAV(i, A){
			if((i.X+i.Y)%2 == 0) p++;
			else np++;
		}
		if(np > 0 && p > 0) ans1(A);
		if(p == 0){
			TRAV(i, A) i.X++;
		}
		np = 0;
		p = 0;
		TRAV(i, A){
			if(i.X%2 == 0) p++;
			else np++;
		}
		if(np > 0 && p > 0) ans2(A);
		if(p == 0){
			TRAV(i, A) i.X++, i.Y++;
		}
		TRAV(i, A) i.X /= 2, i.Y /= 2;
	}
	return 0;
}