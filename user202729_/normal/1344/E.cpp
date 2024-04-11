// .........

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

//#define NAIVE 1

struct edge{ int node, len; };
std::vector<std::vector<edge>> add;
#if NAIVE
std::vector<int> par;
#endif

std::vector<int64_t> depth;
std::vector<int> subtreeSize;

void compute(int node){
	subtreeSize[node]=1;
	for(auto [child, len]: add[node]){
		depth[child]=depth[node]+len;
#if NAIVE
		par[child]=node;
#endif
		compute(child);
		subtreeSize[node]+=subtreeSize[child];
	}
}

std::vector<std::vector<int>> trains;

std::vector<std::pair<int64_t, int64_t>> limits;

void addLimit(int64_t left, int64_t right){
	// some switch change must happen at time >=left and <right
	limits.push_back({left, right});
}

int64_t explode=INT64_MAX;
std::set<int64_t> work(int node){ // returns the set of train start times that the trains' destinations are inside the subtree of node
	if(add[node].empty())
		return {begin(trains[node]),end(trains[node])};


	std::tuple<int, int, int> tmp={-1, -1, -1};
	for(auto [child, len]: add[node])
		tmp=std::max(tmp, std::tuple{subtreeSize[child], len, child});
	auto const [maxChildSize, maxChildLen, heavyChild]=tmp;

	auto result=work(heavyChild);

	//auto lastChildFirst=INT64_MAX;
	//if(heavyChild==add[node].back().node and not result.empty()) lastChildFirst=*result.begin();

	auto const process=[&](auto first, auto sec){
		if(first==sec){
			explode=std::min(explode, first);
			return;
		}
		assert(first<sec);
		// first<sec are two start times of two trains that has destinations inside this subtree
		// and their destinations' lca is at this node
		assert(first+depth[node]>=0);
		addLimit(first+depth[node], sec+depth[node]);
	};

	struct T{
		int64_t time; int child;
		bool operator<(T other) const{ return time<other.time; }
	};
	std::vector<T> lightData;
	lightData.push_back({-depth[node], add[node].back().node}); // small hack to simplify implementation
	// ^ ( :( this created more bugs and special cases than it helps to solve, apparently?...

	for(auto [child, len]: add[node]) if(child!=heavyChild){
		/*
		auto other=work(child);
		if(other.empty()) continue;
		if(child==add[node].back().node) lastChildFirst=*other.begin();
		for(auto startTime: other) lightData.push_back({startTime, child});
		*/
		for(auto startTime: work(child)) lightData.push_back({startTime, child});
	}
	std::sort(begin(lightData),end(lightData));

	for(int index=0;index<(int)lightData.size();++index) {
		T const lightPrev=index==0 ? T{INT64_MIN, -1}: lightData[index-1];
		T const lightCur =lightData[index];
		T const lightNext=index+1==(int)lightData.size() ? T{INT64_MAX, -1}: lightData[index+1];

		auto heavyNext=result.lower_bound(lightCur.time);  // assumes that heavy time is added to (prep?) epsilon
		if(heavyNext!=result.end() and *heavyNext<lightNext.time){
			if(heavyChild==lightCur.child){
				// special case
				assert(index==0);
			}else{
				process(lightCur.time, *heavyNext);
			}
		}
		else {
			if(lightCur.child!=lightNext.child and lightNext.child>=0)
				process(lightCur.time, lightNext.time); // [1]
		}

		if(heavyNext!=result.begin()){
			auto heavyPrev=std::prev(heavyNext);
			if(*heavyPrev>=lightPrev.time)
				process(*heavyPrev, lightCur.time);
			else {
				assert(lightPrev.child!=-1);
				if(lightCur.child!=lightPrev.child){
					// don't do anything, already handled by [1]
				}
			}
		}
	}

	assert(lightData[0].time==-depth[node]);
	std::for_each(1+begin(lightData),end(lightData), [&](auto it){ 
		result.insert(it.time); // ignores duplicates (already updated to explode)
	});
	// (actually it's not possible to have O-length segments. Simplify the problem a little and avoid having to check for edge cases/off-by-one errors)
		

	// now result contains data of both light and heavy children
	//if(not result.empty() and *result.begin()<lastChildFirst){
	//	addLimit(0, *result.begin()+depth[node]);
	//}

	for(auto it: trains[node]) result.insert(it); // might conflict, it's okay
	return result;
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numTrain; std::cin>>numNode>>numTrain;
	add.resize(numNode);
	for(int _=0;_<numNode-1;++_) {
		int first, sec, len; std::cin>>first>>sec>>len;
		--first;--sec;
		add[first].push_back({sec, len});
	}

	trains.resize(numNode);
	for(int _=0;_<numTrain;++_) {
		int node, time; std::cin>>node>>time;
		--node;
		trains[node].push_back(time);
	}

	depth.resize(numNode);
	subtreeSize.resize(numNode);
	// depth[0]=0;

#if NAIVE
	par.resize(numNode);
#endif
	compute(0);

#if NAIVE
	std::vector<std::vector<std::pair<int, int64_t> /* (child (direction), time) */ >> changes(numNode);
	for(int node=0;node<numNode;++node) 
		for(auto start: trains[node]){
			auto node_=node;
			while(node_!=0){
				changes[par[node_]].push_back({node_, depth[par[node_]]+start});
				node_=par[node_];
			}
		}

	for(int node=0;node<numNode;++node) if(not changes[node].empty()) {
		int64_t lastTime=0;
		int lastChild=add[node].back().node;
		std::sort(begin(changes[node]),end(changes[node]),[&](auto x, auto y){ return x.second<y.second; });
		for(auto [child, time]: changes[node]){
			if(child!=lastChild){
				limits.push_back({lastTime, time});
				lastChild=child;
			}
			lastTime=time;
		}
	}
#else
	work(0);
#endif

	std::sort(begin(limits),end(limits)
			//,[&](auto first, auto sec){ return first.first<sec.first; }
			);
	int64_t left=0;
	std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> rights;

	auto inserted=limits.begin();
	auto const insertRight=[&]{
		while(inserted!=limits.end() and inserted->first<=left){
			rights.push(inserted->second);
			++inserted;
		}
	};

	insertRight();
	while(inserted!=limits.end() or not rights.empty()){
		if(rights.empty()){
			left=inserted->first;
		}else{
			auto right=rights.top(); rights.pop();
			if(right<=left){
				explode=std::min(explode, left);
				break;
			}
			++left;
		}
		insertRight();
	}

	if(explode!=INT64_MAX){
		std::cout<<explode<<' '<<
			std::count_if(begin(limits),end(limits),[&](auto it){ return it.second<explode; })
			<<'\n';
	}else{
		std::cout<<"-1 "<<limits.size()<<"\n";
	}
}