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

int n, k;
std::vector<int> A;

void read(){
std::ios_base::sync_with_stdio(false);
	std::cin >> n >> k;
	A.resize(n);
	for(int i = 0; i < n; ++i){
		std::cin >> A[i];
	}
}

std::vector<int> sum;

void answer(){
	sum.resize(n+1);
	for(int i = 0; i < n; ++i){
		sum[i+1] = sum[i] + A[i];
	}
	double max = 0.0;
	for(int i = 0; i < n; ++i){
		for(int j = i+k-1; j < n; ++j){
			max = std::max(max, (double)(sum[j+1] - sum[i]) / (j - i + 1));
		}
	}
	std::cout << std::fixed << std::setprecision(10) << max << "\n";
}

int main(){
	read();
	answer();
	return 0;
}