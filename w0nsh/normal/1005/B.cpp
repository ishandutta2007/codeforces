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

std::string a, b;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> a >> b;
	if(a.size() < b.size()) std::swap(a, b);
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	int num = 0;
	while(a.size() > b.size()){
		a.pop_back();
		num++;
	}
	int cnt = 0;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] != b[i]) break;
		cnt++;
	}
	std::cout << num + (a.size()-cnt)*2 << std::endl;

	return 0;
}