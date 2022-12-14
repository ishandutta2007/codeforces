/*
still unproven, but seems more correct

@Z%8,Q#k]LW0p[wb3A7dU&Bp>v MSQP9:Oi}@zQOtN^I>A-,E~yhWD
*/

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Graph{
	std::vector<std::vector<int>> add;
	std::vector<char> marked;

	void resize(int number){
		assert(add.empty() and marked.empty());
		add.resize(number);
		marked.resize(number);
	}

	void fill(int node){  // total time: O(n+m + numCall)
		if(marked[node]) return;
		marked[node]=true;
		for(auto other: add[node]) if(not marked[other]){
			fill(other);
			marked[other]=true;
		}
	}

	std::vector<int> minTime;

	int compute1(int node){
		if(minTime[node]==-1){
			minTime[node]=node;
			for(auto other: add[node])
				minTime[node]=std::min(minTime[node], compute1(other));
		}
		return minTime[node];
	}

	void compute(){
		minTime.assign(add.size(), -1);
		for(int node=0;node<(int)add.size();++node) if(minTime[node]==-1)
			compute1(node);
	}
};

Graph add, reverse;

std::vector<char> state;
void checkCycle(int node){
	assert(0==state[node]);
	state[node]=1;
	for(auto other: add.add[node])
		switch(state[other]){
			case 0:
				checkCycle(other);
				break;
			case 1:
				std::cout<<"-1\n";
				std::exit(0);
			case 2:
				break;
			default:
				assert(false); __builtin_unreachable();
		}
	state[node]=2;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	reverse.resize(numNode);

	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add.add[first].push_back(sec);
		reverse.add[sec].push_back(first);
	}

	state.resize(numNode);
	for(int node=0;node<numNode;++node) 
		if(state[node]==0) checkCycle(node);

	add.compute();
	reverse.compute();

	std::string result(numNode, 'E');
	for(int node=0;node<numNode;++node) {
		if(add.minTime[node]==node and reverse.minTime[node]==node){
			result[node]='A';
		}
	}
	std::cout<<std::count(begin(result),end(result), 'A')<<'\n'
		<<result<<'\n';
}