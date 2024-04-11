// time-limit: 2000
// problem-url: https://codeforces.com/contest/1601/problem/A
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
	std::array<int, 30> count {};
	for(int i=0; i<n; ++i){
		int a; std::cin>>a;
		for(int bit=0; a!=0; ++bit){
			count[bit]+=a&1;
			a>>=1;
		}
	}
	int result {};
	for(auto x: count) result=std::gcd(x, result);

	assert(result<=n);
	if(result==0){
		for(int i=1; i<=n; ++i)
			std::cout<<i<<' ';
	}else{
		for(int i=1; i<=result; ++i)
			if(result%i==0)
				std::cout<<i<<' ';
	}
	std::cout<<'\n';
}