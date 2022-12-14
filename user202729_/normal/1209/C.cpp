// :( too slow
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	std::string string, tmp;
	while(numTest--){
		int number; std::cin>>number;
		string.reserve(number);
		std::cin>>string;
		assert((int)string.size()==number);

		for(char shared='0';shared<='9';++shared) {
			tmp.assign(number, 0);
			std::transform(begin(string),end(string), begin(tmp),[&](char it){
				return it<shared ? '1': it==shared ? 0: '2';
			});

			for(auto index=(int)tmp.size(); index--;){
				auto& it=tmp[index];
				if(it=='1') break;
				if(it==0) it='1';
			}
			for(auto & it: tmp){
				if(it=='2') break;
				if(it==0) it='2';
			}

			if(std::find(begin(tmp),end(tmp), 0)!=end(tmp)) continue;

			for(int ch='1';ch<='2';++ch)
				for(int last=0, index=0;index<number;++index) if(tmp[index]==ch){
					if(string[index]<last) goto nextSharedValue;
					last=string[index];
				}

			std::cout<<tmp<<'\n';
			goto nextTest;

nextSharedValue:;
		}

		std::cout<<"-\n";
nextTest:;
	}
}