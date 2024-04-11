// time-limit: 1000
// problem-url: https://codeforces.com/contest/1523/problem/B

// took too long somehow

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
	for(int _=0; _<n; ++_){
		int ai; std::cin>>ai;
	}

	std::cout<<n*3<<'\n';
	for(int i=1; i<n; i+=2){
		std::stringstream s;
		s<<' '<<i<<' '<<i+1<<'\n';
		auto t=std::move(s).str();
		std::cout<<'1'<<t;
		std::cout<<'1'<<t;
		std::cout<<'2'<<t;
		std::cout<<'1'<<t;
		std::cout<<'1'<<t;
		std::cout<<'2'<<t;
	}
}