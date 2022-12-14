#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
4 2
1 2 1000
3 4 1
1 2

)");}
#endif // Sublime


struct PersistentTree{
	static int constexpr DEPTH=17;
	static int constexpr ZERO_AT_DEPTH=1+2*DEPTH; // <- implementation details

	using Node=std::pair<int,int>;
	using NodePtr=int;

	struct NodeHash{
		std::size_t operator() (Node x) const{
			return x.first*(std::size_t)100003+x.second;
		}
	};

private:
	std::vector<Node> nodePool;
	std::unordered_map<Node,NodePtr,NodeHash> nodeCache;
	//^ to ensure that two nodes have the same ptr always have same value

	NodePtr left (NodePtr x)const{return nodePool[x].first;}
	NodePtr right(NodePtr x)const{return nodePool[x].second;}

public:
	PersistentTree(){
		// prepare some nodes for reserved use
		nodePool.emplace_back(-1,0); // for the leaf [0], value=0
		nodePool.emplace_back(-1,1); // for the leaf [1], value=1

		NodePtr i=1;
		for(int j=DEPTH;j-->0;)i=construct(i,i);
		// the only nodes contains all 1s have index [1..DEPTH+1]

		i=0;
		for(int j=DEPTH;j-->0;)i=construct(i,i);
	}

	/// given a node return whether it consists of all ones.
	static bool all1(NodePtr node){
		return 0<node&&node<=(DEPTH+1);
	}

	static bool isLeaf(NodePtr node){
		return node<2;
	}

	/// given a nonleaf (all1) node return a node with same size and all0.
	static NodePtr zeroAll1(NodePtr node){
		assert(all1(node)&&!isLeaf(node));
		return node+DEPTH;
	}

	NodePtr construct(Node n){
		auto it=nodeCache.find(n);
		if(it!=nodeCache.end())return it->second;

		NodePtr const ans=nodePool.size();
		nodeCache.insert({n,ans});
		nodePool.push_back(n);
		return ans;
	}
	NodePtr construct(NodePtr left,NodePtr right){
		return construct({left,right});
	}

	// For this problem's purpose each node will be used to represent
	// a number. So it's necessary to compare them. Assume the left
	// subtree is less significant than the right subtree.
	int compare(NodePtr x,NodePtr y)const{
		if(x==y)return 0;
		if(x<2&&y<2)return (x>y)-(x<y);
		int cmp_right=compare(right(x),right(y));
		if(cmp_right!=0)return cmp_right;
		return compare(left(x),left(y));
	}

private:
	// return {node + 2 ** expo, carry}. parameter: d: depth.
	std::pair<NodePtr,bool> add2Pow_(NodePtr node,int expo,int d){
		assert(expo<(1<<d));

		// leaf
		if(d==0){
			assert(isLeaf(node));
			return {node^1,node};
		}else assert(!isLeaf(node));

		// special case to ensure logarithmic complexity
		if(expo==0&&all1(node)){
			return {zeroAll1(node),true};
		} 

		// left st is not touched
		if(expo>=(1<<(d-1))){
			auto [r,carry]=add2Pow_(right(node),expo-(1<<(d-1)),d-1);
			return {construct(left(node),r),carry};
		}

		auto [l,lCarry]=add2Pow_(left(node),expo,d-1);
		if(lCarry){
			auto [r,carry]=add2Pow_(right(node),0,d-1);
			return {construct(l,r),carry};
		}else{
			return {construct(l,right(node)),false};
		}
	}

	int depth(NodePtr node)const{
		int depth=0;
		while(!isLeaf(node)){
			node=left(node);
			++depth;
		}
		return depth;
	}

public:
	NodePtr add2Pow(NodePtr node,int expo){
		assert(depth(node)==DEPTH);
		auto [ans,carry]=add2Pow_(node,expo,DEPTH);
		assert(!carry);
		return ans;
	}

	static int constexpr MOD=1e9+7;
	// return (actual value, width) where (width) == 1+maximum
	// value == 1<<depth

private:
	std::pair<int,int> mod_(NodePtr node)const{
		if(isLeaf(node))return {node,2};
		auto [ leftVal,width]=mod_(left(node));
		auto [rightVal,widt1]=mod_(right(node));
		assert(width==widt1);
		widt1=width*(int64_t)width%MOD;
		return {((int64_t)rightVal*width+leftVal)%MOD,widt1};
	}

public:
	int mod(NodePtr node)const{
		return mod_(node).first;
	}

};

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int nNode,nEdge;std::cin>>nNode>>nEdge;

	std::vector<std::vector<std::pair<int,int>>>adjl(nNode);
	for(int i=nEdge;i-->0;){
		int u,v,lg2_weight;
		std::cin>>u>>v>>lg2_weight;--u;--v;
		adjl[u].emplace_back(v,lg2_weight);
		adjl[v].emplace_back(u,lg2_weight);
	}
	int src,dest;std::cin>>src>>dest;--src;--dest;

	static PersistentTree dists;
	std::vector<PersistentTree::NodePtr>dist(nNode,-1);
	std::vector<int>trace(nNode,-1);

	using state=std::pair<PersistentTree::NodePtr,int>;
	struct StateComparator{
		bool operator() (state a,state b){
			return dists.compare(a.first,b.first)>0;
		}
	};
	std::priority_queue<state,std::vector<state>,StateComparator>pq;

	pq.emplace(dist[src]=dists.ZERO_AT_DEPTH,src);
	while(!pq.empty()){
		auto [distNode,node]=pq.top();pq.pop();
		if(distNode!=dist[node])continue;
		if(node==dest)break;
		for(auto edge:adjl[node]){
			auto d1=dists.add2Pow(distNode,edge.second);
			if(dist[edge.first]<0||dists.compare(d1,dist[edge.first])<0){
				pq.emplace(dist[edge.first]=d1,edge.first);
				trace[edge.first]=node;
			} // else does nothing
		} // next edge
	}

	if(dist[dest]<0){
		std::cout<<"-1\n";
		return 0;
	}

	std::cout<<dists.mod(dist[dest])<<'\n';

	std::vector<int> path;
	path.push_back(dest);
	while(path.back()!=src)path.push_back(trace[path.back()]);

	std::cout<<path.size()<<'\n';
	for(unsigned i=path.size();i-->0;)std::cout<<1+path[i]<<' ';
	std::cout<<'\n';
}