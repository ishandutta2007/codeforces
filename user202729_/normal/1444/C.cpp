// I **really** did consider this case in the solution.

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct UndoableBipartiteDsu{
 std::vector<int> data;
 bool isRoot(int node) const{return data[node]<0;}
 std::pair<int, bool> link(int node)const{
  assert(not isRoot(node));
  return {data[node]>>1, data[node]&1};
 }
 std::pair<int, bool> root(int node) const{
  bool flip{};
  while(not isRoot(node)){
   auto const [par, flip1]=link(node);
   node=par; flip^=flip1;
  }
  return {node, flip};
 }
 int rank(int node)const{
  assert(isRoot(node));
  return data[node];
 }
 UndoableBipartiteDsu(int number): data(number, -1){}
 struct Change{ int index, old; };
 std::vector<Change> changes;
 void set(int index, int newValue){
  changes.push_back({index, data[index]});
  data[index]=newValue;
 }
 enum class State{
  conflict,
  done,
  already,
 };
 State join(int a, int b, bool flip){
  auto const [a_, aflip]=root(a);
  auto const [b_, bflip]=root(b);
  flip^=aflip^bflip;
  a=a_; b=b_;
  if(a==b){
   if(flip) return State::conflict;
   return State::already;
  }else{
   if(rank(a)>rank(b)) std::swap(a, b);
   else if(rank(a)==rank(b)) set(a, data[a]-1);
   set(b, a<<1|flip);
   return State::done;
  }
 }
 std::size_t undoPos() const{return changes.size();}
 void undoTo(std::size_t pos){
  assert(changes.size()>=pos);
  while(changes.size()>pos){
   auto const [index, old]=changes.back(); changes.pop_back();
   data[index]=old;
  }
 }
};

int main(){
	if(0){
		UndoableBipartiteDsu dsu(3);
		assert(dsu.rank(0)==-1);
		assert(dsu.rank(1)==-1);
		assert(dsu.join(0, 1, true)==UndoableBipartiteDsu::State::done);
		assert(dsu.rank(0)==-2);
		assert(dsu.join(0, 1, true)==UndoableBipartiteDsu::State::already);
		assert(dsu.join(2, 1, true)==UndoableBipartiteDsu::State::done);
		assert(dsu.rank(0)==-2);
		return 0;
	}

	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	int numEdge; std::cin>>numEdge;
	int numGroup; std::cin>>numGroup;
	std::vector<int> groupOf(numNode);
	for(auto& it: groupOf) {
		std::cin>>it;
		--it;
	}
	

	std::map<
		std::pair<int, int>, // group ids
		std::vector<std::pair<int, int>>
			> edges;

	for(int _=0; _<numEdge; ++_){
		int a; std::cin>>a; --a;
		int b; std::cin>>b; --b;
		int x=groupOf[a], y=groupOf[b];
		edges[std::minmax({x, y})].push_back({a, b});
	}

	std::vector<char> bipartite(numGroup, true);
	UndoableBipartiteDsu dsu(numNode);

	for(auto const& [group, edges_]: edges) if(group.first==group.second){
		for(auto [a, b]: edges_)
			if(dsu.join(a, b, true)==UndoableBipartiteDsu::State::conflict){
				bipartite[group.first]=false;
				break; // this component no longer matters
			}
	}

	int64_t result=std::accumulate(begin(bipartite), end(bipartite), 0);
	result=result*(result-1)/2; // only consider unordered pairs of groups that both components are bipartite

	for(auto const& [group, edges_]: edges) if(group.first!=group.second and bipartite[group.first] and bipartite[group.second]){
		auto undoPos=dsu.undoPos();
		for(auto [a, b]: edges_)
			if(dsu.join(a, b, true)==UndoableBipartiteDsu::State::conflict){
				--result;
				break;
			}
		dsu.undoTo(undoPos);
	}

	std::cout<<result<<'\n';

}