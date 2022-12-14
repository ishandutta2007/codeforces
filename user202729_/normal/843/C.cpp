// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

int number;
int throwCentroid(int const node, int par){
	int maxChild=-1;
	int subsize=1;
	for(auto it: add[node]) if(it!=par){
		//add[it].erase(std::find(begin(add[it]), end(add[it]), node));
		int childSize=throwCentroid(it, node);
		maxChild=std::max(maxChild, childSize);
		subsize+=childSize;
	}
	if(std::max(number-subsize, maxChild)*2<=number){
		if(subsize*2==number)
			throw std::pair{node, par};
		else
			throw std::pair{node, -1};
	}
	return subsize;
}
auto findCentroid(){
	try{
		throwCentroid(0, -1);
	}catch(std::pair<int, int> centroid){
		return centroid;
	}
	assert(false); __builtin_unreachable();
}

#if LOCAL
#define local(...) __VA_ARGS__
#else
#define local(...)
#endif

local(std::vector<std::vector<int>> add1;)

std::vector<std::array<int, 3>> operations;
void operation(int a, int b, int c){
	operations.push_back({a, b, c});
#if LOCAL
	add1[a].erase(std::find(begin(add1[a]), end(add1[a]), b));
	add1[b].erase(std::find(begin(add1[b]), end(add1[b]), a));
	add1[a].push_back(c);
	add1[c].push_back(a);
#endif
}

struct List{
	std::vector<int> data;
	local(std::vector<int> someAdjacent;)

	List(){}
	List(int number): data(number)
					  local(
							  , someAdjacent(number, -1)
							  )
	{
		for(int i=0; i<number; ++i){
			assert(adjacent(i, -1));
			assert(step(-1, i)==-1);
		}
	}

	int step(int previous, int cur) const{
		assert(adjacent(cur, previous));
		assert(adjacent(cur, data[cur]^previous));
		return data[cur]^previous;
	}

	local(
	bool adjacent(int node, int other) const{
		return other==someAdjacent[node] or other==(data[node]^someAdjacent[node]);
	}
	)

	void link(int first, int sec){
		assert(adjacent(first, -1));
		assert(adjacent(sec, -1));
		local(someAdjacent[first]=sec; someAdjacent[sec]=first;)
		data[first]^=(-1)^sec;
		data[sec]^=(-1)^first;
		assert(adjacent(first, sec));
		assert(adjacent(sec, first));
	}
};

List list;

std::pair<int, int> work2(int const par, int const node){
	assert(list.adjacent(node, -1));

	assert(par>=0);
	assert(std::find(begin(add[node]), end(add[node]), par)!=add[node].end());
	assert(std::find(begin(add1[node]), end(add1[node]), par)!=add1[node].end());
	if(add[node].size()==1){
		assert(add1[node].size()==1);
		return {node, node};
	}

	int resultX=-1;
	auto par1=par;

	for(auto const child: add[node]) if(child!=par){
		auto const [x, y]=work2(node, child);
		operation(par1, node, y);
		if(resultX<0)
			resultX=y;
		else
			list.link(par1, y);
		par1=x;
	}
	list.link(par1, node);
	assert(list.adjacent(resultX, -1));
	assert(list.adjacent(node, -1));
	assert(([&]{
		int tmp=node, last=-1;
		while(tmp!=resultX) {
			std::tie(last, tmp)=std::pair(tmp, list.step(last, tmp));
			assert(tmp>=0);
		}
		return true;
	}()));

	assert(add1[node].size()==1);
	return {resultX, node};
}

void work(int node, int par){
	for(auto child: add[node]) if(child!=par){
		auto [x, y]=work2(node, child);
		child=-1;
		assert(list.adjacent(y, -1));
		assert(list.adjacent(x, -1));

		if(x!=y){
			int last=y, z=y;
			y=list.step(-1, y);
			while(y!=x){
				auto const a=list.step(last, y);
				operation(a, y, z);
				last=y; y=a;
			}
			operation(node, y, z);
		}
		
		
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number;
	add.clear();
	add.resize(number);
	for(int _=0; _<number-1; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back(sec);
		add[sec].push_back(first);
	}

	local(add1=add;)

	auto centroid=findCentroid();
	operations.clear();
	list=List(number);
	if(centroid.second<0){
		work(centroid.first, -1);
	}else{
		work(centroid.first, centroid.second);
		work(centroid.second, centroid.first);
	}

	std::cout<<operations.size()<<'\n';
	for(auto it: operations){
		for(auto it: it) std::cout<<it+1<<' ';
		std::cout<<'\n';
	}

}