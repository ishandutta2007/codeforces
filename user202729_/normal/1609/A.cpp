// time-limit: 1000
// problem-url: https://codeforces.com/contest/1609/problem/A
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
	int n; std::cin>>n;
	std::vector<uint64_t> a(n);
	int numEven=0;
	for(auto& it: a) {
		std::cin>>it;
		numEven+=__builtin_ctzll(it);
		it>>=__builtin_ctzll(it);
	}
	*std::max_element(begin(a), end(a))<<=numEven;
	std::cout<<
		std::accumulate(begin(a), end(a), uint64_t(0))
		<<'\n';
	
}