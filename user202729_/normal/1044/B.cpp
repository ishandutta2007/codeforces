// https://codeforces.com/group/sd4r2IvEfL/contest/289090
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
std::vector<int> par;
void work(int node){
	for(auto child: add[node]){
		par[child]=node;
		std::swap(add[child].back(), *std::find(begin(add[child]), end(add[child]), node));
		add[child].pop_back();
		work(child);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--){
		int number; std::cin>>number;
		add.clear(); add.resize(number);
		for(int _=0; _<number-1; ++_){
			int first, sec; std::cin>>first>>sec;
			--first;--sec;
			add[first].push_back(sec); add[sec].push_back(first);
		}
		auto const readComponent=[&]{
			std::vector<int> result;
			int number; std::cin>>number;
			result.resize(number);
			for(auto& it: result){std::cin>>it;--it;}
			return result;
		};

		auto const ask=[&](char type, int node)->int{
			assert(0<=node and node<number);
			std::cout<<type<<' '<<node+1<<std::endl;
			assert(type=='A' or type=='B');
			int result; std::cin>>result;
			--result;
			assert(0<=result and result<number);
			return result;
		};
		auto const answer=[&](int node){
			if(node>=0) ++node;
			std::cout<<'C'<<' '<<node<<std::endl;
		};

		auto const myComponent=readComponent();
		auto const theirComponent=readComponent();

		par.resize(number); par[myComponent[0]]=-1;
		work(myComponent[0]);

		std::vector<char> have(number);
		for(auto it: myComponent) have[it]=true;
		for(auto it: myComponent) assert(par[it]<0 ? have[it]: have[par[it]]);

		auto const x=ask('B', theirComponent[0]);
		if(have[x])
			answer(x);
		else{
			auto y=x;
			while(not have[y]) y=par[y];
			if(std::find(begin(theirComponent), end(theirComponent), ask('A', y))!=theirComponent.end())
				answer(y);
			else
				answer(-1);
		}
	}
}