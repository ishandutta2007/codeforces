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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	ll k;
	std::cin >> k;

	ll have = 1;

	std::string a = "codeforces";
	VI ile(SZ(a));
	FOR(i, SZ(a)) ile[i] = 1;
	int pos = 0;
	while(have < k){
		have /= ile[pos];
		ile[pos]++;
		have *= ile[pos];

		pos++;
		if(pos >= SZ(a)) pos = 0;
	}

	FOR(i, SZ(a)){
		FOR(j, ile[i]) std::cout << a[i];
	}

	return 0;
}