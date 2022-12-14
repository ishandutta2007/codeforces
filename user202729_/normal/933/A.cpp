// so slow :(
// is div1 A supposed to be *this* hard?
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<char> data(number);
	int count1{};
	for(auto & it: data){
		std::cin>>it;
		it=it=='1';
		count1+=it;
	}

	int result{};
	std::vector<int> tmp(number+1, INT_MAX);

	for(auto right=0, count1r=count1;;){
		for(int len{}, part{};;){
			tmp[len]=std::min(tmp[len], part);

			if(len==right) break;
			part+=data[right-(++len)];
		}

		for(int len{}, part{};;){
			if(tmp[len]!=INT_MAX){
				auto c1r=count1r+tmp[len]-part;
				result=std::max(result, (number-right)-2*c1r+count1);
			}

			if(right+len==number) break;
			part+=data[right+len];
			++len;
		}

		if(right==number) break;
		count1r-=data[right++];
	}

	tmp.assign(number+1, INT_MIN);

	for(int right=number, count1r{};;){
		for(int len{}, part{};;){
			tmp[len]=std::max(tmp[len], part);

			if(right+len==number) break;
			part+=data[right+len];
			++len;
		}

		for(int len{}, part{};;){
			if(tmp[len]!=INT_MIN){
				auto c1r=count1r-tmp[len]+part;
				result=std::max(result, (number-right)-2*c1r+count1);
			}

			if(len==right) break;
			part+=data[right-(++len)];
		}

		if(right==0) break;
		count1r+=data[--right];
	}
	std::cout<<result<<'\n';
}