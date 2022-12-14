// (spent too much time re-?implementing the lca, la and DFS stuff)
// TODO learn/review offline lca algorithm
//
//
// update: wrong algorithm. (again?...)
// Too bad. (it takes more time implementing the wrong algorithm than the correct one?)





#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Edge2{
	int first, sec, weight;
	bool operator<(Edge2 other) const{return weight<other.weight;}
};

struct DisjointSet{
	std::vector<int> par;
	struct Change{int index, old;};
	std::vector<Change> history;

	DisjointSet(int number): par(number, -1), history(){}

	void undo(){
		auto [index, old]=history.back(); history.pop_back();
		par[index]=old;
	}

	private:
	int set(int index, int value){
		if(par[index]==value) return value;
		history.push_back({index, par[index]});
		return par[index]=value;
	}
	public:

	int root(int node)const{
		assert(node!=-1);
		return par[node]>=0 ? root(par[node]): node;
	}
	bool join(int first, int sec){
		first=root(first); sec=root(sec);
		if(first==sec) return false;
		if(par[first]>par[sec]) std::swap(first, sec);
		if(par[first]==par[sec]) --par[first];
		set(sec, first);
		return true;
	}
};

/*
struct Edge1{int node, weight;};
std::vector<std::vector<Edge1>> add,
	jump; // weight=maximum weight on path

std::vector<Edge1> par;
std::vector<int> depth;

void work(int node, int parNode=-1){
	for(auto [child, weight]: add[node]) if(child!=parNode){
		par[child]={node, weight};
		depth[child]=depth[node]+1;
		work(child, node);
	}
}

Edge1 la(int first, int depth){
	int weight=INT_MIN;
	while(depth){
		auto [next, weight_]=jump[__builtin_ctz(depth)][first];
		weight=std::max(weight, weight_);
		first=next; depth&=depth-1;
	}
	return {first, weight};
}

Edge1 lca(int first, int sec){ // this is really an abuse of the Edge1 struct :~
	// returned weight=maximum weight on path
	if(depth[first]<depth[sec]) std::swap(first, sec);
	auto [first_, weight]=la(first, depth[first]-depth[sec]);
	first=first_;
	if(first==sec) return {first, weight};

	auto const jumpAt=[&](auto layer){
		auto [a, b]=jump[layer][first];
		auto [c, d]=jump[layer][sec];
		first=a; sec=c;
		weight=std::max({weight, b, d});
	};

	for(auto layer=jump.size(); layer--;) if(jump[layer][first].node!=jump[layer][sec].node)
		jumpAt(layer);
	assert(first!=sec);
	jumpAt(0);
	assert(first==sec);
	return {first, weight};
}
*/

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;

	struct Group{
		struct QueryPart{int index; std::vector<std::pair<int, int>> edges;};
		std::vector<QueryPart> queryParts;
		std::vector<std::pair<int, int>> edges;
	};
	std::map<int /*weight*/, Group> groups;

	std::vector<Edge2> edges(numEdge);
	for(auto &[first, sec, weight]: edges){
		//int first, sec, weight;
		std::cin>>first>>sec>>weight;
		--first;--sec;
		groups[weight].edges.push_back({first, sec});
	}

	DisjointSet set(numNode);

	/*
	auto edgesSorted=edges;
	std::sort(begin(edgesSorted), end(edgesSorted));
	add.resize(numNode);
	for(auto const [first, sec, weight]: edgesSorted){
		if(set.root(first)!=set.root(sec)){
			set.join(first, sec);
			add[first].push_back({sec, weight}); add[sec].push_back({first, weight});
		}
	}
	*/

	/*
	par.resize(numNode);
	depth.resize(numNode);
	par[0]={-1, INT_MIN}; work(0);

	assert(jump.empty());
	jump.push_back(par);
	while(true){ // construct jump table
		auto const& a=jump.back();
		auto b=a;
		bool useful=false;
		for(auto &[node, weight]: b) if(node>=0){
			auto [node1, weight1]=a[node];
			node=node1; weight=std::max(weight, weight1);
			if(node>=0) useful=true;
		}
		if(useful) jump.push_back(std::move(b)); else break;
	}
	*/


	int numQuery; std::cin>>numQuery;
	for(int queryIndex=0; queryIndex<numQuery; ++queryIndex){
		int number; std::cin>>number;
		for(int _=0; _<number; ++_){
			int edgeIndex; std::cin>>edgeIndex;--edgeIndex;
			auto const [first, sec, weight]=edges[edgeIndex];
			/*
			if(weight!=lca(first, sec).weight) okay=false;
			if(okay){
				if(set.root(first)==set.root(sec)) okay=false;
				else set.join(first, sec);
			}
			*/

			auto& it=groups[weight].queryParts;
			if(it.empty() or it.back().index!=queryIndex){
				it.emplace_back();
				it.back().index=queryIndex;
			}
			it.back().edges.push_back({first, sec});
		}
	}

	std::vector<char> result(numQuery, true);
	for(auto const& [_weight, group]: groups){
		auto historyPos=set.history.size();
		for(auto const& queryPart: group.queryParts){
			if(not result[queryPart.index])
				continue;
			for(auto [first, sec]: queryPart.edges){
				if(not set.join(first, sec))
					result[queryPart.index]=false;
			}
			while(set.history.size()!=historyPos) set.undo();
		}
		for(auto [first, sec]: group.edges){
			set.join(first, sec);
		}
	}
	for(auto okay: result) std::cout<<(okay ? "YES\n": "NO\n");
}