#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	while(n--){
		int64_t a,b;std::cin>>a>>b;
		std::cout<<(a-b==1?"NO\n":"YES\n");
	}
}