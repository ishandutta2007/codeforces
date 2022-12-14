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
	int number; std::cin>>number;
	std::vector<int> indices; // element indices larger than all previous elements
	int maximum=-1;
	for(int index=0; index<number*2;++index){
		int value; std::cin>>value;
		if(value>maximum){
			maximum=value;
			indices.push_back(index);
		}
	}

	std::vector<char> stuff(number+1); stuff[number]=true;
	int last=number*2;
	for(auto index1=(int)indices.size(); index1--;){
		int cur=indices[index1];
		assert(last>cur);

		for(int i=last-cur; i<(int)stuff.size();++i) if(stuff[i]) stuff[i-(last-cur)]=true;
		if(stuff[0]){
			std::cout<<"YES\n";
			return;
		}
		last=cur;
	}
	std::cout<<"NO\n";
}