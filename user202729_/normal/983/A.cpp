#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<numeric>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t nq;std::cin>>nq;
	while(nq--){
		int64_t p,q,base;std::cin>>p>>q>>base;
		{
			auto g=std::gcd(p,q);
			p/=g;q/=g;
		}
		{
			int64_t x=base;
			while(1){
				x=std::gcd(q,x);
				if(x==1) break; else q/=x;
			}
		}
		std::cout<<(q==1 ? "Finite\n" : "Infinite\n");
	}
}