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

long long p, q, B;

long long gcd(long long a, long long b){
	while(b > 0){
		a = a % b;
		std::swap(a, b);
	}
	return a;
}

void answer(){
	if(p % q == 0) std::cout << "Finite\n";
	else{
		q /= gcd(p, q);
		long long gc = gcd(q, B);
		while(gc > 1){
			while(q % gc == 0) q /= gc;
			gc = gcd(q, B);
		}
		if(q > 1) std::cout << "Infinite\n";
		else std::cout << "Finite\n";
	}
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	while(n--){
		std::cin >> p >> q >> B;
		answer();
	}
}


int main(){
	read();
	return 0;
}