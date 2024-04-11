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

void solve(){
	int n;
	std::cin >> n;
	std::vector<PII> A(3);
	VI x(3), y(3);
	FOR(i, 3){
		std::cin >> A[i].X >> A[i].Y;
		x[i] = A[i].X;
		y[i] = A[i].Y;
	}

	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());

	PII pt = MP(x[1], y[1]);

	PII ot;
	std::cin >> ot.X >> ot.Y;

	if(pt == MP(1, 1) || pt == MP(n, 1) || pt == MP(1, n) || pt == MP(n, n)){
		if(ot.X == pt.X || ot.Y == pt.Y) std::cout << "YES\n";
		else std::cout << "NO\n";
	}else{
		if(ot.X % 2 == pt.X % 2 || ot.Y % 2 == pt.Y % 2) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}