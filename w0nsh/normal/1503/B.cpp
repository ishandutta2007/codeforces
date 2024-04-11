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

void color(int col, PII ps){
	std::cout << col+1 << " " << ps.X+1 << " " << ps.Y+1 << std::endl;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> one, two;
	FOR(i, n){
		FOR(j, n){
			if((i+j)%2) one.push_back(MP(i, j));
			else two.push_back(MP(i, j));
		}
	}
	FOR(_, n*n){
		assert(SZ(two) || SZ(one));
		int a;
		std::cin >> a;
		a--;
		if(SZ(one) && SZ(two)){
			if(a == 0){
				color(1, two.back());
				two.pop_back();
			}else{
				color(0, one.back());
				one.pop_back();
			}
		}else if(SZ(one)){
			color((a == 0 ? 2 : 0), one.back());
			one.pop_back();
		}else{
			color((a == 1 ? 2 : 1), two.back());
			two.pop_back();
		}
	}
	assert(SZ(two) == 0 && SZ(one) == 0);

	return 0;
}