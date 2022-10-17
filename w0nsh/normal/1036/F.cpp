#include <algorithm>
#include <bitset>
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

const ll MAX = 1e18;
std::vector<ll> rest;
std::set<ll> set;

ll sqrt_floor(ll a){
	ll left = 2;
	ll right = 1000000005ll;
	while(left < right){
		ll mid = (left+right)/2;
		if(mid*mid > a) right = mid;
		else left = mid+1;
	}
	return left-1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	REP(i, 3, 60){
		if(i%2 == 0) continue;
		ll cur = 2;
		while(std::pow(cur, i) <= MAX) if(std::pow(sqrt_floor(std::pow(cur, i)), 2) != std::pow(cur, i)) set.insert(std::pow(cur++, i));else cur++;
	}
	TRAV(i, set) rest.push_back(i);
	int q;
	std::cin >> q;
	while(q--){
		ll n;
		std::cin >> n;
		std::cout << n - std::distance(rest.begin(), std::upper_bound(rest.begin(), rest.end(), n)) - sqrt_floor(n) << "\n";
	}
	return 0;
}