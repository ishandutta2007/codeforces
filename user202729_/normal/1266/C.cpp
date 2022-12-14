#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int r,c;std::cin>>r>>c;
	if(r==1 and c==1)
		std::cout<<"0\n";
	else if(c>1){
		for(int i=1;i<=r;++i){
			for(int j=r+1;j<=r+c;++j)
				std::cout<<i*j<<' ';
			std::cout<<'\n';
		}
	}else{
		for(int j=2;j<=r+1;++j)
			std::cout<<j<<'\n';
	}
}