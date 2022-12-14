// :(((((
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	std::string string; std::cin>>string;
	std::string prefix, suffix;
	{
		int left=0, right=(int)string.size();
		while(right-left>2 and string[left]==string[right-1]){
			++left;--right;
		}

		prefix=string.substr(0, left);
		suffix=string.substr(right);
		string=string.substr(left, right-left);
	}

	std::string other;
	other.reserve(string.size()*2+1);
	other+='|';
	for(auto ch: string){other+=ch; other+='|';}
	assert(other.size()==string.size()*2+1);
	//other.back()='$';

	auto left=0, right=1;
	std::vector<int> rad(other.size()); //[index-rad]==[index+rad]
	std::pair<int, int> result{-1, -1};
	for(int index=1;index<(int)rad.size()-1;++index) {
		if(index>=right){
			left=index; right=index+1;
		}
		auto& cur=rad[index]=std::min(rad[left+right-1-index], right-index-1);
		while(index-cur-1>=0 and index+cur+1<(int)other.size()
				and
				other[index-cur-1]==other[index+cur+1]) ++cur;
		if(index+cur+1>right){
			right=index+cur+1;
			left=index-cur;
		}

		if(index-cur-1<0 or index+cur+1==(int)other.size())
			result=std::max(result, std::make_pair(cur, index));
	}

	auto [rad_, index]=result;
	std::cout<<prefix;
	std::string mid; mid.reserve(rad_);
	for(int x=index-rad_;x<=index+rad_;++x) if(auto ch=other[x]; ch!='|') mid+=ch;
	assert(mid.size()==rad_);
	std::cout<<std::move(mid)+std::move(suffix)<<'\n';

}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}