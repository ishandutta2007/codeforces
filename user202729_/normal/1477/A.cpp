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
	int n; int64_t k; std::cin>>n>>k;
	std::vector<int64_t> x(n);
	for(auto& it: x) std::cin>>it;
	{
		auto const base=x[0];
		for(auto& it: x) it-=base;
		k-=base;
	}
	int64_t gcd=0;
	for(auto it: x) gcd=std::gcd(gcd, it);
	std::cout<<(k%gcd==0 ? "YES\n": "NO\n");
}