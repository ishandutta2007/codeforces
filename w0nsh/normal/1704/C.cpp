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

void parse(const std::string& s, VI& fs, VI& sc){
	int have = 0;
	TRAV(i, s){
		if(i == '0'){
			have++;
		}else{
			if(fs.empty()) fs.push_back(have);
			else sc.push_back(have);
			have = 0;
		}
	}
	fs.push_back(have);
}

void solve(){
	int n, m;
	std::cin >> n >> m;
	VI A(m);
	FOR(i, m) std::cin >> A[i];


	VI fs, sc;
	fs.push_back(0);
	fs.push_back(0);

	std::sort(A.begin(), A.end());
	FOR(i, SZ(A)-1){
		sc.push_back(A[i+1] - A[i] - 1);
	}
	sc.push_back(A[0] - A.back() + n - 1);

	assert(SZ(fs) == 2);

	std::sort(sc.begin(), sc.end());
	std::reverse(sc.begin(), sc.end());

	int ans = n;
	FOR(mask, 4){
		int cur = n;
		int nw = 0;
		FOR(i, 2) if(mask & (1<<i)) cur -= fs[i] - nw++;
		int i = 0;
		while(i < SZ(sc) && sc[i] - (2 * nw + 1) > 0){
			cur -= sc[i] - (2 * nw + 1);
			nw += 2;
			++i;
		}
		while(i < SZ(sc) && sc[i] - (2 * nw) > 0) {
			cur--;
			nw++;
			++i;
		}

		ans = std::min(ans, cur);
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}