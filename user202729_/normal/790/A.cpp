#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	std::vector<int> gr(n);for(int i=n;i--;)gr[i]=i;

	for(int i=0;i<n-k+1;++i){
		char c;std::cin>>c;
		if(c=='Y'){
		}else{
			gr[i+k-1]=gr[i];
		}
		std::cin.ignore(2,' ');
	}

	for(auto x:gr)
		std::cout<<char(x/26+'A')<<char(x%26+'a')<<' ';
	std::cout<<'\n';
}