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
	int n, k;
	std::cin >> n >> k;
	std::string a;
	std::cin >> a;
	VI xd;
	FOR(i, n){
		if(a[i] == '0')xd.push_back(i);
	}
	int best = 1000000000;
	FOR(i, SZ(xd)-k){
		int mid = (xd[i]+xd[i+k])/2;
		auto it = std::lower_bound(xd.begin(), xd.end(), mid);
		if(it != xd.end()) best = std::min(best, std::max(xd[i+k]-*it, *it-xd[i]));
		if(it != xd.begin()) --it, best = std::min(best, std::max(xd[i+k]-*it, *it-xd[i]));
	}
	std::cout << best;
	return 0;
}