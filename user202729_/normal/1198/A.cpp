#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,maxbyte;std::cin>>n>>maxbyte;
	auto const maxbitperval=maxbyte*8/n;
	auto const maxndiffval=1<<std::min(30,maxbitperval);

	std::vector<int> a(n);for(int& ai:a)std::cin>>ai;
	std::sort(begin(a),end(a));

	auto it1=begin(a),it2=begin(a);
	int ndiffval=0;

	int out=n;
	while(true){
		while(it2!=end(a)){
			// check it1..(1+it2) compression is representable
			if(it2==begin(a) or it2[0]!=it2[-1]){ // increases ndiffval
				if(ndiffval==maxndiffval)
					break;
				++ndiffval;
			}
			++it2;
		}
		out=std::min<int>(out,(it1-begin(a))+(end(a)-it2));

		if(it2==end(a))break;
		if(it2-it1==0){
			++it1;++it2;
			assert(ndiffval==0);
		}else if(it2-it1==1){
			++it1;
			assert(ndiffval==1);
			--ndiffval;
		}else{
			++it1;
			if(it1[-1]!=it1[0])
				--ndiffval;
		}
	}
	std::cout<<out<<'\n';
}