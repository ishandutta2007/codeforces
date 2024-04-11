// editorial solution.(should be) more elegant than my solution.
// I should try to solve the tree construction part int O(n) before reading the editorial. :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> regionAdd;
std::vector<int> color;
std::vector<char> used; // *

std::vector<int> subtreeSize;

int findSubtreeSize(int node, int par){
	int cur=1;
	for(auto child: regionAdd[node]) if(child!=par and not used[child])
		cur+=findSubtreeSize(child, node);
	return subtreeSize[node]=cur;
}

void work(int node, int nodeColor){
	findSubtreeSize(node, -1);
	int const total=subtreeSize[node];
	while(true){
		int best=-1, bestSubtreeSize=-1; // best=the child with maximum subtreeSize
		for(auto child: regionAdd[node]) 
			if(subtreeSize[child]<subtreeSize[node] and not used[child] and subtreeSize[child]>bestSubtreeSize){
				bestSubtreeSize=subtreeSize[child];
				best=child;
			}
		if(bestSubtreeSize>total/2) node=best; else break;
	}

	// now node is the centroid of the current component
	color[node]=nodeColor;
	used[node]=true;
	for(auto child: regionAdd[node]) if(not used[child]) work(child, nodeColor+1);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numVer, numDiagonal; std::cin>>numVer>>numDiagonal;
	struct Diagonal{
		int x, y;
		int outerArcLen()const{
			assert(x+1<y);
			return y-x;
		}
	};
	std::vector<Diagonal> diagonals(numDiagonal);
	for(auto & [x, y]: diagonals){
		std::cin>>x>>y;
		std::tie(x, y)=std::minmax({x-1, y-1});
	}

	std::vector<std::vector<int>> region; // list of vertices
	std::sort(begin(diagonals),end(diagonals),[&](auto first, auto sec){
		return first.outerArcLen()<sec.outerArcLen();
	});

	region.reserve(numDiagonal+1);
	regionAdd.resize(numDiagonal+1);

	{
		struct item{int next, pendRegionIndex;};
		std::vector<item> list(numVer);
		for(int node=0;node<numVer;++node) list[node]={node+1, -1};
		
		auto const process=[&](int x, int y){
			assert(x<y);
			std::vector<int> currentRegion;
			int const currentRegionIndex=(int)region.size();
			currentRegion.push_back(x);
			while(currentRegion.back()!=y){
				auto [next, pendRegionIndex]=list[currentRegion.back()];
				if(pendRegionIndex>=0){
					regionAdd[currentRegionIndex].push_back(pendRegionIndex);
					regionAdd[pendRegionIndex].push_back(currentRegionIndex);
				}
				currentRegion.push_back(next);
			}
			list[x]={y, currentRegionIndex};
			region.push_back(std::move(currentRegion));
		};
		for(auto [x, y]: diagonals) process(x, y);
		process(0, numVer-1);
	}

	used.resize(region.size());
	color.resize(region.size());
	subtreeSize.resize(region.size());

	work(0, 1);

	std::vector<std::array<int, 3>> result(region.size());
	std::transform(
			std::move_iterator(begin(region)),
			std::move_iterator(end(region)),
			begin(result),
			[&, index=0](auto currentRegion) mutable {
				std::partial_sort(begin(currentRegion), begin(currentRegion)+2, end(currentRegion), std::greater<>());
				return std::array<int, 3>{{currentRegion[0], currentRegion[1], color[index++]}};
			});
	std::sort(begin(result),end(result));

	for(auto [_,__, x]: result) std::cout<<x<<' ';
	std::cout<<'\n';
}