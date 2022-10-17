#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	PII pos = MP(0, 0);

	std::vector<PII> A;

	std::vector<PII> add{MP(1, 0), MP(2, 0), MP(0, 1), MP(0, 2), MP(2, 1), MP(1, 2)};

	auto xd = [&](PII ps){
		for(auto x : add){
			A.push_back(x+ps);
		}
	};

	xd(pos);
	A.push_back(MP(2, 2));

	FOR(_, n){
		A.push_back(pos);
		pos.X -=2;
		pos.Y -=2;
		xd(pos);
	}

	A.push_back(pos);

	std::cout << SZ(A) << "\n";
	TRAV(i, A) std::cout << i.X << " " << i.Y << "\n";

	return 0;
}