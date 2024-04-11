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

PR<VI, int> op(VI A, int zer){
	VI nw;
	FOR(i, SZ(A)-1) nw.push_back(A[i+1] - A[i]);
	if(zer) nw.push_back(A[0]), zer--;
	std::sort(nw.begin(), nw.end());
	std::reverse(nw.begin(), nw.end());
	while(SZ(nw) > 1 && nw.back() == 0){
		nw.pop_back();
		zer++;
	}
	std::reverse(nw.begin(), nw.end());
	return {nw, zer};
}

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int zer = 0;

	// int ile = 0;
	while(SZ(A) > 1){
		std::tie(A, zer) = op(A, zer);
		// ile++;
	}
	// std::cerr << ile << std::endl;
	std::cout << A.back() << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}