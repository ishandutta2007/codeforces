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

int n, m;
std::vector<std::vector<int> > part;
std::multiset<int> cheapest;
int score = 0;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	if(m == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	part.resize(m);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		a--;
		part[a].push_back(b);
		if(a != 0) cheapest.insert(b);
		else score++;
	}
	FOR(i, m) std::sort(part[i].begin(), part[i].end(), std::greater<int>());
	ll best = 1000000000ll*1000000000ll;
	ll have = 0;
	
	int _mx = 0;
	REP(j, 1, m) _mx = std::max(_mx, SZ(part[j]));
	if(_mx < score){
		std::cout << 0 << "\n";
		return 0;
	}else{
		int need = _mx - score + 1;
		ll cur = 0;
		auto it = cheapest.begin();
		FOR(j, need){
			cur += *it;
			it++;
		}
		best = cur;
	}

	FOR(i, n){
		int max = 0;
		FOR(j, m) if(SZ(part[j]) >= SZ(part[max])){
			if(max == 0 || SZ(part[j]) > SZ(part[max])) max = j;
			else if((SZ(part[j]) > 0 && SZ(part[max]) > 0) && (part[j].back() < part[max].back())) max = j;
		}
		if(max == 0) break;
		have += part[max].back();
		cheapest.erase(cheapest.find(part[max].back()));
		part[max].pop_back();
		max = 0;
		score++;
		REP(j, 1, m) max = std::max(max, SZ(part[j]));
		if(max < score) break;
		int need = max - score + 1;
		ll cur = 0;
		auto it = cheapest.begin();
		FOR(j, need){
			cur += *it;
			it++;
		}
		//std::cout << "iter " << i << " have=" << have << " , cur=" << cur << "\n";
		best = std::min(best, have + cur);
	}
	std::cout << std::min(best, have) << "\n";
	return 0;
}