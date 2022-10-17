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

ll go(VI A, VI B){
	std::vector<PII> xd;
	while(SZ(A) || SZ(B)){
		if(SZ(A)){
			xd.push_back(MP(0, A.back()));
			A.pop_back();
		}
		if(SZ(B)){
			xd.push_back(MP(1, B.back()));
			B.pop_back();
		}
	}
	std::reverse(xd.begin(), xd.end());
	ll ans = 0;
	FOR(i, SZ(xd)){
		if(i > 0 && xd[i-1].X != xd[i].X) ans += 2ll * xd[i].Y;
		else ans += xd[i].Y;
	}
	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	VI A(n), B(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];

	VI fs;
	VI sc;
	FOR(i, n){
		if(A[i]) fs.push_back(B[i]);
		else sc.push_back(B[i]);
	}

	std::sort(fs.begin(), fs.end());
	std::sort(sc.begin(), sc.end());
	std::cout << std::max(go(fs, sc), go(sc, fs)) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}