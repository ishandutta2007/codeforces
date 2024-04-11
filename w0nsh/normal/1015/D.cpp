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

ll n, k, s;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> s;
	if(s > (n-1)*k || s < k) fail();
	ll big = s / (n-1);
	ll more = -1;
	if(s % (n-1) != 0ll) more = s % (n-1);
	std::cout << "YES\n";
	bool start = true;
	std::vector<PR<ll, ll> > moves;
	FOR(i, big){
		if(start) moves.push_back({1, n});
		else moves.push_back({n, 1});
		start = !start;
	}
	if(more != -1){
		if(start) moves.push_back({1, 1+more});
		else moves.push_back({n, n-more});
	}
	ll have = moves.size();
	TRAV(pr, moves){
		if(have < k){
			ll cur = std::abs(pr.X - pr.Y);
			ll need = k - have;
			have += std::min(need, cur - 1);
			ll pos = pr.X;
			FOR(i, std::min(need, cur - 1)){
				if(pr.X < pr.Y) (std::cout << pos+1 << " "), (pos++);
				else (std::cout << pos-1 << " "), (pos--);
			}
			std::cout << pr.Y << " ";
		}else std::cout << pr.Y << " ";
	}
	return 0;
}