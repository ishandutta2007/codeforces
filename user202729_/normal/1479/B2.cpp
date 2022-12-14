// ...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> values(number);
	for(auto& it: values) {
		std::cin>>it;
	}
	values.erase(std::unique(begin(values), end(values)), end(values));

	std::vector<int> minimum((int)values.size()+1, INT_MAX);
	minimum[0]=0;
	std::map<int, int> last;
	for(int index=0; index<(int)values.size(); ++index) if(minimum[index]!=INT_MAX){
		minimum[index+1]=std::min(minimum[index+1], minimum[index]+1);
		if(auto const iterator=last.find(values[index]); iterator!=last.end()){
			auto const curLast=iterator->second;
			assert(index>=curLast-2);
			minimum[index+1]=std::min(minimum[index+1], minimum[curLast+2]+index-curLast-2);
			iterator->second=index;
		}else
			last[values[index]]=index;

	}
	std::cout<<minimum.back()<<'\n';

}