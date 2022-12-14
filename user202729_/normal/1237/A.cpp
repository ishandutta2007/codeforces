#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int nodd=0;
	std::vector<int> d(n);for(int& x:d){
		std::cin>>x;
		nodd+=(x&1);
	}
	int z=nodd/2;
	for(int x:d){
		int y=x>>1;
		if(x&1){
			--z;
			std::cout<<(z>=0?y+1:y)<<'\n';
		}else
			std::cout<<y<<'\n';
	}
}