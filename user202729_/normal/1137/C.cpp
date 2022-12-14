#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

std::vector<std::vector<int>> ad,rad;
std::vector<int> order;
std::vector<char> vis;
void dd(int node){
	if(vis[node])return;
	vis[node]=true;
	for(int x:rad[node])
		dd(x);
	order.push_back(node);
}

std::vector<std::string> open; // museum state

std::vector<int> comp; // currently considered connected component

int nnode,nedge,nday /* in week */;

std::vector<std::vector<int>> dp; // [node][day] = max distinct museum
int const UNVISITED=-2,VISITED=-1; // dp state.

void dd2(int node,int day){ // comp.size() * d (*d is not necessary, but the implementation is easier)
	if(not vis[node]){
		vis[node]=true;
		comp.push_back(node);
	}

	if(dp[node][day]==VISITED or dp[node][day]>=0 /* other comp */)
		return;

	assert(dp[node][day]==UNVISITED);
	dp[node][day]=VISITED;

	for(int x:ad[node])
		dd2(x,day+1==nday ? 0 : day+1);
}

std::vector<int> start; // hard to explain

void proccc(int node){
	if(vis[node])return;
	comp.clear();
	dd2(node,0);

	static std::vector<char> incmp;
	if(incmp.empty())incmp.resize(nnode);

	assert(std::find(begin(incmp),end(incmp),true)==end(incmp));

	for(int x:comp)incmp[x]=true;

	assert(dp[node][0]==VISITED);
	int period=int(std::find(1+begin(dp[node]),end(dp[node]),VISITED)-begin(dp[node]));
	assert(nday%period==0);

	for(int x:comp){
		start[x]=int(std::find(begin(dp[x]),end(dp[x]),VISITED)-begin(dp[x]));
		assert(start[x]<period);
	}
	assert(start[node]==0);

	for(int mod=0;mod<period;++mod){
		int maxdp=0, curcmp_nvisit=0;

		auto const stuff=dp[node][mod];

		for(int x:comp){
			bool visx=false;
			for(int day=(mod+start[x])%period;day<nday;day+=period){ // (1)
				assert(dp[x][day]==stuff);
				visx=visx or open[x][day];
				for(int y:ad[x]) // sum outdeg size * d
					if(not incmp[y]) // should not be necessary?
						maxdp=std::max(maxdp,dp[y][day+1==nday ? 0 : day+1]);
			}
			curcmp_nvisit+=visx;
		}

		for(int x:comp){
			for(int day=(mod+start[x])%period;day<nday;day+=period){ // (2)
				// I fixed (1) but forgot to fix (2). Took quite a while to debug...
				dp[x][day]=maxdp+curcmp_nvisit;
			}
		}

	}
	
	for(int x:comp)incmp[x]=false;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nnode>>nedge>>nday;
	ad.resize(nnode);
	rad.resize(nnode);
	for(int z=nedge;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		rad[v].push_back(u);
	}
	
	open.resize(nnode);
	for(auto& x:open){
		x.reserve(nday);
		std::cin>>x;
		for(char& c:x)c-='0';
		assert(x.size()==nday);
	}

	vis.assign(nnode,false);
	order.reserve(nnode);
	for(int x=nnode;x--;) dd(x);

	vis.assign(nnode,false);

	dp.resize(nnode);
	for(auto& dpi:dp) dpi.assign(nday,UNVISITED);
	start.resize(nnode);
	std::for_each(order.rbegin(),order.rend(),proccc);

	std::cout<<dp[0][0]<<'\n';
}