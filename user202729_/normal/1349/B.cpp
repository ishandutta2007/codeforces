#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number, target; std::cin>>number>>target;
	std::vector<int> values(number);for(auto & it: values) std::cin>>it;

	if(std::find(begin(values),end(values), target)==values.end()){
no:
		std::cout<<"no\n";
		return;
	}
	if(number==1){
yes:
		std::cout<<"yes\n";
		return;
	}

	for(int index=1;index<number;++index) if(values[index-1]>=target and values[index]>=target)
		goto yes;

	for(int index=2;index<number;++index) if(values[index-2]>=target and values[index]>=target){
		assert(values[index-1]<target);
		goto yes;
	}

	goto no;
}