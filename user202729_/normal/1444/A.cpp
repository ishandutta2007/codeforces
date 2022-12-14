// oops...
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
	int64_t p; std::cin>>p;
	int q; std::cin>>q;
	if(p%q!=0) std::cout<<p<<'\n';
	else{
		auto tmp=q;
		int64_t result=1;
		for(int prime=2; tmp!=1; prime=prime*prime<=tmp ? prime+1: tmp) if(tmp%prime==0){
			int exponent{};
			while(tmp%prime==0){
				tmp/=prime;
				++exponent;
			}

			--exponent;
			int tmp2=1;
			while(exponent--) tmp2*=prime;

			assert(p%prime==0);
			auto tmp3=p;
			while(tmp3%prime==0) tmp3/=prime;
			tmp3*=tmp2;

			result=std::max(result, tmp3);
		}
		std::cout<<result<<'\n';
	}
	
}