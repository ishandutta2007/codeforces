#include<iostream>
#include<vector>
#include<queue>
#include<climits>

int main(){
   std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nedge,maxRetainEdge;
	std::cin>>nnode>>nedge>>maxRetainEdge;
	struct edge{int node,edgeIndex;int64_t weight;};
	std::vector<std::vector<edge>> adjl(nnode);
	for(int edgeIndex=1;edgeIndex<=nedge;++edgeIndex){
		int x,y,weight;
		std::cin>>x>>y>>weight;
		--x;--y;
		adjl[x].push_back({y,edgeIndex,weight});
		adjl[y].push_back({x,edgeIndex,weight});
	}

	maxRetainEdge=std::min(maxRetainEdge,nnode-1);
	std::cout<<maxRetainEdge<<'\n';
	if(maxRetainEdge==0)return 0; // edge case...
	std::vector<int64_t> dist(nnode,LLONG_MAX);
	std::vector<int> backEdge(nnode); // Dijkstra tree...
	struct state{
		int node;int64_t dist;
		bool operator<(state s)const{return dist>s.dist;}
	};
	std::priority_queue<state> pq;
	pq.push({0,dist[0]=0});
	while(!pq.empty()){
		state s=pq.top();pq.pop();
		if(dist[s.node]!=s.dist)continue;
		if(s.node!=0){
			std::cout<<backEdge[s.node]<<' ';
			if(0==--maxRetainEdge)break;
		}

		for(edge e:adjl[s.node])
			if(s.dist+e.weight<dist[e.node]){
				backEdge[e.node]=e.edgeIndex;
				pq.push({e.node,dist[e.node]=s.dist+e.weight});
			}
	}
	std::cout<<'\n';
}