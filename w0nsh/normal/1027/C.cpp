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


int q, n, a, m1, m2, cnt[10004], best[2];

inline double calc(int x, int y){
	return 4.0*(x+y)*(x+y)/(x*y);
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::multiset<int> set;
	std::cin >> q;
	while(q--){
		std::cin >> n;
		FOR(i, 10004) cnt[i] = 0;
		best[0] = 1000000000;
		best[1] = 1;
		double bbb = calc(best[0], best[1]);
		FOR(i, n){
			std::cin >> a;
			cnt[a]++;
			if(cnt[a] == 2){
				cnt[a] = 0;
				auto it = set.insert(a);
				if(it != set.begin() && calc(*std::next(it, -1), a) <bbb){
					best[0] = *std::next(it, -1);
					best[1] = a;
					bbb = calc(best[0], best[1]);
				}
				if(std::next(it, 1) != set.end() && calc(*std::next(it, 1), a) < bbb){
					best[0] = *std::next(it, 1);
					best[1] = a;
					bbb = calc(best[0], best[1]);
				}
			}
		}
		FOR(i, 2) std::cout << best[i] << " " << best[i] << " ";
		std::cout << "\n";
		set.clear();
	}
	return 0;
}