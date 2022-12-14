#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int n,k;
struct edge{
	int node,weight;
};
std::vector<std::vector<edge>> ad;

struct result_t{
	int64_t ansk,ansk1;
};

// dfs(node): result of subtree rooted at node, with node adj to at most k|k-1 edges
result_t dfs(int node,int par){
	std::vector<int64_t> connwts;connwts.reserve(ad[node].size()-(par>=0));
	// weight - (ansk - ansk1)
	int64_t sum_ansk=0;

	for(edge e:ad[node])if(e.node!=par){
		auto tmp=dfs(e.node,node);

		assert(tmp.ansk>=tmp.ansk1);
		sum_ansk+=tmp.ansk;

		int64_t conn_wt=e.weight + tmp.ansk1-tmp.ansk;
		if(conn_wt>0) // connect edge to node increases the total value
			connwts.push_back(conn_wt);
	}

	if((int)connwts.size()>k-1)
		std::nth_element(begin(connwts),end(connwts)-k,end(connwts));

	// now sum last k-1 elems = max sum <= k-1 elems
	// and sum last k elems = max sum <= k elems
	result_t ans;
	auto sum_max_k_1_connwt=
		std::accumulate(end(connwts)-std::min(k-1,int(connwts.size())),
				end(connwts),0LL);
	auto sum_max_k_connwt=sum_max_k_1_connwt;
	if((int)connwts.size()>=k)
		sum_max_k_connwt+=connwts.end()[-k];

	ans.ansk1=sum_ansk+sum_max_k_1_connwt;
	ans.ansk=sum_ansk+sum_max_k_connwt;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int q;std::cin>>q;
	while(q--){
		std::cin>>n>>k;
		ad.clear();ad.resize(n);
		for(int z=n-1;z--;){
			int u,v,w;std::cin>>u>>v>>w;
			--u;--v;
			ad[u].push_back({v,w});
			ad[v].push_back({u,w});
		}
		std::cout<<dfs(0,-1).ansk<<'\n';
	}
}