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
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	if(*std::max_element(A.begin(), A.end()) == 1){
		std::cout << 	"YES\n";
	}
	else{
		std::cout << "NO\n";
	}

	// VI nw;
	// int last = -1;
	// FOR(i, n){
	// 	nw.push_back(A[i]);
	// 	if(SZ(nw) >= 2 && nw.back() == 0 && nw[SZ(nw)-2] == 0) nw.pop_back();
	// }


}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}