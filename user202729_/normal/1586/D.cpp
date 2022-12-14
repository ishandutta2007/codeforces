// time-limit: 2000
// problem-url: https://codeforces.com/contest/1586/problem/D

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);

	int n; std::cin>>n;
	std::vector<int> value(n);
	for(int i=1; i<n; ++i){
		std::cout<<'?';
		for(int _=0; _<n-1; ++_) std::cout<<" 1";
		std::cout<<' '<<1+i<<'\n';
		int k; std::cin>>k; --k;
		if(k>=0) value[k]=i;

		std::cout<<'?';
		for(int _=0; _<n-1; ++_) std::cout<<' '<<1+i;
		std::cout<<' '<<'1'<<'\n';
		std::cin>>k; --k;
		if(k>=0) value[k]=-i;
	}
	auto const delta=*std::min_element(begin(value), end(value));
	std::cout<<'!';
	for(auto x: value)
		std::cout<<' '<<x-delta+1;
	std::cout<<'\n';




	
}