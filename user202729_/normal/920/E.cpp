
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

       
 #include<variant>
template<class EdgeValue=std::monostate>
struct Graph{
 struct EdgeCompound{
  int node; EdgeValue value;
 };
 static bool constexpr weightedEdge=not std::is_same_v<EdgeValue, std::monostate>;
 using Edge=std::conditional_t<weightedEdge, EdgeCompound, int>;
 std::vector<std::vector<Edge>> add;
 template<bool directed> void read(int numNode, int numEdge){
  assert(add.empty()); add.resize(numNode);
  for(int _=0;_<numEdge;++_){
   int first, sec; std::cin>>first>>sec;
   --first;--sec;
   if constexpr(weightedEdge){
    EdgeValue value; std::cin>>value;
    if(not directed)
     add[sec].push_back({first, value});
    add[first].push_back({sec, std::move(value)});
   }else{
    if(not directed)
     add[sec].push_back(first);
    add[first].push_back(sec);
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
	Graph graph; graph.readUndirected();
	for(auto & it: graph.add) std::sort(begin(it),end(it));

	std::vector<int> remaining(graph.add.size());
	std::iota(begin(remaining),end(remaining), 0);
	std::vector<int> numComponentWithSize(1+graph.add.size());
	std::vector<int> pending; pending.reserve(graph.add.size());
	while(not remaining.empty()){
		auto const oldSize=remaining.size();

		pending.clear();
		pending.push_back(remaining.back());
		remaining.pop_back();
		while(not pending.empty()){
			auto const node=pending.back(); pending.pop_back();
			std::set_difference(begin(remaining),end(remaining),
					begin(graph.add[node]),end(graph.add[node]), 
					std::back_inserter(pending));
			remaining.erase(
					std::set_intersection(begin(remaining),end(remaining),
						begin(graph.add[node]),end(graph.add[node]), begin(remaining)),
					end(remaining));
		}

		++numComponentWithSize[oldSize-remaining.size()];
	}
	std::cout<<std::accumulate(begin(numComponentWithSize),end(numComponentWithSize), 0)<<'\n';
	for(int size=0;size<(int)numComponentWithSize.size();++size) 
		for(auto _=numComponentWithSize[size];_--;)
			std::cout<<size<<' ';
	std::cout<<'\n';
}