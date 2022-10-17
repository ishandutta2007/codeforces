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
	int n,m;
	std::cin >> n >> m;
	std::set<int> cats;
	FOR(i, n) cats.insert(i);
	VI order;
	for(int i = 0; i < n; i += 2) order.push_back(i);
	for(int i = 1; i < n; i += 2) order.push_back(i);
	FOR(i, m){
		cats.erase(order[i]);
	}
	int ans = 0;
	int last = -20;
	TRAV(i, cats){
		if(i != last+1) ans++;
		last = i;
	}
	std::cout << ans;
	return 0;
}