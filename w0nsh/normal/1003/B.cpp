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

int a, b, x;

void read(){
	std::cin >> a >> b >> x;
}

void answer(){
	bool is_zero = true;
	if(a < b) is_zero = false;
	std::string str = "";
	for(int i = 0; i < x+1; ++i){
		if(is_zero){
			a--;
			str += "0";
		}else{
			b--;
			str += "1";
		}
		is_zero = !is_zero;
	}
	while(a > 0){
		str.insert(str.find('0'), "0");
		a--;
	}
	while(b > 0){
		str.insert(str.find('1'), "1");
		b--;
	}
	std::cout << str << "\n";
}

int main(){
	read();
	answer();
	return 0;
}