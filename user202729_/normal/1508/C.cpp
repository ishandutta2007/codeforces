#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct DSU{
	std::vector<int> p;
	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(int n){
		p.resize(n);
		while(n--)p[n]=n;
	}
	int root(int x){
		return p[x]!=x?p[x]=root(p[x]):x;
	}
	void join(int a,int b){ // let root(a) be the root
		p[root(b)]=root(a);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	int numGivenEdge; std::cin>>numGivenEdge;

	std::vector<std::map<int, int>> given(numNode);
	struct Edge{ int u, v, weight;
		bool operator<(Edge other) const{return weight<other.weight;}
	};
	std::vector<Edge> givenEdges(numGivenEdge);
	int xorEmpty{};
	for(auto& [u, v, weight]: givenEdges){
		std::cin>>u; --u;
		std::cin>>v; --v;
		std::cin>>weight;
		given[u][v]=given[v][u]=weight;
		xorEmpty^=weight;
	}

	DSU emptyComponents(numNode);

	//std::vector<std::vector<int>> components(numNode);
	//for(int node=0; node<numNode; ++node){
	//	components[node].push_back(node);
	//}

	// first find the connected components of the free edges
	// bfs
	std::vector<char> visited(numNode);
	std::set<int> unvisited;
	for(int node=0; node<numNode; ++node)
		unvisited.insert(unvisited.end(), node);

	int numComponent{};
	for(int startNode=0; startNode<numNode; ++startNode) if(not visited[startNode]){
		std::vector<int> component; component.push_back(startNode);
		++numComponent;
		for(int index=0; index<(int)component.size(); ++index){
			int curNode=component[index];
			for(auto iterator=unvisited.begin(); iterator!=unvisited.end(); ){
				int other=*iterator;
				assert(not visited[other]);
				if(not given[curNode].count(other)){ // free edge
					component.push_back(other);
					emptyComponents.join(startNode, other);
					visited[other]=true;
					iterator=unvisited.erase(iterator);
				}else
					iterator++;
			}
		}
	}
	
	for(auto it: visited) assert(it);

	int numEmptyRequiredForSpan=numNode-numComponent;
	int64_t numEmptyActual=(int64_t)numNode*(numNode-1)/2-numGivenEdge;

	assert(numEmptyActual>=0);
	assert(numEmptyActual>=numEmptyRequiredForSpan);

	int64_t givenSpanValue{};
	DSU dsu=emptyComponents;
	DSU givenOnSpan(numNode); // dsu of components formed by all the **given** edges that is on the (found) spanning tree
	std::sort(begin(givenEdges), end(givenEdges));
	for(auto [node, other, weight]: givenEdges)
		if(dsu.root(other)!=dsu.root(node)){
			dsu.join(other, node);
			givenOnSpan.join(other, node);
			givenSpanValue+=weight;
		}

	for(int node=0; node<numNode; ++node)
		assert(dsu.root(node)==dsu.root(0));

	int extraValue;
	if(numEmptyActual==numEmptyRequiredForSpan){
		// not all of those empty edges can be assigned zero
		extraValue=xorEmpty;
		for(auto [node, other, weight]: givenEdges)
			if(givenOnSpan.root(other)!=givenOnSpan.root(node)){
				extraValue=std::min(extraValue, weight);
				break;
			}
		// I guess this is correct...
		
	}else{
		extraValue=0;
	}

	std::cout<<givenSpanValue+extraValue<<'\n';
}