// time-limit: 1000
// problem-url: https://codeforces.com/contest/1530/problem/A
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	std::string x; std::cin>>x;
	std::cout<<*std::max_element(begin(x), end(x))<<'\n';
}