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

int moge[105][2];

void solve(){
	int n;
	std::cin >> n;
	std::string a, b;
	std::cin >> a >> b;

	FOR(i, n) FOR(j, 2) moge[i][j] = 0;
	moge[0][0] = a[0] == '0';
	moge[0][1] = b[0] == '0';
	REP(i, 1, n){
		moge[i][0] = (a[i] == '0' && (moge[i-1][0] || moge[i-1][1]));
		moge[i][1] = (b[i] == '0' && (moge[i-1][1] || moge[i-1][0]));
		moge[i][0] |= (a[i] == '0' && moge[i][1]);
		moge[i][1] |= (b[i] == '0' && moge[i][0]);
	}
	
	std::cout << (moge[n-1][1] ? "YES" : "NO") << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}