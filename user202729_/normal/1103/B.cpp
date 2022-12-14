#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>

char getchar_(){
	char c;std::cin>>c;return c;
}

int main(){
	std::string st;
	while(true){
		std::cin>>st;
		if(st=="start"){
			std::cout<<"? 0 1\n";
			if(getchar_()=='x'){
				std::cout<<"! 1\n";
			}else{
				int x=1;
				while(2LL*x+1<=1000000000 and (std::cout<<"? "<<x<<' '<<2*x<<'\n', getchar_()=='y'))
					x*=2;
				// now x+1 <= a < 2*x

				int z=2*x; // z%a < x%a
				for(int step=x/2;step!=0;step>>=1){
					std::cout<<"? "<<x<<' '<<z-step<<'\n';
					if(getchar_()=='x')
						z-=step;
				}

				std::cout<<"! "<<z<<'\n';
			}
		}else if(st=="end"||st=="mistake"){
			return 0;
		}else{
			std::cerr<<"??? "<<st<<'\n';
			return 0;
		}
	}
}