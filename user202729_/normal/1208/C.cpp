#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	for(int i=0,maxi=n*n;i<maxi;i+=2*n){
		for(int j=i,maxj=i+2*n;j<maxj;j+=4)
			std::cout<<j<<' '<<j+1<<' ';
		std::cout<<'\n';
		for(int j=i,maxj=i+2*n;j<maxj;j+=4)
			std::cout<<j+2<<' '<<j+3<<' ';
		std::cout<<'\n';
	}
}