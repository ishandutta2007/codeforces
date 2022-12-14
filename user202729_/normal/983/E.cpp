// [I didn't read the editorial or see any failed test cases]
//
// Seen the standings int the contest. People mostly solve E instead of D.
//
// Fortunately the sample test cases are strong.
//
// WA on test 3?...
// Remember: shuffle the vertices order.
// (at least int this case it isn't necessary to find the wrong test case)

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

std::vector<std::vector<int>> ad;

std::vector<int> depth,par,first,last;
int num=0;
void dd(int x){ // dfs compute depth and par, prepare for init_jt
	first[x]=num++;
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		par[y]=x;
		depth[y]=depth[x]+1;
		dd(y);
	}
	last[x]=num;
}

std::vector<std::vector<int>> jt;
void init_jt(){
	jt.push_back(par);
	for(;;){
		bool useful=false;
		auto const& a=jt.back();
		auto b=a;
		for(auto& x:b)if(x>=0){
			if((x=a[x])>=0)
				useful=true;
		}
		if(useful)
			jt.push_back(std::move(b));
		else
			break;
	}
}

std::vector<std::vector<int>> mindepthanc; // LCA style update. ancestor with min depth
// reachable with one bus route. Final result: at least (current node). -1: none.

int lca(int u,int v){
	assert(u!=v);

	bool swapped;
	if((swapped=(depth[u]<depth[v])))std::swap(u,v);

	int ddepth=depth[u]-depth[v];
	if(ddepth){
		--ddepth;
		for(;ddepth;ddepth^=ddepth&-ddepth){
			u=jt[__builtin_ctz(ddepth)][u];
		}
		assert(depth[u]-1==depth[v]);
		if(jt[0][u]==v)return v;
		u=jt[0][u];
	}
	assert(u!=v);
	for(auto layer=jt.size();layer--;){
		if(jt[layer][u]!=jt[layer][v])
			std::tie(u,v)=std::make_pair(jt[layer][u],jt[layer][v]);
	}
	assert(jt[0][u]==jt[0][v]);
	return jt[0][u];
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode;std::cin>>nnode;
	ad.resize(nnode);
	for(int i=1,par_i;i<nnode;++i){
		std::cin>>par_i; --par_i;
		ad[i].push_back(par_i); ad[par_i].push_back(i);
	}
	depth.resize(nnode); par.resize(nnode);
	first.resize(nnode); last.resize(nnode);
	num=0;
	par[0]=-1; dd(0);
	assert(num==nnode);

	struct WaveletTree{
		std::vector<std::vector<int>> val;
		WaveletTree(int n):val(2*n){}
		void add(int x,int y){
			x+=int(val.size()/2);
			val[x].push_back(y);
		}
		void build(){
			int const n=int(val.size()/2);
			for(int x=n;x--;) std::sort(begin(val[x+n]),end(val[x+n]));
			for(int x=n;--x;){
				auto const& s1=val[x*2],s2=val[x*2+1];
				val[x].resize(s1.size()+s2.size());
				auto iter=std::merge(begin(s1),end(s1),begin(s2),end(s2),begin(val[x]));
				assert(iter==end(val[x]));
			}
		}
		int get(int l,int r,int subl,int subr)const{ // O(n log^2 n), could be O(n log n) with sweep line
			int out=0;
			auto const process=[&](auto const& node){
				out+=int(lower_bound(begin(node),end(node),subr)-lower_bound(begin(node),end(node),subl));
			};
			l+=int(val.size()/2);
			r+=int(val.size()/2);
			while(l<r){
				if(l&1) process(val[l++]);
				if(r&1) process(val[--r]);
				l>>=1;r>>=1;
			}
			return out;
		}
	};
	WaveletTree vt(nnode);

	int nbus;std::cin>>nbus;
	std::vector<std::pair<int,int>> buses(nbus);

	auto const update_mindepthanc=[](int& item,int node){
		if(item<0 or depth[node]<depth[item])
			item=node;
	};

	init_jt();
	mindepthanc.assign(jt.size(),std::vector<int>(nnode,-1));
	for(auto& [l,r]:buses){
		std::cin>>l>>r;
		--l;--r;
		assert(l!=r);
		if(first[l]>first[r]) std::swap(l,r);

		auto w=lca(l,r);

		for(int x:{l,r}){
			int ddepth=depth[x]-depth[w];
			for(;ddepth;ddepth^=ddepth&-ddepth){
				update_mindepthanc(mindepthanc[__builtin_ctz(ddepth)][x],w);
				x=jt[__builtin_ctz(ddepth)][x];
			}
			assert(x==w);
		}
		// update_mindepthanc(mindepthanc[0][w],w); // not necessary

		vt.add(first[l],first[r]);
	}
	vt.build();

	// compute final value of mindepthanc
	while(mindepthanc.size()>1){
		for(int node=nnode;node--;){
			auto const cur=mindepthanc.back()[node];
			if(cur>=0){
				update_mindepthanc(mindepthanc.end()[-2][node],cur);
				update_mindepthanc(mindepthanc.end()[-2][jt[mindepthanc.size()-2][node]],cur);
			}
		}
		mindepthanc.pop_back();
	}
	for(int node=nnode;node--;) if(mindepthanc[0][node]==node) mindepthanc[0][node]=-1;

	std::vector<std::vector<int>> busjt=std::move(mindepthanc);
	for(;;){
		bool useful=false;
		auto const& a=busjt.back();
		auto b=a;
		for(auto& x:b)if(x>=0){
			if((x=a[x])>=0)
				useful=true;
		}
		if(useful)
			busjt.push_back(std::move(b));
		else
			break;
	}

	int nquery;std::cin>>nquery;
	for(int z=nquery;z--;){
		int u,v;std::cin>>u>>v;
		--u;--v;
		if(first[u]>first[v]) std::swap(u,v);
		int w=lca(u,v);
		int out=0;
		for(auto px:{&u,&v}){
			auto& x=*px;
			for(auto layer=busjt.size();layer--;){
				int x1=busjt[layer][x];
				if(x1>=0 and depth[x1]>depth[w]){
					out+=1<<layer;
					x=x1;
				}
			}
			assert(depth[x]>=depth[w]);
		}

		if(u!=w or v!=w){
			if(u!=w and busjt[0][u]<0) out=-1;
			else if(v!=w and busjt[0][v]<0) out=-1;
			else if(u==w or v==w)++out;
			else{
				assert(last[u]<=first[v]);
				if(vt.get(first[u],last[u],first[v],last[v])!=0)
					out+=1;
				else
					out+=2;
			}
		}

		std::cout<<out<<'\n';
	}
}