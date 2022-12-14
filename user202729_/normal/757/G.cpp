// :(
// editorial solution.
//
// Why is O(n log n) for n=2e5 so slow... (current fastest solution: 1092 ms)
// Any solution that takes O(n log^2(n)) or more may take even slower.
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct Edge{
	int node, weight;
};
std::vector<std::vector<Edge>> add;

void workAddDummy(int node, int parent){
	assert(std::none_of(begin(add[node]),end(add[node]),[&](auto it){ return it.node==parent; }));
	for(auto [child,_]: add[node]){
		add[child].erase(
				std::find_if(begin(add[child]),end(add[child]),[&](auto it){ return it.node==node; })
				);
		workAddDummy(child, node);
	}
	while(add[node].size()>=3){
		auto const newNode=(int)add.size();
		add.push_back({add[node].end()-2, add[node].end()});
		for(auto [child, weight]: add[newNode])
			add[child].push_back({newNode, weight});
		add[node].pop_back();
		add[node].back()={newNode, 0};
	}
	for(auto [child, weight]: add[node])
		add[child].push_back({node, weight});
}

struct EdgeCentroid{
	int weight;
	std::array<int, 2> halves; // -1 if not exist (only 1 node in component)
	//int parent;
};
std::deque<EdgeCentroid> edgeCentroid; // dequeue to avoid reference invalidation

struct EdgeCentroidInfo{
	int index; // into (edgeCentroid)
	int side;
	int64_t distance;
};
std::vector<std::vector<EdgeCentroidInfo>> info; //[0]: topmost

int curComponentSize, maxHalf, edgeCentroidFirst, edgeCentroidSec, edgeCentroidFirstSize;

int findEdgeCentroid(int node, int par){ // returns subtree size, store result in (edgeCentroidFirst, edgeCentroidSec)
	int subtreeSize=1;
	for(auto [child,_]: add[node]) if(child!=par){
		int const childSize=findEdgeCentroid(child, node);
		int const newMaxHalf=std::max(childSize, curComponentSize-childSize);
		if(newMaxHalf<maxHalf){
			maxHalf=newMaxHalf; edgeCentroidFirst=child; edgeCentroidSec=node;
			edgeCentroidFirstSize=childSize;
		}
		subtreeSize+=childSize;
	}
	return subtreeSize;
}

void fillInfo(int node, int par, EdgeCentroidInfo infoNode){
	info[node].push_back(infoNode);
	auto const addDistance=[&](EdgeCentroidInfo info, int weight){ info.distance+=weight; return info; };
	for(auto [child, weight]: add[node]) if(child!=par)
		fillInfo(child, node, addDistance(infoNode, weight));
}

void computeEdgeCentroid(int edgeCentroidIndex, int node, int componentSize){
	EdgeCentroid& result=edgeCentroid[edgeCentroidIndex];
	curComponentSize=componentSize; maxHalf=INT_MAX;
	[[maybe_unused]] auto const tmp = findEdgeCentroid(node, -1);
	assert(tmp==componentSize);
	assert(std::max(edgeCentroidFirstSize, componentSize-edgeCentroidFirstSize)==maxHalf);

	for(int _=0;_<2;++_, std::swap(edgeCentroidFirst, edgeCentroidSec)) {
		auto const iterator=std::find_if(begin(add[edgeCentroidFirst]),end(add[edgeCentroidFirst]),
				[&](auto it){ return it.node==edgeCentroidSec; });
		if(_==0) result.weight=iterator->weight;
		else assert(result.weight==iterator->weight);
		add[edgeCentroidFirst].erase(iterator);
	}


	auto const x=edgeCentroidFirst, y=edgeCentroidSec, xSize=edgeCentroidFirstSize;
	fillInfo(x, y, EdgeCentroidInfo{edgeCentroidIndex, 0, 0});
	fillInfo(y, x, EdgeCentroidInfo{edgeCentroidIndex, 1, 0});

	if(xSize>1){
		result.halves[0]=(int)edgeCentroid.size();
		edgeCentroid.emplace_back();
		//edgeCentroid.back().parent=edgeCentroidIndex;
		computeEdgeCentroid(result.halves[0], x, xSize);
	}else result.halves[0]=-1;

	if(componentSize-xSize>1){
		result.halves[1]=(int)edgeCentroid.size();
		edgeCentroid.emplace_back();
		//edgeCentroid.back().parent=edgeCentroidIndex;
		computeEdgeCentroid(result.halves[1], y, componentSize-xSize);
	}else result.halves[1]=-1;
}

using PersistentNodeIndex=int;
struct Node{
	std::array<PersistentNodeIndex, 2> child;
	std::array<int, 2> numNode;
	std::array<int64_t, 2> sumDistance;
};
std::vector<Node> nodes; // index type: PersistentNodeIndex

PersistentNodeIndex emptyTree(int edgeCentroidIndex){
	auto const result=PersistentNodeIndex(nodes.size());
	nodes.emplace_back();
	for(int side=0;side<2;++side)
		nodes[result].child[side]= // undefined behavior before C++17
			edgeCentroid[edgeCentroidIndex].halves[side]>=0 ?
			emptyTree(edgeCentroid[edgeCentroidIndex].halves[side]): -1;
	return result;
}

PersistentNodeIndex activate(PersistentNodeIndex persistentNode, int node,
		std::vector<EdgeCentroidInfo>::iterator iterator,
		std::vector<EdgeCentroidInfo>::iterator last){
	assert(node<(int)add.size());
	if(iterator==last) {
		assert(persistentNode==-1);
		return -1;
	}

	auto const result=PersistentNodeIndex(nodes.size());
	nodes.push_back(nodes[persistentNode]);
	auto const [index, side, distance]=*iterator;
	nodes[result].sumDistance[side]+=distance;
	++nodes[result].numNode[side];
	nodes[result].child[side]= // undefined behavior before C++17
		activate(nodes[result].child[side], node, ++iterator, last);
	return result;
}

// get sum of distances from node to all activated nodes (of course)
int64_t query(PersistentNodeIndex persistentNode, int node,
		std::vector<EdgeCentroidInfo>::iterator iterator,
		std::vector<EdgeCentroidInfo>::iterator last){
	assert(node<(int)add.size());
	if(iterator==last) {
		assert(persistentNode==-1);
		return -1;
	}

	auto const [index, side, distance]=*iterator;
	auto const tmp=nodes[persistentNode];
	return (edgeCentroid[index].weight+distance)*tmp.numNode[not side]
		+tmp.sumDistance[not side]
		+query(tmp.child[side], node, ++iterator, last);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRealNode, numQuery; std::cin>>numRealNode>>numQuery;
	std::vector<int> a(numRealNode); for(auto & it: a){
		std::cin>>it;
		--it;
	}
	add.resize(numRealNode);
	for(int _=0;_<numRealNode-1;++_) {
		int first, sec, weight; std::cin>>first>>sec>>weight;
		add[--first].push_back({--sec, weight});
		add[sec].push_back({first, weight});
	}

	workAddDummy(0, -1);
	info.resize(add.size());
	edgeCentroid.emplace_back();
	int const edgeCentroidRoot=0;
	//edgeCentroid[edgeCentroidRoot].parent=-1;
	computeEdgeCentroid(edgeCentroidRoot, 0, (int)add.size());

	std::vector<PersistentNodeIndex> roots; roots.reserve(numRealNode+1);
	roots.push_back(emptyTree(edgeCentroidRoot));
	for(auto node: a){
		if(roots.size()>=roots.capacity()){ assert(false); __builtin_unreachable(); }
		roots.push_back(activate(roots.back(), node, begin(info[node]),end(info[node])));
	}
	assert((int)roots.size()==(numRealNode+1));

	int previousAnswer=0;
	while(numQuery--){
		char type; std::cin>>type;
		if(type=='1'){
			int left, right, node; std::cin>>left>>right>>node;
			left^=previousAnswer;
			right^=previousAnswer;
			node^=previousAnswer;
			--node;

			int64_t answer=query(roots[right], node,begin(info[node]),end(info[node]))
				-query(roots[left-1], node,begin(info[node]),end(info[node]));
			std::cout<<answer<<'\n';
			previousAnswer=int(answer%(1<<30));
		}else{
			assert(type=='2');
			int pos; std::cin>>pos;
			pos^=previousAnswer;

			std::swap(a[pos-1], a[pos]);
			roots[pos]=activate(roots[pos-1], a[pos-1],begin(info[a[pos-1]]),end(info[a[pos-1]]));
		}
	}
}