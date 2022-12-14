#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t n;std::cin>>n;
	for(int64_t j=2;j*j<=n;++j){
		if(n%j==0){
			do
				n/=j;
			while(n%j==0);
			if(n==1)
				std::cout<<j<<'\n';
			else
				std::cout<<"1\n";
			return 0;
		}
	}
	std::cout<<n<<'\n';
}