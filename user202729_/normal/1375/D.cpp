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
	std::vector<int> value(number);
	for(auto& it: value){
		std::cin>>it;
	}

	std::vector<int> result;
	std::vector<int> count(number+1);
	while(true){
		std::fill(begin(count), end(count), 0);
		for(auto it: value) count[it]++;
		int Mex=0;
		while(count[Mex]!=0)++Mex;

		if(Mex==number){
			int i=0;
			while(true){
				if(i==number) goto break_outer;
				if(value[i]==i) ++i; else break;
			}

			std::vector<int> cycle{i};
			while(value[cycle.back()]!=i) cycle.push_back(value[cycle.back()]);

			for(auto it: cycle) result.push_back(it);
			result.push_back(i);

			for(auto it: cycle) value[it]=it;


		}else{
			result.push_back(Mex);
			value[Mex]=Mex;
		}
	}
break_outer:
	std::cout<<result.size()<<'\n';
	for(auto it: result) std::cout<<it+1<<' ';
	std::cout<<'\n';
}