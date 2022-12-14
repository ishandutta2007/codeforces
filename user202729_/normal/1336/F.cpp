// [I did not read the editorial]
// stress tested. (without writing a naive solution)
//
// update: that's... such an unfortunate bug. I guessed that before tried to to prove the time complexity of the other functions,
// but for some reason decide to prove complexity first.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

std::vector<int> depth, par, order, first, last;
int work(int node){ // compute stuff above, remove parent edges, return subtree size
	int subtreeSize=1;
	auto const nextDepth=depth[node]+1;
	first[node]=(int)order.size();
	order.push_back(node);

	int maxSize=-1;
	for(auto& child: add[node]){
		par[child]=node;
		depth[child]=nextDepth;
		add[child].erase(std::find(begin(add[child]),end(add[child]), node));
		auto childSize=work(child);
		subtreeSize+=childSize;
		if(childSize>maxSize) {
			std::swap(add[node][0], child);
			maxSize=childSize;
		}
	}
	// after the loop add[node][0] is the largest child if exists
	
	last[node]=(int)order.size();
	return subtreeSize;
}

std::vector<std::vector<int>> jumpTable;
void constructJumpTable(){
	assert(jumpTable.empty());
	jumpTable.push_back(par);
	for(;;){
		bool useful=false;
		auto const& a=jumpTable.back();
		auto b=a;
		for(auto& x:b)if(x>=0){
			if((x=a[x])>=0)
				useful=true;
		}
		if(useful)
			jumpTable.push_back(std::move(b));
		else
			break;
	}
}


bool isAncestor(int ancestor, int node){
	return first[ancestor]<=first[node] and last[node]<=last[ancestor];
}

int levelAncestor(int node, int level){
	assert(level>=0);
	for(;level;level^=level&-level)
		node=jumpTable[__builtin_ctz(level)][node];
	return node;
}

struct lca_result {
	int u1,v1,lca; // u1,v1: child of lca int the direction of u/v resp.
	// int case lca is u or v, both u1 and v1 are int the direction of the node != lca
};
lca_result lcaExtended(int u,int v){
	assert(u!=v);

	bool swapped;
	if((swapped=(depth[u]<depth[v])))std::swap(u,v);

	int ddepth=depth[u]-depth[v];
	if(ddepth){
		--ddepth;
		u=levelAncestor(u, ddepth);
		assert(depth[u]-1==depth[v]);
		if(jumpTable[0][u]==v)return {u,u,v};
		u=jumpTable[0][u];
	}
	assert(u!=v);
	for(auto layer=jumpTable.size();layer--;){
		if(jumpTable[layer][u]!=jumpTable[layer][v])
			std::tie(u,v)=std::make_pair(jumpTable[layer][u],jumpTable[layer][v]);
	}
	assert(jumpTable[0][u]==jumpTable[0][v]);
	if(swapped)std::swap(u,v);
	assert(u!=v);
	return {u,v,jumpTable[0][u]};
}

int lca(int u,int v){
	bool swapped;
	if((swapped=(depth[u]<depth[v])))std::swap(u,v);

	u=levelAncestor(u, depth[u]-depth[v]);
	assert(depth[u]==depth[v]);
	if(u==v) return u;

	for(auto layer=jumpTable.size();layer--;){
		if(jumpTable[layer][u]!=jumpTable[layer][v])
			std::tie(u,v)=std::make_pair(jumpTable[layer][u],jumpTable[layer][v]);
	}
	assert(jumpTable[0][u]==jumpTable[0][v]);
	if(swapped)std::swap(u,v);
	assert(u!=v);
	return jumpTable[0][u];
}

struct BIT{
	using T=int;
	std::vector<T> data;

	void change(int index, T delta){
		for(; index>=0; index=(index&(index+1))-1)
			data[index]+=delta;
	}
	void forceReset(int index){
		// after a series of change operations on some indices, forceReset those indices will make the tree 0
		// other usages may create <s>undefined behavior</s> unexpected states.
		for(; index>=0; index=(index&(index+1))-1)
			data[index]=0;
	}

	T sumSuffix(int index)const{
		T result{};
		for(; index<(int)data.size(); index|=index+1)
			result+=data[index];
		return result;
	}

	T getElement(int index)const{ return sumSuffix(index)-sumSuffix(index+1); }
	void print()const{
		for(int index=0;index<(int)data.size();++index) 
			std::cerr<<getElement(index)<<' ';
		std::cerr<<'\n';
	}
};
BIT tree; // [order] -> number of paths with other endpoint at this node

std::vector<std::vector<int>> paths,  // traveler path u-v => v in paths[u]
	pathsRemove; // v in [u] => there exists some paths with one endpoint in subtree of u, lca==par[u]

int minCommon;
int64_t result;

void updateResultPath(int node, int pathEnd, int other){ // complexity: about 7 log N
	if(node!=pathEnd){ // TODO check correctness
		assert(not isAncestor(pathEnd, other));
		assert(lca(node, other)==lca(pathEnd, other));
		assert(lca(node, pathEnd)==pathEnd);
	}

	// count number of paths (z, t) in tree which have common length with (node... other) >= minCommon
	// given that common path of (any path in tree) and (node... other) has the max endpoint (by order) == pathEnd
	// where t is the "other endpoint" inserted into the tree

	assert(node!=other);

	auto const [_, dir, y]=lcaExtended(pathEnd, other);
	// only count the paths such that pathEnd is the max one
	if(minCommon<=depth[pathEnd]-depth[y]){
		auto const v=levelAncestor(pathEnd, minCommon-1); // t must not be a descendant of v
		result+=tree.sumSuffix(0)-tree.sumSuffix(first[v])+tree.sumSuffix(last[v]);
		if(first[node]<first[other]){
			// for some (z, t) paths, the other endpoint may be larger. Must filter them out.
			// in particular, filter out those in the subtree of dir.
			result-=tree.sumSuffix(first[dir])-tree.sumSuffix(last[dir]);
		}
	}else{
		int const level=(depth[other]-depth[y])-(minCommon-(depth[pathEnd]-depth[y]));
		if(level>=0){
			auto const v=levelAncestor(other, level); // t must be a descendant of v
			if(first[node]>first[other])
				result+=tree.sumSuffix(first[v])-tree.sumSuffix(last[v]);
		} // otherwise the remaining path has length < minCommon, does not contribute to result
	}
}

void updateResult(int node, int pathEnd){ // complexity: 7 log N * paths[node].size()
	assert(isAncestor(pathEnd, node));
	for(auto other: paths[node]) if(not isAncestor(pathEnd, other)){
		updateResultPath(node, pathEnd, other);
	}
}

void addPaths(int node, int pathEnd){ // complexity: log N * paths[node].size()
	assert(isAncestor(pathEnd, node));
	for(auto other: paths[node]) if(not isAncestor(pathEnd, other)){
		tree.change(first[other], 1);
	}
}

void removePaths(int node){ // complexity: log N * pathsRemove[node].size()
	for(auto other: pathsRemove[node]) {
		assert(tree.getElement(first[other])!=0);
		tree.change(first[other], -1);
	}
}

void iterateSubtree(int node, auto function /* (int node)->any */){
	std::for_each(first[node]+begin(order), last[node]+begin(order), function);
}


template<bool keep> void solve(int node){ // complexity: log N * log (subtree size) * (subtree size+sum paths size+sum pathsRemove size)
	assert(std::all_of(begin(tree.data),end(tree.data),[&](auto it){return it==0;}));
	if(not add[node].empty()){
		std::for_each(add[node].begin()+1, add[node].end(),[&](auto child){
			solve<false>(child);
		});

		solve<true>(add[node][0]);
		removePaths(add[node][0]);

		std::for_each(add[node].begin()+1, add[node].end(),[&](auto child){
			iterateSubtree(child,[&](auto it){ updateResult(it, node); });
			iterateSubtree(child,[&](auto it){ addPaths(it, node); });
		});
	}

	/*
	updateResult(node, node);
	addPaths(node, node);
	*/
	for(auto other: paths[node]){
		updateResultPath(node, node, other);
		tree.change(first[other], 1);
	}

	if(not keep){
		iterateSubtree(node,[&](auto descendant){
			for(auto other: paths[descendant])
				tree.forceReset(first[other]);
		});
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numPath;
	std::cin>>numNode>>numPath>>minCommon;
	add.resize(numNode);
	for(int _=0;_<numNode-1;++_) {
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		add[sec].push_back(first);
		assert(first!=sec);
	}

	depth.resize(numNode);
	par.resize(numNode); par[0]=-1;
	order.reserve(numNode);
	first.resize(numNode);
	last.resize(numNode);
	{
		auto const numNode_=work(0);
		assert(numNode==numNode_);
	}
	assert((int)order.size()==numNode);

	constructJumpTable();

	paths.resize(numNode);
	pathsRemove.resize(numNode);
	for(int _=0;_<numPath;++_) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		assert(first!=sec);
		auto const [first1, sec1, lca_]=lcaExtended(first, sec);
		if(depth[first]+depth[sec]-2*depth[lca_]>=minCommon){
			paths[first].push_back(sec);
			paths[sec].push_back(first);
			if(first1==sec1){
				assert(lca_==first or lca_==sec);
				pathsRemove[first1].push_back(lca_);
			}else{
				pathsRemove[first1].push_back(sec);
				pathsRemove[sec1].push_back(first);
			}
		}
	}
	assert(std::cin);

	assert(tree.data.empty());
	tree.data.resize(numNode);
	assert(result==0);
	solve<true>(0);
	//assert(result%2==0); result/=2;
	std::cout<<result<<'\n';
}