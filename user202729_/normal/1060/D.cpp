// not proven very carefully ~

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len; std::cin>>len;
	std::vector<int> left(len+1), right(len+1);
	for(int index=0;index<len;++index) std::cin>>left[index+1]>>right[index+1];
	left[0]=right[0]=INT_MIN;

	std::sort(begin(left)+1,end(left)); std::sort(begin(right)+1,end(right));

	int64_t result=len;
	int remainLeft{}, remainRight{};
	for(int _=0;_<2*len;++_) {
		if(left.back()>right.back()){
			if(remainRight) --remainRight;
			else{ result+=left.back(); ++remainLeft; }
			left.pop_back();
		}else{
			if(remainLeft) --remainLeft;
			else{ result+=right.back(); ++remainRight; }
			right.pop_back();
		}
	}
	assert(remainLeft==0); assert(remainRight==0);
	std::cout<<result<<'\n';
}