// http://codeforces.com/contest/1028/problem/E

#include<iostream>
#include<vector>

#ifdef _GLIBCXX_DEBUG
#define cin cin_
#include<sstream>
namespace std{std::stringstream cin(R"(
2
0 0
)");}
#endif

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

	int n;std::cin>>n;
	std::vector<int64_t> b(n);for(int64_t&x:b)std::cin>>x;
	for(int i=0,prev_i=n-1;i<n;prev_i=i++){
		if(b[prev_i]<b[i]){
			// assume b[i]==a[i]
			for(int j=prev_i,prev_j;prev_j=j-1+n*!j,  j!=i;j=prev_j){
				while(b[prev_j]>=b[j]) b[j]+=b[(j+1)%n];
			}
			std::cout<<"YES\n";
			for(auto x:b)std::cout<<x<<' ';
			std::cout<<'\n';

			return 0;
		}
	}
	// all elements are ==
	if(b[0]==0){
		std::cout<<"YES\n";
		for(int i=0;i<n;++i)std::cout<<"1 ";
		std::cout<<'\n';
	}else{
		std::cout<<"NO\n";
	}
}