#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>

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

struct edge{
	int node,cost;
};
std::vector<std::vector<edge>> ad; // of any spanning tree
int ncell;

void dd(int x,int par){ // prints transfer plan. x must be already printed.
	for(auto [y,cost]:ad[x])if(y!=par){
		std::cout<<y+1<<' '<<(cost==ncell ? 0 : x+1)<<'\n';
		dd(y,x);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol,nlevel,deltacost;std::cin>>nrow>>ncol>>nlevel>>deltacost;
	ncell=nrow*ncol;
	
	std::vector<std::map<char,std::vector<int>>> value_to_index(ncell);
	// [cell position][character] = {level indices}
	for(int leveli=0;leveli<nlevel;++leveli){
		for(int celli=0;celli<ncell;++celli){
			char c;std::cin>>c;
			value_to_index[celli][c].push_back(leveli);
		}
	}

	std::vector<std::vector<int>> diff(nlevel,std::vector<int>(nlevel,ncell));
	for(auto const& x /* [character] = {level indices} */ :value_to_index)
		for(auto const& [c,levels]:x)
			for(auto a:levels) for(auto b:levels)
				--diff[a][b];

	DSU dsu(nlevel);
	ad.resize(nlevel);

	struct edge2{
		int x,y,cost;
		bool operator<(edge2 b)const{return cost<b.cost;}
	};
	std::vector<edge2> edges;edges.reserve(nlevel*(nlevel-1)/2);
	for(int i=nlevel;i--;) for(int j=i;j--;)
		edges.push_back({i,j,std::min(deltacost*diff[i][j],ncell)});
	std::sort(begin(edges),end(edges));

	int64_t totalcost=ncell;
	for(auto [x,y,cost]:edges){
		if(dsu.root(x)!=dsu.root(y)){
			dsu.join(x,y);
			ad[x].push_back({y,cost});ad[y].push_back({x,cost});
			totalcost+=cost;
		}
	}

	std::cout<<totalcost<<"\n1 0\n";
	dd(0,-1);
}