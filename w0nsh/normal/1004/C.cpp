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

int n;
int nums = 0;
std::vector<int> count;
std::vector<int> A;

void answer(){
	long long ans = 0;
	int ahead = nums;
	std::vector<bool> given(nums, false);
	for(int i = 0; i < n; ++i){
		count[A[i]]--;
		if(count[A[i]] == 0) ahead--;
		if(!given[A[i]])
			ans += ahead;
		given[A[i]] = true;
	}
	std::cout << ans << "\n";
}

void read(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	count.resize(100005);
	std::map<int, int> map;
	for(int i = 0; i < n; ++i){
		std::cin >> A[i];
		if(map.find(A[i]) != map.end()) A[i] = map[A[i]];
		else{
			map[A[i]] = nums++;
			A[i] = map[A[i]];
		}
		count[A[i]]++;
	}
}

int main(){
	read();
	answer();
	return 0;
}