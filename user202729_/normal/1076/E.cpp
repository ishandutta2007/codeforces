#include<iostream>
#include<vector>

std::vector<std::vector<int>> adjl;
struct query{int depth,delta;};
std::vector<std::vector<query>> queries;
std::vector<int64_t> netDelta,result;

void dfs(int node,int parent,int depth,int64_t value){
	for(query q:queries[node]){
		netDelta[depth]+=q.delta;
		if(depth+q.depth+1u<netDelta.size())
			netDelta[depth+q.depth+1]-=q.delta;
	}

	value+=netDelta[depth];
	result[node]=value;
	for(int adj:adjl[node])if(adj!=parent)
		dfs(adj,node,depth+1,value);

	for(query q:queries[node]){ // reverse the loop above
		netDelta[depth]-=q.delta;
		if(depth+q.depth+1u<netDelta.size())
			netDelta[depth+q.depth+1]+=q.delta;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode;std::cin>>nnode;
	adjl.resize(nnode);
	for(int _=nnode-1;_-->0;){
		int x,y;std::cin>>x>>y;--x;--y;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}

	int nqueries;std::cin>>nqueries;
	queries.resize(nnode);
	for(int _=nqueries;_-->0;){
		int node,depth,delta;
		std::cin>>node>>depth>>delta;--node;
		queries[node].push_back({depth,delta});
	}

	result.resize(nnode);
	netDelta.resize(nnode);
	dfs(0,-1,0,0);
	for(auto x:result)std::cout<<x<<' ';
	std::cout<<'\n';
}