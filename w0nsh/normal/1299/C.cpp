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
typedef long double ld;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<PR<ld, int> > vec;
	std::reverse(A.begin(), A.end());
	std::cout << std::fixed << std::setprecision(12);
	TRAV(i, A){
		PR<ld, int> cur = MP((ld)i, 1);
		while(SZ(vec) && vec.back().X <= cur.X){
			cur = MP((vec.back().X*vec.back().Y+cur.X*cur.Y)/(cur.Y+vec.back().Y), cur.Y+vec.back().Y);
			vec.pop_back();
		}
		vec.push_back(cur);
	}

	while(SZ(vec)){
		FOR(i, vec.back().Y) std::cout << vec.back().X << "\n";
		vec.pop_back();
	}
	

	return 0;
}