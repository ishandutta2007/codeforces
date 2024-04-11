// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string string; std::cin>>string;
	int const len=(int)string.size();
	std::array<std::vector<std::string>, 26> rots;
	for(int _=0;_<len;++_) {
		auto newString=string.substr(1)+string[0];
		rots[string[0]-'a'].push_back(std::move(string));
		string=newString;
	}
	int result=0;
	for(auto & cur: rots){
		int curResult=0;
		for(int pos=0;pos<len;++pos) {
			std::array<int, 26> count{};
			for(auto const& x: cur) ++count[x[pos]-'a'];
			curResult=std::max(curResult, (int)std::count(begin(count),end(count), 1));
		}
		result+=curResult;
	}
	std::cout<<std::fixed<<std::setprecision(12)<<result/(double) len<<'\n';
}