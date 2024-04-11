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

int t;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		int n, m, k;
		std::cin >> n >> m >> k;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		VI vals;
		int l = 0;
		m--;
		int r = n-1-m;
		while(r <= n-1){
			vals.push_back(std::max(A[l], A[r]));
			l++;
			r++;
		}
		int max = 0;
		l = 0;
		r = SZ(vals)-1-k;
		r = std::max(r, 0);
		while(r <= SZ(vals)-1){
			int cand = 1000000005;
			REP(x, l, r+1) cand = std::min(cand, vals[x]);
			l++;
			r++;
			max = std::max(max, cand);
		}
		std::cout << max << "\n";
	}
	return 0;
}