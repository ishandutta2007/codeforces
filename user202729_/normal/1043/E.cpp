#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

struct comp{ // etitor
	int x,y;
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ncomp,nxpair;std::cin>>ncomp>>nxpair;
	std::vector<comp> cs(ncomp);
	for(auto& [x,y]:cs) std::cin>>x>>y;

	auto const x_sub_y_less=[](comp a,comp b){ return a.x-a.y < b.x-b.y; };

	auto cs_clone=cs;
	std::sort(begin(cs_clone),end(cs_clone),x_sub_y_less);

	struct query{
		comp op; // score with (x1,y1) = min {x,y} ((x1,y1)-op)
		int ind;
	};
	std::vector<query> qs(ncomp);
	for(int i=0;i<ncomp;++i){
		qs[i].ind=i;
		qs[i].op={-cs[i].y,-cs[i].x};
	}
	std::sort(begin(qs),end(qs),[&](auto a,auto b){ return x_sub_y_less(a.op,b.op); });

	std::vector<int64_t> out(ncomp);

#define USE_SLOW 0

#if USE_SLOW
	out.assign(ncomp,0);
	for(auto [op,ind]:qs){
		for(int i1=0;i1<ncomp;++i1)if(i1!=ind)
			out[ind]+=std::min(cs[i1].x-op.x,cs[i1].y-op.y); // SLOW
	}
#else
	//out.assign(ncomp,0xDEADCAFE);

	int64_t sumx=0,sumy=0;
	int nx=0,ny=ncomp;
	for(auto [x,y]:cs_clone) sumy+=y;
	auto iter=begin(qs);
	for(auto [x,y]:cs_clone){
		// now sumx = sum of x values of points strictly before this point (int x-y increasing order)
		// sumy = sum of y values of points at >= this point
		while(true){
			if(iter==end(qs))
				goto break_outer;
			if(x_sub_y_less({x,y},iter->op))
				break;
			out[iter->ind]=
				sumx-iter->op.x*(int64_t)nx+
				sumy-iter->op.y*(int64_t)ny;
			++iter;
		}

		sumx+=x;sumy-=y;
		++nx;--ny;
	}
	assert(sumy==0 and nx==ncomp and ny==0);

	while(iter!=end(qs)){
		out[iter->ind]=
			sumx-iter->op.x*(int64_t)nx+
			sumy-iter->op.y*(int64_t)ny;
		++iter;
	}
break_outer:

	for(int i=0;i<ncomp;++i)
		out[i]-=cs[i].x+cs[i].y; // Forgot this, took too long to debug...
#endif

	for(int z=nxpair;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		int teamscore=std::min(cs[u].x+cs[v].y,cs[u].y+cs[v].x);
		out[u]-=teamscore;out[v]-=teamscore;
	}

	for(auto x:out)std::cout<<x<<' ';
	std::cout<<'\n';
}