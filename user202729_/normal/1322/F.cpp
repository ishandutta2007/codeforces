




#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

void add_edge(int u,int v){
	add[u].push_back(v);
	add[v].push_back(u);
}

std::vector<int> depth;
std::vector<int> par;
std::vector<int> subtreeSize;
std::vector<int> postOrder;

void dd(int x,int parx=-1){
	par[x]=parx;
	//subtree_size[x]=1;
	for(int y:add[x]){
		//add[y].erase(std::find(begin(add[y]),end(add[y]),x));
		if(y==parx) continue;

		depth[y]=depth[x]+1;
		dd(y,x);
		//subtree_size[x]+=subtree_size[y];
	}
	postOrder.push_back(x);
}

std::vector<std::vector<int>> jt;

void init_jt(){
	jt.push_back(par);
	for(;;){
		bool useful=false;
		auto const& a=jt.back();
		auto b=a;
		for(auto& x:b)if(x>=0){
			if((x=a[x])>=0)
				useful=true;
		}
		if(useful)
			jt.push_back(std::move(b));
		else
			break;
	}
}

struct lca_result {
	int u1,v1,lca; // u1,v1: child of lca int the direction of u/v resp.
	// int case lca is u or v, both u1 and v1 are int the direction of the node != lca
};

lca_result lca(int u,int v){
	assert(u!=v);

	bool swapped;
	if((swapped=(depth[u]<depth[v])))std::swap(u,v);

	int ddepth=depth[u]-depth[v];
	if(ddepth){
		--ddepth;
		for(;ddepth;ddepth^=ddepth&-ddepth){
			u=jt[__builtin_ctz(ddepth)][u];
		}
		assert(depth[u]-1==depth[v]);
		if(jt[0][u]==v)return {u,u,v};
		u=jt[0][u];
	}
	assert(u!=v);
	for(auto layer=jt.size();layer--;){
		if(jt[layer][u]!=jt[layer][v])
			std::tie(u,v)=std::make_pair(jt[layer][u],jt[layer][v]);
	}
	assert(jt[0][u]==jt[0][v]);
	if(swapped)std::swap(u,v);
	assert(u!=v);
	return {u,v,jt[0][u]};
}


std::vector<int> tail; // tail[x]=y => path (x... y) have the same direction
std::vector<std::vector<std::pair<int, int>>> pairs;
// [u, v] in pairs[lca] => (edge (u, lca) is up) xor (edge (v, lca) is up)

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numPath; std::cin>>numNode>>numPath;

	add.resize(numNode);
	for(int z=numNode-1;z--;){
		int u,v;
		std::cin>>u>>v;
		--u;--v;
		add_edge(u,v);
	}

	postOrder.reserve(numNode);
	par.resize(numNode); depth.resize(numNode);
	par[0]=-1;
	depth[0]=0;
	dd(0);
	assert((int)postOrder.size()==numNode);
	init_jt();

	tail.resize(numNode);
	std::iota(begin(tail),end(tail), 0);

	auto const updateTail=[&](int v, int u){
		if(depth[u]<depth[tail[v]]) tail[v]=u;
	};

#ifdef LOCAL
	std::vector<std::pair<int, int>> inputPaths;
#endif

	pairs.resize(numNode);
	for(auto _=numPath;_--;){
		int u,v;
		std::cin>>u>>v;
		--u;--v;
		assert(u!=v);
#ifdef LOCAL
		inputPaths.push_back({u, v});
#endif
		auto it=lca(u, v);
		if(it.u1==it.v1){
			if(v==it.lca) std::swap(u, v);
			assert(u==it.lca);
			updateTail(v, u);
		}else{
			updateTail(u, it.lca);
			updateTail(v, it.lca);
			pairs[it.lca].push_back({it.u1, it.v1});
		}
	}

	for(auto node:postOrder){
		assert(depth[tail[node]]<=depth[node]);
		if(tail[node]!=node and tail[node]!=par[node]){
			updateTail(par[node], tail[node]);
			pairs[par[node]].push_back({par[par[node]], node});
		}
	}


	std::vector<std::vector<std::array<std::vector<int>, 2>>> components(numNode);
	// bipartite components
	{
		std::vector<std::vector<int>> subadd(numNode);
		// used for computing `components`
		std::vector<char> color(numNode); // -1, 0 or 1
		std::vector<int> queue; queue.reserve(numNode);

		for(int node=numNode; node--;){
			assert(par[node]==-1 or std::find(begin(add[node]),end(add[node]), par[node])!=end(add[node]));
			for(auto other: add[node]){
				subadd[other].clear();
				color[other]=-1;
			}
			for(auto [first, sec]: pairs[node]){
				subadd[first].push_back(sec);
				subadd[sec].push_back(first);
			}
			assert(components[node].empty());
			for(auto other: add[node]) if(color[other]<0){
				color[other]=0;
				std::array<std::vector<int>, 2> component;
				queue.clear();
				queue.push_back(other);
				component[color[other]=0].push_back(other);
				for(auto iterator=begin(queue); iterator!=end(queue);++iterator){
					assert((int)queue.size()<=numNode);
					auto node=*iterator;
					auto const colorNode=color[node];

					assert(colorNode==0 or colorNode==1);
					assert(std::count(begin(component[colorNode]),end(component[colorNode]), node)==1);
					for(auto other: subadd[node]){
						if(color[other]==colorNode){
							std::cout<<"-1\n";
							return 0;
						}
						if(color[other]<0){
							component[color[other]=not colorNode].push_back(other);
							queue.push_back(other);
						}
					}
				}

				components[node].push_back(std::move(component));
			}

			if(par[node]>=0){ // rearrange the components so [0][0] is the component that contains par[node]
				assert(color[par[node]]!=-1);
				std::swap(components[node][0], *std::find_if(begin(components[node]),end(components[node]),[&](auto const& component){
					return std::any_of(begin(component),end(component),[&](auto const& side){
						return std::find(begin(side),end(side), par[node])!=end(side);
					});
				}));
				auto& component=components[node][0];
				if(std::find(begin(component[0]),end(component[0]), par[node])==end(component[0]))
					std::swap(component[0], component[1]);
				assert(std::find(begin(component[0]),end(component[0]), par[node])!=end(component[0]));
			}
		}
	}

	pairs.clear(); // don't use this anymore, use `components` instead

	std::vector<int> f;
	// f[node] = minimum down length from node,
	// if all paths in that substring has length <= maximumPathLength,
	// and the edge (par[node]..node) points down

	auto const fillF=[&](int maximumPathLength){
		f.assign(numNode, 0);
		for(auto node: postOrder){
			std::vector<std::array<int, 2>> componentLength(components[node].size());
			assert(par[node]==-1 or f[par[node]]==0);
			for(int index=0;index<(int)components[node].size();++index) {
				auto const& component=components[node][index];
				std::array<int, 2> result;
				std::transform(begin(component),end(component), begin(result),
						[&](auto const& side){
							int result=0;
							for(auto node: side) if(tail[node]!=node)
								result=std::max(result, f[node]+1);
							return result;
						});
				if(result[0]+result[1]>maximumPathLength) return false;
				if(index!=0 or par[node]<0){
					std::sort(begin(result),end(result), std::greater<>());
				}else{
					// result[0] must be max up distance, result[1] must be max down distance
				}
				componentLength[index]=result;
			}

			int minimumUp=std::accumulate(begin(componentLength),end(componentLength), 0,
					[](int minimumUp, auto const& componentLength){
						return std::max(minimumUp, std::min(componentLength[0], componentLength[1]));
					});
			if(par[node]>=0){
				minimumUp=std::max(minimumUp, componentLength[0][0]);
				if(tail[node]==node){
					assert(components[node][0][0].size()==1 and
							components[node][0][0][0]==par[node] and
							components[node][0][1].empty());
				}
			}

			std::sort(begin(componentLength),end(componentLength),[&](auto first, auto sec){
				return first[0]>sec[0];
			});
			int maximumDown=std::accumulate(begin(componentLength),end(componentLength), 0,
					[](int maximumDown, auto const& componentLength){
						return std::max(maximumDown, componentLength[1]);
					});
			for(auto [up, down]: componentLength){
				// consider maximumUp = std::max(minimumUp, up),
				// then it's possible that maximumDown == maximumDown
				if(std::max(up, minimumUp)+maximumDown<=maximumPathLength)
					goto okay; // the choice with minimum possible maximumDown

				if(up<minimumUp) return false; // short circuit
				maximumDown=std::max(maximumDown, up /* when swapped */);
			}
			return false;
okay:

			f[node]=maximumDown;
		}
		return true;
	};

	int maximumPathLength=numNode;
	assert(numPath>0);
	for(int step=1<<22; step>>=1;) if(maximumPathLength-step>0 and fillF(maximumPathLength-step)){
		maximumPathLength-=step;
	}
	{
		auto success=fillF(maximumPathLength);
		assert(success);
	}

	std::vector<char> parUp(numNode);
	assert(par[postOrder.back()]==-1);
	std::vector<std::vector<int>> inpath(numNode);
	// b in inpath[a] -> value of b must be larger than value of a

	std::for_each(postOrder.rbegin(), postOrder.rend(),[&](int node){
		int const maximumDownLength=f[node];
		int const maximumUpLength=maximumPathLength-f[node];
		assert(maximumUpLength>=0);

		for(int index=0;index<(int)components[node].size();++index) {
			auto const& component=components[node][index];
			std::array<int, 2> result;
			std::transform(begin(component),end(component), begin(result),
					[&](auto const& side){
						int result=0;
						for(auto it: side) if(tail[it]!=it and it!=par[node])
							result=std::max(result, f[it]+1);
						return result;
					});

			bool swap=false;
			// can exchange up/down
			if(not (result[0]<=maximumUpLength and result[1]<=maximumDownLength)){
				assert(index!=0 or par[node]<0); // can swap freely
				swap=true;
				std::swap(result[0], result[1]);
			}
			assert(result[0]<=maximumUpLength and result[1]<=maximumDownLength);

			for(int index=0;index<2;++index) for(auto it:component[index]) if(it!=par[node]){
				assert(par[it]==node);
				if(tail[it]!=it){
					parUp[it]=bool(parUp[node] xor swap xor index xor 1);
					if(parUp[it]) inpath[it].push_back(node);
					else inpath[node].push_back(it);
				}
			}
		}
	});

	std::vector<int> longestPathLength(numNode); // that ends at this node
	std::vector<int> indegree(numNode);
	for(auto const& it: inpath)
		for(auto const node: it) ++indegree[node];
	std::vector<int> pending;
	for(int node=0;node<numNode;++node)
		if(indegree[node]==0) pending.push_back(node);
	while(not pending.empty()){
		auto node=pending.back(); pending.pop_back();
		auto const nextLongestPathLength=longestPathLength[node]+1;
		for(auto other: inpath[node]){
			--indegree[other];
			longestPathLength[other]=std::max(longestPathLength[other], nextLongestPathLength);
			if(indegree[other]==0) pending.push_back(other);
		}
	}

	assert(maximumPathLength==*std::max_element(begin(longestPathLength),end(longestPathLength)));

	assert(std::all_of(begin(indegree),end(indegree),[&](auto it){return it==0;}));
#ifdef LOCAL
	auto const direction=[&](int node, int ancestor){
		assert(node!=ancestor);
		auto const direction=longestPathLength[node]<longestPathLength[par[node]];
		for(; par[node]!=ancestor; node=par[node]){
			assert(direction==(longestPathLength[node]<longestPathLength[par[node]]));
			assert(longestPathLength[node]!=longestPathLength[par[node]]);
		}
		return direction;
	};
	for(auto [first, sec]: inputPaths){
		auto w=lca(first, sec).lca;
		if(sec==w) std::swap(first, sec);
		if(first==w)
			direction(sec, w);
		else
			%assert(direction(first, w)!=direction(sec, w));
	}
#endif

	std::cout<<maximumPathLength+1<<'\n';
	for(int node=0;node<numNode;++node) std::cout<<longestPathLength[node]+1<<' ';
	std::cout<<'\n';
}