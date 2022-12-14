// really...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t; std::cin>>t; while(t--) [&]{
		int number; std::cin>>number;
		int decrease=INT_MAX, increase=0;
		for(int _=0; _<number; ++_){
			int value; std::cin>>value;
			if(decrease+increase>value){
				decrease-= (decrease+increase-value);
				if(decrease<0){
					std::cout<<"NO\n";
					for(++_;_<number;++_) std::cin>>value;
					return;
				}
			}else
				increase+= value-(decrease+increase);
		}
		std::cout<<"YES\n";
	}();
}