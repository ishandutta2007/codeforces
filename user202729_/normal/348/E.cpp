// Took about 56 minutes to implement + (???) minutes to debug
// NOTE:
// 1. [done] print the computation details when the output data is much smaller than the computed data
// 2. Always double check the code after fixing a bug. There's no TKPWARPT that fixing a bug will not introduce other...
//
// [I didn't read the editorial or see any failed test cases]

#ifndef LOCAL
#define NDEBUG
#endif
#include<tuple>
#include<climits>
#include<queue>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>
#include<array>

struct edge{
	 int x,dist;
};
std::vector<std::vector<edge>> ad;

std::vector<char> mon;
std::vector<std::array<edge,2>> dp; // {farthest node with a monastery, dist to that node} - exclude parent
// store 2 candidates to different branches

std::vector<edge> par;
std::vector<int> postorder;

template<bool store> // store dp and (par for all node != root)
std::array<edge,2> farthestnode(int x,int parx){
	std::array<edge,2> ans{{ {-1,-1},{-1,-1} }};
	if(mon[x])
		ans[0]={x,0};

	for(auto [y,elen]:ad[x])if(y!=parx){
		if(store)
			par[y]={x,elen};

		auto [z,dist]=farthestnode<store>(y,x)[0];
		if(dist>=0){
			dist+=elen;
			if(dist>ans[1].dist){
				ans[1]={z,dist};
				if(ans[1].dist>ans[0].dist)
					std::swap(ans[0],ans[1]);
			}
		}
	}
	if(store){
		dp[x]=ans;
		postorder.push_back(x);
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nmon;std::cin>>n>>nmon;
	assert(n>nmon and nmon>=2);
	mon.resize(n);
	for(int z=nmon,x;z--;){
		std::cin>>x;--x;
		assert(not mon[x]);
		mon[x]=true;
	}

	ad.resize(n);
	for(int z=n,u,v,w;--z;){
		std::cin>>u>>v>>w;--u;--v;
		ad[u].push_back({v,w});
		ad[v].push_back({u,w});
	}
	assert(std::cin);

	int root=farthestnode<false>(0,-1)[0].x;
	dp.resize(n);
	par.resize(n);
	postorder.reserve(n);
	auto [y,diam]=farthestnode<true>(root,-1)[0];
	assert((int)postorder.size()==n);
	assert(mon[root]);
	assert(mon[y]);

	int xb=-1; // the lowest node int the upper half (contains root)
	// such that there are multiple branches not go to y with same farthest == dist to root
	int yb=-1;


	// bfs from the diameter to all nodes
	struct st{
		int node,base;
	};
	std::queue<st> sts;
	std::vector<char> visited(n);
	std::vector<int> dx_minus_dy_of(n,INT_MIN); // only meaningful with nodes on root..y


	int dx=diam,dy=0,node=y;
	while(true){
		assert(dp[node][0].dist==dy);
		auto const d1=dp[node][1].dist;

		assert(d1<=std::min(dx,dy));
		assert(dx>=0 and dy>=0 and dx+dy==diam);
		if(dx*2<=diam and d1==dx){ // upper half
			if(xb<0)xb=node;
		}
		if(dy*2<=diam and d1==dy){ // lower half
			yb=node;
		}
		dx_minus_dy_of[node]=dx-dy;

		sts.push({node,node});
		visited[node]=true;

		// goto next node
		if(node==root){
			assert(dx==0);
			assert(dy==diam);
			break;
		}
		auto [nnode,elen]=par[node];
		std::tie(node,dx,dy)=std::make_tuple(nnode,dx-elen,dy+elen);
	}
	if(xb<0)xb=root;
	if(yb<0)yb=y;

	std::vector<int> val(n);
	while(not sts.empty()){
		auto [node,base]=sts.front();sts.pop();

		assert(dx_minus_dy_of[base]!=INT_MIN);
		if(mon[node]){
			if(dx_minus_dy_of[base]>0){ // lower half
				++val[node];
				if(xb!=root) --val[par[xb].x];
			}else if(dx_minus_dy_of[base]==0){
				assert(root!=y);
				assert(root!=base);

				++val[node];
				--val[par[base].x];
			}else{
				++val[node]; ++val[yb];
				--val[base];
				if(base!=root) --val[par[base].x];
			}
		}

		for(auto [x,_]:ad[node])if(not visited[x]){
			visited[x]=true;
			sts.push({x,base});
		}
	}
	// currently: number of unhappy when destroy x = sum val y for y int subtree of x
	assert(postorder.back()==root);
	assert(std::all_of(begin(visited),end(visited),[](char x){return x;}));
	postorder.pop_back();
	for(auto z:postorder)
		val[par[z].x]+=val[z];

	for(int z=n;z--;)
		if(mon[z])
			val[z]=-1;
	int max=*std::max_element(begin(val),end(val));

	for(auto x:val)assert(std::cerr <<x<<' ');
	assert(std::cerr <<'\n');

	assert(max>=0);
	std::cout<<max<<' '<<std::count(begin(val),end(val),max)<<'\n';
}