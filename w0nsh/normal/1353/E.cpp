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

int largest(VI &A){
	int have = 0;
	int best = 0;
	int n = SZ(A);
	FOR(i, n){
		have += A[i];
		have = std::max(have, 0);
		best = std::max(best, have);
	}
	return best;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		int cnt = 0;
		TRAV(i, s) if(i == '1') cnt++;
		int ans = cnt;
		FOR(sh, k){
			VI A;
			int pos = sh;
			while(pos < n){
				A.push_back(s[pos]-'0');
				if(A.back() == 0) A.back() = -1;
				pos += k;
			}
			ans = std::min(ans, cnt-largest(A));
		}
		std::cout << ans << "\n";
	}

	return 0;
}