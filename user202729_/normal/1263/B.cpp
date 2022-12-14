#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t;std::cin>>t;
	while(t--){
		int n;std::cin>>n;
		std::vector<std::string> a(n);
		for(auto& r:a)std::cin>>r;
		int nmod=0;
		for(int i=1;i<n;++i){
			if(std::find(begin(a),end(a),a[i])==begin(a)+i) continue;
			auto newai=a[i];
			++nmod;
			for(int pos=0;pos<4;++pos){
				for(char d='0';d<='9';++d){
					newai[pos]=d;
					if(std::find(begin(a),end(a),newai)==end(a)){
						a[i]=std::move(newai);
						goto nexti;
					}
				}
				newai[pos]=a[i][pos];
			}
nexti:;
		}
		std::cout<<nmod<<'\n';
		for(auto& r:a)std::cout<<r <<'\n';
	}
}