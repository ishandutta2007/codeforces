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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<VI> diags;
	diags.push_back(A);
	int min = 1;
	while(SZ(A) > 1){
		VI nw;
		FOR(i, SZ(A)) if(A[i] != min) nw.push_back(A[i]);
		A = nw;
		min++;
		diags.push_back(A);
	}

	assert(SZ(diags) == n);
	FOR(i, n){
		for(int j = i, kt = 0; j >= 0; --j, kt++){
			std::cout << diags[j][kt] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}