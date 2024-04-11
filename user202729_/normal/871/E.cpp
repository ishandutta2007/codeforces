#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	if(false){
failed:
		std::cout<<"-1\n"; return 0;
	}

	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numRemember; std::cin>>number>>numRemember;

	// {node, [distance node to x for x in range(number)]}
	struct Remembered{
		int node;
		std::vector<int> distance;
		std::vector<int> parents; // to some particular fixed root
	};
	std::vector<Remembered> distance;
	distance.reserve(numRemember);

	std::vector<char> constructed(number);
	std::vector<std::vector<int>> add(number);
	auto const addEdge=[&](int first, int sec){
		assert(first!=sec);
		add[first].push_back(sec); add[sec].push_back(first);
	};

	for(int _=0; _<numRemember; ++_){
		std::vector<int> value(number);
		for(auto & it: value) std::cin>>it;
		if(std::count(begin(value), end(value), 0)!=1) goto failed;
		auto const node=int(std::find(begin(value), end(value), 0)-value.begin());

		if(not distance.empty()){
			struct{ int nearestConstructed=-1, minDistance=INT_MAX; } data;
			for(int it=0; it<number; ++it)if(constructed[it])
				if(value[it]<data.minDistance)
					data={it, value[it]};
			assert(data.nearestConstructed>=0);

			auto const& [top, distanceTop, _]=distance[0];

			auto const d=distanceTop[node];
			if(d!=value[top]) goto failed;
			if(d!=data.minDistance+distanceTop[data.nearestConstructed]) goto failed;

			std::vector<int> path(data.minDistance+1, -1);
			for(int other=0; other<number; ++other)
				if(value[other]<=data.minDistance and value[other]+distanceTop[other]==d){
					if(path[value[other]]>=0) goto failed;
					path[value[other]]=other;
				}
			if(std::any_of(begin(path), end(path),[&](auto it){return it<0;})) goto failed;
			if(path[0]!=node) goto failed; // can this be changed to an assert?...


			for(int index=0; index<(int)path.size()-1; ++index){
				addEdge(path[index], path[index+1]);
				if(constructed[path[index]]) goto failed;
				constructed[path[index]]=true;
			}
		}else constructed[node]=true;

		distance.push_back({node, std::move(value), {}});
	}
	assert((int)distance.size()==numRemember);

	auto const root=distance[0].node;
	{
		auto const& distanceRoot=distance[0].distance;
		for(auto & [node, distance, parents]: distance){
			assert(parents.empty());
			parents.push_back(node);
			while(parents.back()!=root){
				auto const node1=parents.back();
				for(auto other: add[node1])if(distanceRoot[other]==distanceRoot[node1]-1){
					parents.push_back(other);
					goto next_parent;
				}
				goto failed;
next_parent:;
			}
		}
	}


	// construct the rest
	struct Item{int distance, node;};
	std::vector<std::vector<Item>> items(number); // nearest->unconstructed node
	for(int node=0; node<number; ++node)if(not constructed[node]){
		std::sort(begin(distance), end(distance),[&](auto const& first, auto const& sec){
			return first.distance[node]<sec.distance[node];
		});

		auto data=std::pair(INT_MAX, -1);
		for(int index=1; index<(int)distance.size(); ++index){
			auto const a=distance[0].distance[node],
			b=distance[0].distance[distance[index].node],
			c=distance[index].distance[node];
			assert(a<=c);
			if(a+b+c<2*std::max(b, c)) goto failed; // triangle inequality
			if(a+b>c){
				if((a+c-b)%2!=0) goto failed;
				data=std::min(data, std::pair((a+c-b)/2, index));
			}
		}

		if(data.second<0){
			items[distance[0].node].push_back({distance[0].distance[node], node});
		}else{
			auto const [d, index]=data;
			auto const dleft=distance[0].distance[node]-d, dright=distance[index].distance[node]-d,
				rleft_=distance[0].distance[root], rright_=distance[index].distance[root],
				b=distance[0].distance[distance[index].node];
			if(rleft_+rright_+b<2*std::max({rleft_, rright_, b})
					or (rleft_+rright_+b)%2!=0) goto failed;
			auto const rleft=(rleft_+b-rright_)>>1, rright=(rright_+b-rleft_)>>1;

			if(rleft+rright!=b) goto failed;
			assert(dleft+dright==b);
			if(dleft<=rleft){
				items[distance[0].parents[dleft]].push_back({d, node});
			}else{
				assert(dright<=rright);
				items[distance[index].parents[dright]].push_back({d, node});
			}
		}
	}

	for(int node=0; node<number; ++node)if(not items[node].empty()){
		auto& itemsNode=items[node];
		std::sort(begin(itemsNode), end(itemsNode),[&](auto first, auto sec){return first.distance<sec.distance;});
		if(itemsNode[0].distance!=1) goto failed;
		Item last{0, node}, pending{-1, -1};
		for(auto const [distance, node1]: itemsNode){
			if(last.distance!=distance-1) {
				last=pending;
				if(last.distance!=distance-1) goto failed;
			}
			addEdge(last.node, node1);
			pending={distance, node1};
		}
	}

	// check
	for(auto const& [node, distanceNode, _]: distance){
		assert(distanceNode[node]==0);
		for(int a=0; a<number; ++a)if(a!=node){
			auto const distanceA=distanceNode[a];
			bool seenLess=false;
			for(auto b: add[a]){
				if(distanceNode[b]==distanceA-1) seenLess=true;
				else if(distanceNode[b]!=distanceA+1) goto failed;
			}
			if(not seenLess) goto failed;
		}
	}

	for(int a=0; a<number; ++a)
		for(auto b: add[a])
			if(a>b) std::cout<<a+1<<' '<<b+1<<'\n';
}