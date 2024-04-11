// time-limit: 2000
// problem-url: https://codeforces.com/contest/1566/problem/G

// is global round hard or is it because I wasted time implementing the Y combinator + figure out G solution before implementing F?
// end up losing virtual rating after all



#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>



struct Edge{
	int weight, dummy, a, b;

	auto t() const{return std::tie(weight, dummy);}

	auto allT() const{return std::tie(weight, dummy, a, b);}
	bool allEqual(Edge other) const{
		return allT()==other.allT();
	}

	bool operator==(Edge other) const{
		return t()==other.t();
	}
	bool operator<(Edge other) const{
		// reuse pbds's implementation of order statistics tree, but extremely large constant factor...


		return t()<other.t();
		//if(dummy>=0 and other.dummy>=0) return t()<other.t();
		//if(dummy==other.dummy) return false;
		//if(dummy<0) {
		//	assert(std::cerr<<"?");
		//	return not(other<*this);
		//}

		//
		//assert(false);
	}
};

auto& operator<<(std::ostream& stream, Edge ){
	return stream;
}

using Set = __gnu_pbds::tree<
  Edge,
  __gnu_pbds::null_type,
  std::less<Edge>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update>;




int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	int numEdge; std::cin>>numEdge;

	
	int dummy {};

	std::vector<Set> local(number); // node  edges with one endpoint at that node
	Set global; // all edges
	std::map<std::pair<int, int>, Edge> edgeOf;

	auto const addEdge=[&]{
		int u; std::cin>>u; --u;
		int v; std::cin>>v; --v;
		int weight; std::cin>>weight;
		Edge e{weight, dummy++, u, v};
		local[u].insert(e);
		local[v].insert(e);
		global.insert(e);
		auto const [iterator, inserted]=edgeOf.insert({std::minmax({u, v}), e});
		assert(inserted);
	};

	auto const removeSet=[&](Set& set, Edge edge){
		//set.erase(std::find(begin(set), end(set), edge));
		set.erase(set.find(edge));
	};

	auto const countLE=[&](Set const& set, Edge edge){
		auto iter=set.upper_bound(edge);
		if(iter==set.end()) return (int)set.size();
		return (int)set.order_of_key(*iter);
	};

	auto const removeEdge=[&]{
		int u; std::cin>>u; --u;
		int v; std::cin>>v; --v;
		auto const iterator=edgeOf.find(std::minmax({u, v}));
		auto const e=iterator->second;
		removeSet(local[u], e);
		removeSet(local[v], e);
		removeSet(global, e);
		edgeOf.erase(iterator);
	};

	for(int _=0; _<numEdge; ++_){
		addEdge();
	}

	auto const computeResult=[&]{
		auto const edge=*global.begin();
		auto const [minWeight, _, a, b]=edge;
		assert(local[a].begin()->allEqual(edge));
		assert(local[b].begin()->allEqual(edge));

		auto external=global.begin();
		if(0){
			while(external!=global.end() and (
						external->a==a or external->a==b or
						external->b==a or external->b==b
						)) ++external;
		}else{
			if(local[a].size()+local[b].size()-1==global.size()){
				external=global.end();
			}else{
				int index=1;
				for(int step=1<<30; step>>=1;) if([&](int index){
					if(index>=(int)global.size())
						return false;
					Edge p=*global.find_by_order(index-1);
					return countLE(local[a], p)+countLE(local[b], p)==index+1;
				}(index+step)){
					index+=step;
				}
				external=global.find_by_order(index);
			}
		}

		assert(external!=global.begin());
		int64_t result=INT64_MAX;
		if(external!=global.end()){
			result=std::min(result, external->weight+(int64_t)minWeight);
		}

		auto const get=[&](int x){
			assert(local[x].begin()->allEqual(edge));
			auto iter=local[x].begin();
			iter++;

			struct Item{int node; int64_t weight;};
			std::array<Item, 6> value; value.fill(Item{-1, INT64_MAX});

			for(int index=0; index<3; ++index){
				if(iter!=local[x].end()){
					value[index]={
						.node=iter->a+iter->b-x,
						.weight=iter->weight,
					};
					assert(x==iter->a or x==iter->b);
					iter++;
				}else break;
			}
			return value;
		};
		auto const c=get(a);
		auto const d=get(b);

		// how complex. Hopefully this is sufficient
		if(c[0].node>=0 and d[0].node>=0) {
			if(c[0].node!=d[0].node)
				result=std::min(result, c[0].weight+d[0].weight);
			else{
				if(d[1].node>=0)
					result=std::min(result, c[0].weight+d[1].weight);
				if(c[1].node>=0)
					result=std::min(result, c[1].weight+d[0].weight);
			}
		}
		if(c[1].node>=0) result=std::min(result, minWeight+c[0].weight+c[1].weight);
		if(d[1].node>=0) result=std::min(result, minWeight+d[0].weight+d[1].weight);

		return result;
	};

	std::cout<<computeResult()<<'\n';
	int numQuery; std::cin>>numQuery;
	for(int _=0; _<numQuery; ++_){
		char type; std::cin>>type;
		if(type=='0'){
			removeEdge();
		}else{
			addEdge();
		}
		std::cout<<computeResult()<<'\n';
	}

}