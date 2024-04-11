#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int l,r;std::cin>>l>>r;
		std::cout<<l<<' '<<2*l<<'\n';
	}
}