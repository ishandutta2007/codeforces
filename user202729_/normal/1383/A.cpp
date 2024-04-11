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

std::vector<std::vector<int>> add;
std::array<bool, 20> visited;

void work(int node){
	assert(not visited[node]);
	visited[node]=true;
	for(auto other: add[node]) if(not visited[other]) work(other);
}

void up(){
	int number; std::cin>>number;
	std::string a, b;
	a.reserve(number);
	b.reserve(number);
	std::cin>>a>>b;

	std::array<std::bitset<20>, 20> have{};
	add.clear(); add.resize(20);
	for(int index=0; index<number; ++index){
		auto const ai=a[index]-'a', bi=b[index]-'a';
		if(ai>bi){
			std::cout<<"-1\n";
			return;
		}
		if(ai<bi and not have[ai][bi]){
			have[ai][bi]=true;
			add[ai].push_back(bi);
			add[bi].push_back(ai);
		}
	}

	visited.fill(false);
	int result=20;
	for(int node=0; node<20; ++node)
		if(not visited[node]){
			work(node);
			--result;
		}
	std::cout<<result<<'\n';
}