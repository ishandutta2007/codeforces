// This algorithm is fast enough because any binary string with length 9
// has such a (x, k) pair.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	std::vector<int> minr(s.size()); // [l]: s.t. (l..r) has such a pair
	minr.back()=(int)s.size()+1;
	int64_t out=0;
	for(int l=(int)s.size()-1;l--;){
		minr[l]=minr[l+1];
		for(int x=l+2;x+1<minr[l];x+=2)
			if(s[(l+x)/2]==s[l] and s[x]==s[l]){
				minr[l]=x+1;
				break;
			}
		out+=(int)s.size()-minr[l]+1;
	}
	std::cout<<out<<'\n';
}