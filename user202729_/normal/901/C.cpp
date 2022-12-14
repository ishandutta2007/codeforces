// seriously?...

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
enum class State{ white, gray, black };
std::vector<State> visited;
std::vector<int> par;

std::vector<std::pair<int, int>> ranges; // {min, max} values of cycles

void work(int node, int parNode){
	assert(visited[node]==State::white);
	visited[node]=State::gray; par[node]=parNode;
	for(auto other: add[node]) if(other!=parNode){
		switch(visited[other]){
			case State::gray: // cycle
				{
					std::pair<int, int> range{other, other};
					for(int tmp=node; tmp!=other; tmp=par[tmp])
						range={std::min(range.first, tmp), std::max(range.second, tmp)};
					ranges.push_back(range);
					break;
				}
			case State::black: // forward edge
				break;
			case State::white: // child
				work(other, node);
		}
	}
	visited[node]=State::black;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;--first;--sec;
		add[first].push_back(sec);
		add[sec].push_back(first);
	}

	visited.assign(numNode, State::white);
	par.resize(numNode);
	for(int node=0;node<numNode;++node) if(State::white==visited[node]) work(node, -1);

	auto const first_reverse_compare=[&](auto x, auto y){return x.first>y.first;};
	if(not ranges.empty()){ // remove unused elements
		std::sort(begin(ranges),end(ranges), first_reverse_compare);
		// no two first/second values can be equal.
		auto out=ranges.begin()+1;
		std::for_each(out, ranges.end(), [&](auto it){
			if(it.second<out[-1].second) *out++=it;
		});
		ranges.erase(out, ranges.end());
		std::reverse(begin(ranges),end(ranges));
	}
	// now ranges is sorted by increasing first and increasing second
	for(auto & [left, right]: ranges) ++left;

	ranges.insert(ranges.begin(), {0, 0});
	ranges.push_back({numNode, numNode});
	// to makes implementation easier
	

	/*
	int64_t totalArea=numNode*int64_t(numNode+1)/2;
	{
		int lastRow=numNode;
		for(auto [left, right]: ranges){
			assert(right<lastRow);
			totalArea-=int64_t(lastRow-right)*left;
			lastRow=right;
		}
	}
	*/

	std::vector<int64_t> leftArea(ranges.size()), upArea(ranges.size());
	int64_t totalArea;
	{
		int64_t curLeftArea=0, curUpArea=0;
		int lastX=0, lastY=0;
		for(int index=0;index<(int)ranges.size();++index) {
			auto const [x, y]=ranges[index];
			assert(x>=lastX and y>=lastY);
			curLeftArea+=int64_t(x-lastX)*(y-(x-1) + y-lastX)/2;
			curUpArea-=int64_t(y-lastY)*(lastY+1-lastX + y-lastX)/2;
			leftArea[index]=curLeftArea;
			upArea[index]=curUpArea;
			lastX=x; lastY=y;
		}
		assert(curUpArea==-curLeftArea);
		totalArea=curLeftArea;
		for(auto & it: upArea) it+=totalArea;
		assert(upArea.back()==0 and leftArea[0]==0);
	}


	int numQuery; std::cin>>numQuery;
	for(int _=0;_<numQuery;++_) {
		int x, y; std::cin>>x>>y;
		--x;
		auto iterator=std::upper_bound(begin(ranges),end(ranges), x,[&](auto x, auto y){
			return x<y.first;
		});
		if(iterator->second>=y)
			std::cout<< (y-x)*int64_t(y-x+1)/2 <<'\n';
		else{
			auto iterator2=std::lower_bound(begin(ranges),end(ranges), y,[&](auto x, auto y){
				return x.second<y;
			});
			auto const subtractLeft=leftArea[iterator-ranges.begin()-1]+
				int64_t(x-iterator[-1].first)*( iterator->second-(x-1) + iterator->second-iterator[-1].first )/2,
			subtractUp=upArea[iterator2-ranges.begin()]+
				int64_t(iterator2->second-y)*(
						iterator2->second-iterator2[-1].first + y+1-iterator2[-1].first )/2;
			std::cout<< totalArea-subtractLeft-subtractUp <<'\n';
		}
	}

	return 0;
}