// some implementation work can take surprisingly long, especially when I don't remember how to use node.
// (I didn't look it up this time)

// also, (try to) compute the actual time complexity first (if it doesn't take too long)
// 

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numLose; std::cin>>numLose;
	int numQuery; std::cin>>numQuery;

	struct Query{
		int queryIndex; // -1->specified lose position
		int a, b;
		int size() const{return std::max(a, b)+1;}
	};
	std::vector<Query> queries(numQuery+numLose);
	int const losePos=-1;
	for(int index=numQuery; index<numQuery+numLose; ++index){
		queries[index].queryIndex=losePos;
		std::cin>>queries[index].a>>queries[index].b;
	}
	for(int index=0; index<numQuery; ++index){
		queries[index].queryIndex=index;
		std::cin>>queries[index].a>>queries[index].b;
	}
	std::sort(begin(queries), end(queries), [&](auto const& first, auto const& sec){
		return std::max(first.a, first.b)>std::max(sec.a, sec.b);
	});

	std::set<int> gapUnadded{};
	int gapLazy{};
	bool dim{};

	std::vector<char> result(numQuery);
	int size=0;
	std::array<std::vector<int>, 2> lose;  // NOTE temporary variable inside each loop iteration
	while(not queries.empty()){
		if(gapUnadded.empty() or (*gapUnadded.rbegin()+gapLazy==size-1 and *gapUnadded.begin()+gapLazy==size-(int)gapUnadded.size())){
			assert(size<queries.back().size());
			auto const delta=queries.back().size()-1-size;
			size=queries.back().size()-1;
			assert(delta>=0);
			gapLazy+=delta;
		}

		size++;
		assert(size<=queries.back().size());
		auto iterator=queries.end();
		while(iterator!=queries.begin() and iterator[-1].size()==size) --iterator;

		for(auto& it: lose) it.clear();
		// (size-1, lose[0])
		// (lose[1], size-1)

		std::for_each(iterator, queries.end(), [&](auto const& it){
			if(it.queryIndex<0){
				if(it.a==size-1) lose[0].push_back(it.b);
				if(it.b==size-1) lose[1].push_back(it.a);
				assert(it.a==size-1 or it.b==size-1);
			}
		});

		if(gapUnadded.empty()){
			if(lose[0].empty() and lose[1].empty()){
				lose[0].push_back(size-1);
				lose[1].push_back(size-1);
			}
		}else{
			if(lose[dim].empty() or *std::min_element(begin(lose[dim]), end(lose[dim]))
					>*gapUnadded.begin()+gapLazy){
				lose[dim].push_back(*gapUnadded.begin()+gapLazy);
				gapUnadded.erase(gapUnadded.begin()); // will be deleted by (1) below anyway
			}
		}

		for(auto it: lose[dim]) gapUnadded.erase(it-gapLazy); // (1) -- if exists

		assert(not(lose[0].empty() and lose[1].empty()));
		if(lose[0].empty()){
			assert(gapUnadded.empty() or dim==1);
			gapUnadded.insert(size-1-gapLazy);
			dim=1;
		}
		if(lose[1].empty()){
			assert(gapUnadded.empty() or dim==0);
			gapUnadded.insert(size-1-gapLazy);
			dim=0;
		}

		std::sort(begin(lose[0]), end(lose[0]));
		std::sort(begin(lose[1]), end(lose[1]));

		std::for_each(iterator, queries.end(), [&](auto const& it){
			if(it.queryIndex>=0){
				result[it.queryIndex]=(
						not(
							it.a==size-1 ?
							std::binary_search(begin(lose[0]), end(lose[0]), it.b):
							std::binary_search(begin(lose[1]), end(lose[1]), it.a)
						   )
						);
			}
		});

		queries.erase(iterator, queries.end());
	}

	for(auto it: result)
		std::cout<<(it ? "WIN\n": "LOSE\n");
}