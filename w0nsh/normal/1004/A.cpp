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


int main(){
std::ios_base::sync_with_stdio(false);
	int n, d;
	std::cin >> n >> d;
	std::vector<int> A(n);
	int count = 2;
	for(int i = 0; i < n; ++i) std::cin >> A[i];
	for(int i = 0; i < n-1; ++i){
		int val = std::abs(A[i] - A[i+1]) - 1;
		if(val%2 == 1 && val/2 == d-1) count++;
		else if(val/2 >= d) count += 2;
	}
	std::cout << count << "\n";
	return 0;
}