#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
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

int n, m, q, w[15], vals[(1<<12) + 5], ans[500005], k;
std::string str;
std::map<int, int> count;
std::map<int, std::vector<PR<int, int> > > map;

int to_num(const std::string &s){
	int ret = 0;
	int add = 1;
	for(int i = SZ(s)-1; i>=0; --i){
		if(s[i] == '1') ret += add;
		add <<= 1;
	}
	return ret;
}

void calc_vals(){
	FOR(i, 1<<n){
		int have = 0;
		FOR(bit, n) if(i & (1<<bit)) have += w[n-1-bit];
		vals[i] = have;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> q;
	FOR(i, n) std::cin >> w[i];
	calc_vals();
	str.reserve(n);
	FOR(i, m){
		std::cin >> str;
		count[to_num(str)]++;
	}
	FOR(i, q){
		std::cin >> str >> k;
		map[to_num(str)].push_back({k, i});
	}
	TRAV(kvp, map) std::sort(kvp.Y.begin(), kvp.Y.end());
	TRAV(kvp, map){
		std::map<int, int> amount;
		TRAV(pr, count) amount[vals[(~(pr.X^kvp.X))&((1<<n)-1)]] += pr.Y;
		//TRAV(xd, amount) std::cout << kvp.X << " : " << xd.X << " - "<< xd.Y << "\n";
		auto it = kvp.Y.begin();
		auto odp = amount.begin();
		int have = 0;
		while(odp != amount.end() && it != kvp.Y.end()){
			while(odp != amount.end() && it->X >= odp->X) have += (odp++)->Y;
			while(it != kvp.Y.end() && (odp == amount.end() || it->X < odp->X)) ans[(it++)->Y] = have;
		}
	}
	FOR(i, q) std::cout << ans[i] << "\n";
	return 0;
}