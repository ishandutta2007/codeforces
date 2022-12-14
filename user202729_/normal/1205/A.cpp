#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	if(n&1){
		std::cout<<"YES\n";
		int const n2=2*n;
		for(int i=1;i<n2;i+=2)
			std::cout<<(i+(i>>1&1))<<' ';
		for(int i=1;i<n2;i+=2)
			std::cout<<(i+!(i>>1&1))<<' ';
		std::cout<<'\n';
	}else{
		std::cout<<"NO\n";
	}
}