// time-limit: 3000
// problem-url: https://codeforces.com/contest/1586/problem/H

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	int numQuery; std::cin>>numQuery;
	std::vector<int> e(numNode);
	for(auto& it: e) {
		std::cin>>it;
	}
	
	struct Edge{int a, b, cap, toll;};
	std::vector<Edge> edges(numNode-1);
	for(auto& [a, b, cap, toll]: edges){
		std::cin>>a>>b; --a; --b;
		std::cin>>cap>>toll;
	}
	std::sort(begin(edges), end(edges), [&](auto const& first, auto const& sec){
		return first.cap<sec.cap;
	});

	struct Query{
		int queryIndex;
		int leastCap, node;
	};
	struct R{
		int maxE, maxToll;
	};
	std::vector<R> result(numQuery);
	std::vector<Query> queries(numQuery);
	for(int queryIndex=0; queryIndex<numQuery; ++queryIndex){
		auto& query=queries[queryIndex];
		query.queryIndex=queryIndex;
		std::cin>>query.leastCap>>query.node;
		--query.node;
	}
	std::sort(begin(queries), end(queries), [&](auto const& first, auto const& sec){
		return first.leastCap>sec.leastCap;
	});


	struct Edge2{int node, toll;};
	std::vector<std::vector<Edge2>> add(numNode);


	// the forest data structure
	struct Node{
		int root; // equal to itself if this is node
		int depth; // root has depth 0

		struct Jump{
			int node; // -1 if there's none
			int maxToll; // on the path. INT_MAX if there's none (mostly to catch bugs)
		};
		std::array<Jump, 20> jump;

		// data only meaningful for root
		int maxENode; // any node with maxE in this component
		int maxToll; // maximum toll on the edges connecting two maxE nodes in this component, or 0
		int size; // component size.
	};
	std::vector<Node> info(numNode);
	for(int node=0; node<numNode; ++node){
		info[node]={
			.root=node,
			.depth=0,
			.jump={}, // temp
			.maxENode=node,
			.maxToll=0,
			.size=1,
		};
		info[node].jump.fill({-1, INT_MAX});
	}

	auto const maxTollBetween=[&](int a, int b){
		assert(info[a].root==info[b].root);
		int result=0;
		int delta=info[a].depth-info[b].depth;
		if(delta<0){std::swap(a, b); delta=-delta;}
		for(; delta; delta&=delta-1){
			result=std::max(result,
					info[a].jump[__builtin_ctz(delta)].maxToll
					);
			a=info[a].jump[__builtin_ctz(delta)].node;
		}

		assert(info[a].depth==info[b].depth);

		if(a!=b){
			for(int layer=(int)info[a].jump.size(); layer--;){
				if(info[a].jump[layer].node!=info[b].jump[layer].node){
					result=std::max({result, info[a].jump[layer].maxToll, info[b].jump[layer].maxToll});
					a=info[a].jump[layer].node;
					b=info[b].jump[layer].node;
				}
			}
			assert(a!=b);
			result=std::max({result, info[a].jump[0].maxToll, info[b].jump[0].maxToll});
			a=info[a].jump[0].node;
			b=info[b].jump[0].node;
			assert(a==b);
		}

		return result;

	};

	for(auto [queryIndex, leastCap, node]: queries){
		auto const addEdge=[&](Edge edge){
			auto [a, b, cap, toll]=edge;
			add[a].push_back({b, toll});
			add[b].push_back({a, toll});

			if(info[info[a].root].size>info[info[b].root].size) std::swap(a, b);
			auto const newRoot=info[b].root;

			auto const oldRoot=info[a].root;

			auto const e1=info[oldRoot].maxENode;
			auto const e2=info[newRoot].maxENode;
			auto& t=info[newRoot].maxENode;
			bool needMaxTollUpdate=false;

			if(e[e1]>e[e2]){
				t=e1;
				info[newRoot].maxToll=info[oldRoot].maxToll;
			}else if(e[e1]==e[e2]){
				info[newRoot].maxToll=std::max(info[newRoot].maxToll, info[oldRoot].maxToll);
				needMaxTollUpdate=true;
			}else{
				t=e2;
			}

			if(e[e1]>e[t]) t=e1;
			


			info[newRoot].size+=info[oldRoot].size;

			// fill the nodes in old component of a to point to root=newRoot
			auto const work=[&](auto work, int node, int par, int parToll, int depth)->void{
				assert(node!=newRoot);
				info[node]={
					.root=newRoot,
					.depth=depth,
					.jump={}, // temp, fill below
				};
				info[node].jump.fill({-1, INT_MAX});

				Node::Jump tmp=info[node].jump[0]={par, parToll};
				for(int i=1; i<(int)info[node].jump.size(); ++i){
					auto [node1, maxToll1]=info[tmp.node].jump[i-1];
					if(node1<0) break;
					tmp.maxToll=std::max(tmp.maxToll, maxToll1);
					tmp.node=node1;
					info[node].jump[i]=tmp;
				}

				for(auto [child, curToll]: add[node]) if(child!=par){
					work(work, child, node, curToll, depth+1);
				}
			};
			work(work, a, b,
					toll,
					info[b].depth+1);

			if(needMaxTollUpdate)
			info[newRoot].maxToll=std::max(info[newRoot].maxToll,
					maxTollBetween(e1, e2));
		};

		while(not edges.empty() and edges.back().cap>=leastCap){
			addEdge(edges.back()); edges.pop_back();
		}

		auto const processQuery=[&](int const node){

			// part 1. Find maximum e of this component
			auto const work=[&](auto work, int node, int par)->int{
				int result=e[node];
				for(auto [child, curToll]: add[node]) if(child!=par){
					result=std::max(result, work(work, child, node));
				}
				return result;
			};
			auto const maxENode=info[info[node].root].maxENode;
			auto const maxE=e[maxENode];
			assert(maxE==work(work, node, -1));

			int maxToll=std::max(
					info[info[node].root].maxToll,
					maxTollBetween(node, maxENode)
					);

			// part 2. For maximum e, find maximum toll
			auto const work2=[&](auto work2, int node, int par, int maxTollUp)->int{
				int result=0;
				if(maxE==e[node]) result=maxTollUp;
				for(auto [child, curToll]: add[node]) if(child!=par){
					result=std::max(result, work2(work2, child, node,
								std::max(maxTollUp, curToll))
							);
				}
				return result;
			};
			assert(maxToll==work2(work2, node, -1, 0));
			return R{maxE, maxToll};
		};

		result[queryIndex]=processQuery(node);
	}

	for(auto [maxE, maxToll]: result)
		std::cout<<maxE<<' '<<maxToll<<'\n';
}