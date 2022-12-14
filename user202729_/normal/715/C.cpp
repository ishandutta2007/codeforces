#define NDEBUG
#include<iostream>
#include<vector>
#include<cassert>
#include<unordered_map>
#include<algorithm>

struct ej{
	int node,digt; // digt == 0 if this is not a real edge
};

std::vector<std::vector<ej>> adjl;

void dfs1(int node){ // delete parent edge
	for(ej e:adjl[node]){
		auto& z=adjl[e.node];
		std::remove_if(begin(z),end(z),[=](ej x){return x.node==node;});
		z.pop_back();
		dfs1(e.node);
	}
}

void tobintree(int node){
#define z adjl[node]
	while(z.size()>2){
		ej a=z.back();z.pop_back();
		ej b=z.back();z.pop_back();
		int c=adjl.size(); // new node
		adjl.push_back({a,b});
		z.push_back({c,0});
	}
	for(ej e:z){
		tobintree(e.node);
		adjl[e.node].push_back({node,e.digt});
	}
#undef z
}

int compsize;

int x,y,sx,sy;
int dfs2(int node,int parent){
	// find the edge centroid of the tree and store it to (x,y,sx,sy)
	// return value = subtree size
	int stsize=1;
	for(ej e:adjl[node])if(e.node!=parent){
		stsize+=dfs2(e.node,node);
	}
	if(std::max(stsize,compsize-stsize)<=std::max(sx,sy)){
		x=node;y=parent;
		sx=stsize;sy=compsize-stsize;
	}
	return stsize;
}

int mod;
int64_t ans;
int inv10;

template<std::unordered_map<int,int>& tgtmap>
void dfs3(int node,int parent,
		int mult, // digit position
		int base, // multiplier per digit position
		int value,
		bool pointy){
	assert(value>=0&&value<mod);
	if(pointy)
		++tgtmap[value];
	for(ej e:adjl[node])if(e.node!=parent){
		if(e.digt){
			int nextmult=mult*(int64_t)base%mod;
			dfs3<tgtmap>(e.node,node,nextmult,base,
					(value+nextmult*(int64_t)e.digt)%mod,true);
		}else
			dfs3<tgtmap>(e.node,node,mult,base,value,false);
	}
}

std::unordered_map<int,int> upcnt,downcnt;

void ejctroiddec(int node){
	if(compsize==1)return;

	assert((x=-1));
	sx=sy=1000000000;
	{
		int z=dfs2(node,-1);
		assert(z==compsize);
	}
	assert(x!=-1);

	int digt;
	{
		auto iter=std::find_if(begin(adjl[x]),end(adjl[x]),[](ej f){return f.node==y;});
		digt=iter->digt;
		adjl[x].erase(iter);
		adjl[y].erase(
				std::find_if(begin(adjl[y]),end(adjl[y]),[](ej f){return f.node==x;}));
	}

	for(int _=0;_<2;++_,std::swap(x,y)){
		upcnt.clear();
		dfs3<upcnt>(x,y,digt?1:10%mod,inv10,0,(bool)digt);
		downcnt.clear();
		dfs3<downcnt>(y,x,1,10%mod,digt%mod,(bool)digt);

		for(auto p:upcnt){
			assert(0<=p.first&&p.first<mod);
			auto iter=downcnt.find((mod-p.first)%mod);
			if(iter!=downcnt.end())
				ans+=(int64_t)p.second*iter->second;
		}
	}

	int sy_=sy,y_=y;
	compsize=sx;
	ejctroiddec(x);
	compsize=sy_;
	ejctroiddec(y_);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrealnode;std::cin>>nrealnode>>mod;

	int64_t onemodmod=1;
	while(onemodmod%10!=0)onemodmod+=mod;
	inv10=onemodmod/10;

	adjl.resize(nrealnode);
	for(int _=nrealnode-1;_-->0;){
		int u,v,w;std::cin>>u>>v>>w;
		adjl[u].push_back({v,w});
		adjl[v].push_back({u,w});
	}
	dfs1(0);
	tobintree(0);

	compsize=adjl.size();
	ejctroiddec(0);

	std::cout<<ans<<'\n';
}