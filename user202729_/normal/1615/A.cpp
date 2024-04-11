// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/A
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
	int number; std::cin>>number;
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	std::cout<<(std::accumulate(begin(a), end(a),(int64_t)0)%number==0 ? 0: 1)<<'\n';
}