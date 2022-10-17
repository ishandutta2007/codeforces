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

#define PR std::pair
#define X first
#define Y second

int n, m;
std::vector<int> A;
std::vector<int> left, right;
std::map<int, int> map[2];


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	int mpos = -1;
	for(int i = 0; i < n; ++i){
		int a;
		std::cin >> a;
		A.push_back(a);
		if(a == m) mpos = i;
	}
	int have = 0;
	for(int i = mpos+1; i < n; ++i){
		if(A[i] > m) have++;
		else have--;
		map[0][have]++;
	}
	have = 0;
	for(int i = mpos-1; i >= 0; --i){
		if(A[i] > m) have++;
		else have--;
		map[1][have]++;
	}
	long long ans = 1;
	for(auto kvp : map[0]){
		if(kvp.X == 0 || kvp.X == 1) ans += kvp.Y;
		if(map[1].find(0-kvp.X) != map[1].end()) ans += 1ll*kvp.Y*(map[1].find(0-kvp.X)->Y);
		if(map[1].find(1-kvp.X) != map[1].end()) ans += 1ll*kvp.Y*(map[1].find(1-kvp.X)->Y);
	}
	for(auto kvp : map[1]){
		if(kvp.X == 0 || kvp.X == 1) ans += kvp.Y;
	}
	std::cout << ans << "\n";
	return 0;
}