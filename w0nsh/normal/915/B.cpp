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

int n, pos, l, r;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> pos >> l >> r;
	if(n == 1){
		std::cout << 0;
		return 0;
	}
	int ans = 0;
	int dist_left = pos - l;
	if(dist_left < 0) dist_left *= -1;
	int dist_right = r - pos;
	if(dist_right < 0) dist_right *= -1;
	if(pos < l){
		if(r == n) ans = dist_left + 1;
		else ans = dist_right + 2;
	}else if(pos > r){
		if(l == 1) ans = dist_right + 1;
		else ans = dist_left + 2;
	}else{
		if(l == 1 && r == n) ans = 0;
		else if(l == 1){
			ans = dist_right + 1;
		}else if(r == n){
			ans = dist_left + 1;
		}else{
			ans = r - l + std::min(dist_left, dist_right) + 2;
		}
	}
	std::cout << ans << "\n";
	return 0;
}