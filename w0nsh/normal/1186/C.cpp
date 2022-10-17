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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string a, b;
	std::cin >> a >> b;
	int ans = 0;
	int have = 0;
	FOR(i, SZ(b)) have += (a[i] != b[i] ? 1 : 0);
	int pos = 0;
	FOR(i, SZ(b)-1) if(b[i] != b[i+1]) pos++;
	have %= 2;
	pos %= 2;
	if(have == 0) ans++;
	REP(i, SZ(b), SZ(a)){
		have += pos;
		int nw = (b.back() == a[i] ? 0 : 1);
		if(b[0] != a[i-SZ(b)]) have++;
		if(nw == 1) have++;
		have %= 2;
		if(have == 0) ans++;
	}
	std::cout << ans;
	return 0;
}