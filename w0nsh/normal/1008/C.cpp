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

int n;
std::vector<int> A;

void answer(){
int ans = 0;
	int places = 0;
	int this_kind = 0;
	int last = -1;
	for(int i : A){
		if(i != last){
			places += this_kind;
			this_kind = 1;
			last = i;
		}else{
			this_kind++;
		}
		if(places > 0){
			places--;
			ans++;
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	for(int i = 0; i < n; ++i)std::cin >> A[i];
	std::sort(A.begin(), A.end(), std::greater<int>());
	answer();
	return 0;
}