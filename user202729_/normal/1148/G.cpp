// might TLE
// untested
// https://codeforces.com/contest/1285/submission/68525673 ?

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> computeMinimumFactor(int len){
 std::vector<int> result(len);
 for(int prime=2;prime<len;++prime) if(result[prime]==0) {
  result[prime]=prime;
  if((int64_t)prime*prime<len)
   for(int multiple=prime*prime;multiple<len;multiple+=prime)
    if(result[multiple]==0) result[multiple]=prime;
 }
 return result;
}
       
 #include<variant>
template<class EdgeValue=std::monostate>
struct Graph{
 struct EdgeCompound{
  int node; EdgeValue value;
 };
 static bool constexpr weightedEdge=not std::is_same_v<EdgeValue, std::monostate>;
 using Edge=std::conditional_t<weightedEdge, EdgeCompound, int>;
 std::vector<std::vector<Edge>> add;
 Graph(std::vector<std::vector<Edge>> add): add(std::move(add)){}
 Graph(int numNode): add(numNode){}
 Graph(){}
 template<bool directed> void addEdge(int first, int sec){
  static_assert(not weightedEdge);
  if(not directed)
   add[sec].push_back(first);
  add[first].push_back(sec);
 }
 template<bool directed> void addEdge(int first, int sec, EdgeValue value){
  static_assert(weightedEdge);
  if(not directed)
   add[sec].push_back({first, value});
  add[first].push_back({sec, std::move(value)});
 }
 template<bool directed> void read(int numNode, int numEdge){
  assert(add.empty()); add.resize(numNode);
  for(int _=0;_<numEdge;++_){
   int first, sec; std::cin>>first>>sec;
   --first;--sec;
   if constexpr(weightedEdge){
    EdgeValue value; std::cin>>value;
    addEdge<directed>(first, sec, value);
   }else{
    addEdge<directed>(first, sec);
   }
  }
 }
 void readUndirected(){
  int numNode, numEdge; std::cin>>numNode>>numEdge;
  read<false>(numNode, numEdge);
 }
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, resultSize; std::cin>>number>>resultSize;
	std::vector<int> values(number); for(auto & it: values) std::cin>>it;

	auto const minimumFactor=computeMinimumFactor(*std::max_element(begin(values),end(values))+1);
	std::vector<std::vector<int>> indicesWithFactor(minimumFactor.size());
	for(int index=0;index<number;++index) {
		auto tmp=values[index];
		while(tmp!=1){
			auto prime=minimumFactor[tmp];
			do tmp/=prime; while(tmp%prime==0);
			indicesWithFactor[prime].push_back(index);
		}
	}
	indicesWithFactor.erase(std::remove_if(begin(indicesWithFactor),end(indicesWithFactor),[&](auto const& it){
		return it.size()<=1;}), end(indicesWithFactor));

#if not LOCAL
	if(auto iterator=std::find_if(begin(indicesWithFactor),end(indicesWithFactor),[&](auto const& it){
		return (int)it.size()>=resultSize;
	}); iterator!=end(indicesWithFactor)){
		for(int index=0;index<resultSize;++index) std::cout<<(*iterator)[index]+1<<' ';
		std::cout<<'\n';
		return 0;
	}
#endif

	{ // reduce the value size, so the filter is more effective
		auto prime=0;
		std::fill(begin(values),end(values), 1);
		for(auto const& it: indicesWithFactor){
			do ++prime; while(minimumFactor[prime]!=prime);
			for(auto index: it) values[index]*=prime;
		} // after this there may be some numbers == 1
	}


	std::array<std::vector<int>, 100> coprime; // coprime[x] =
	// list of unvisited indices with value coprime with x (there's might be some visited vertices, those can be safely removed)
	for(int value=1;value<(int)coprime.size();++value) 
		for(int index=0;index<number;++index) if(std::gcd(values[index], value)==1)
			coprime[value].push_back(index);

	std::vector<int> pend(number);
	std::iota(begin(pend),end(pend), 0);
	std::vector<char> visited(number);
	Graph graph(number); // any spanning forest of the complement graph
	std::vector<std::vector<int>> components;
	while(not pend.empty()){
		std::vector<int> component{ pend.back() };
		pend.pop_back();
		if(visited[component[0]]) continue;
		visited[component[0]]=true;

		for(int queueFront=0;queueFront<(int)component.size();++queueFront) {
			auto const node=component[queueFront++];
			auto factorToFilter=1;
			for(auto tmp=values[node]; tmp>1; tmp/=minimumFactor[tmp])
				if(factorToFilter*minimumFactor[tmp]<(int)coprime.size())
					factorToFilter*=minimumFactor[tmp];

			auto& curList=coprime[factorToFilter];
			int curListIndex=0;
			while(curListIndex!=(int)curList.size()){
				auto& cur=curList[curListIndex];
				if(visited[cur]){ cur=curList.back(); curList.pop_back(); continue; }
				assert(std::gcd(factorToFilter, values[cur])==1);
				if(std::gcd(values[node], values[cur])==1){
					// adjacent in complement graph
					graph.addEdge<false>(node, cur);
					visited[cur]=true;
					component.push_back(cur);

					cur=curList.back(); curList.pop_back(); continue;
				}

				++curListIndex;
			}
		}
		components.push_back(std::move(component));

		if((int)components.size()==resultSize){
			for(auto const& it: components) std::cout<<1+it[0]<<' ';
			std::cout<<'\n';
			return 0;
		}
	}
	assert((int)components.size()<resultSize);

	std::swap(components.back(), *std::find_if(begin(components),end(components),[&](auto const& component){
		return component.size()>2;
	}));
	std::fill(begin(visited),end(visited), false);
	std::vector<int> queue; queue.reserve(number);
	for(auto const& component: components) if(component.size()>1) {
		assert(resultSize>=2);

		auto numPick=std::min((int)component.size(), resultSize);
		assert(numPick!=1);
		if(resultSize-numPick==1){
			--numPick;
			if(numPick==1) continue;
		}
		assert(numPick!=1 and resultSize-numPick!=1);

		auto node=component[0];
		queue.clear(); queue.push_back(node);
		visited[node]=true;
		std::cout<<1+node<<' ';
		assert(queue.capacity()==(std::size_t)number);
		for(auto iterator=begin(queue); ; ++iterator){
			for(auto other: graph.add[*iterator]) if(not visited[other]){
				visited[other]=true;
				queue.push_back(other);
				std::cout<<1+other<<' ';
				if((int)queue.size()==numPick) goto break_outer;
			}
		}
break_outer:
		resultSize-=numPick;
	}
	assert(resultSize==0);
	std::cout<<'\n';
}