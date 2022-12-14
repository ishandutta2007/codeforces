// :(
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
	std::string a, b; std::cin>>a>>b;
	auto first=a.begin(), last=a.end();
	bool reverse=false;
	std::vector<int> operations;

	for(auto index=(int)b.size(); index--;){
		auto first1=first[0], last1=last[-1];
		assert(first1=='0' or first1=='1');
		assert(last1=='0' or last1=='1');
		if(reverse) {
			std::swap(first1, last1);
			first1^=1; last1^=1;
		}
		/*
		if(b[index]==last1){
			if(reverse) ++first; else --last;
			continue;
		}
		*/
		if(b[index]==first1)
			operations.push_back(1);
		operations.push_back(last-first);

		reverse=not reverse;
		if(reverse) ++first; else--last;
	}

	std::cout<<operations.size();
	for(auto it: operations) std::cout<<' '<<it;
	std::cout<<'\n';
}