// :|
// Reminder: prove correctness before implementing.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge, numSpecial; std::cin>>numNode>>numEdge>>numSpecial;
	std::vector<int> specialNodes(numSpecial);
	for(auto & item: specialNodes){std::cin>>item;--item;}

	std::vector<std::vector<int>> add(numNode);
	for(int _=0;_<numEdge;++_) {
		int first, second; std::cin>>first>>second;
		--first;--second;
		add[first].push_back(second);
		add[second].push_back(first);
	}

	std::vector<int> distance(numNode, -1);
	{
		std::queue<int> queue;
		queue.push(0);
		distance[0]=0;
		while(not queue.empty()){
			auto node=queue.front(); queue.pop();
			for(auto other: add[node]) if(distance[other]<0){
				distance[other]=distance[node]+1;
				queue.push(other);
			}
		}
	}
	
	std::vector<int> distance2(numNode, -1);
	{
		std::queue<int> queue;
		queue.push(numNode-1);
		distance2[numNode-1]=0;
		while(not queue.empty()){
			auto node=queue.front(); queue.pop();
			for(auto other: add[node]) if(distance2[other]<0){
				distance2[other]=distance2[node]+1;
				queue.push(other);
			}
		}
	}

	std::vector<std::pair<int, int>> positions(numSpecial);
	std::transform(begin(specialNodes),end(specialNodes), begin(positions),[&](int node){
		return std::make_pair(distance[node], distance2[node]);
	});
	std::sort(begin(positions),end(positions));

	int result=0;
	for(int index=0;index<(int)positions.size()-1;++index) {
		if(positions[index].second<=positions[index+1].second){
			std::cout<<distance.back()<<'\n';
			return 0;
		}
		result=std::max(result,
				std::min({distance.back(),
					1+positions[index].first+positions[index+1].second,
					1+positions[index+1].first+positions[index].second})
				);
	}
	std::cout<<result<<'\n';
}