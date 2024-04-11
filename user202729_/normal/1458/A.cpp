#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int m; std::cin>>m;
	std::vector<int64_t> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	int64_t result{};
	for(auto it: a) result=std::gcd(result, it-a[0]);
	std::vector<int64_t> b(m);
	for(auto& it: b) {
		std::cin>>it;
		std::cout<<std::gcd(a[0]+it, result)<<' ';
	}
}