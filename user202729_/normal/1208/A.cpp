#include<iostream>
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t;std::cin>>t;
	while(t--){
		int a,b,n;std::cin>>a>>b>>n;
		switch(n%3){
			case 0:std::cout<<a;break;
			case 1:std::cout<<b;break;
			case 2:std::cout<<(a^b);break;
		}
		std::cout<<'\n';
	}
}