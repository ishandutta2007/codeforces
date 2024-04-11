// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int maxTime;
std::vector<std::vector<int>> add;
std::vector<std::pair<int, int>> answer;

void work(int node, int time, int par){
	if(node==0) assert(time==0 and par==-1); else assert(time!=0 and par!=-1);
	auto const startTime=time;

	answer.push_back({node, time});
	bool wrapped=false;
	for(auto child: add[node]) if(child!=par){
		if(wrapped) assert(time!=startTime);
		if(time==maxTime){
			assert(not wrapped); wrapped=true;
			assert(node!=0);
			answer.push_back({node, time-=(int)add[node].size()});
		}
		// (node, time) -> (child, time+1)
		work(child, time+1, node); // -> ... -> (child, time)
		answer.push_back({node, ++time});// -> (node, time+1)
	}

	if(node!=0) {
		if(time!=startTime-1){
			assert(not wrapped);
			answer.push_back({node, startTime-1});
		}else assert(wrapped);
	} else assert(not wrapped);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	add.resize(number);
	std::vector<int> degree(number);
	for(int _=0;_<number-1;++_) {
		int first, sec; std::cin>>first>>sec;
		++degree[--first];++degree[--sec];
		add[first].push_back(sec);
		add[sec].push_back(first);
	}
	maxTime=*std::max_element(begin(degree),end(degree));
	work(0, 0, -1);
	std::cout<<answer.size()<<'\n';
	for(auto [node, time]: answer) std::cout<<node+1<<' '<<time<<'\n';
}