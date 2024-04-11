#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<chrono>
#include<random>
std::mt19937 engine( std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count());

int main(){
	int64_t n;int maxmove;
	std::cin>>n>>maxmove;

	int64_t l=1,r=n; // inclusive endpoints
	while(true){
		l=std::max((int64_t)1,l-maxmove);
		r=std::min(n,r+maxmove);

		if(r-l>4*(maxmove+1)){
			auto mid=(l+r)/2;
			std::cout<<l<<' '<<mid <<'\n';
			std::string s;std::cin>>s;
			switch(s[0]){
				case 'y':case 'Y':
					r=mid;
					break;
				case 'n':case 'N':
					l=mid+1;
					break;
				case 'b':case 'B':
					return 1;
			}
		}else{
			auto x=std::uniform_int_distribution{l,r}(engine);
			std::cout<<x<<' '<<x<<'\n';
			std::string s;std::cin>>s;
			switch(s[0]){
				case 'y':case 'Y':
					return 0;
				case 'n':case 'N':
					break;
				case 'b':case 'B':
					return 1;
			}
		}
	}
}