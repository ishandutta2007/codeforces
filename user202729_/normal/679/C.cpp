#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<numeric>
#include<cassert>
#include<string>
#include<vector>
#include<iostream>

int n,k;
std::vector<std::string> s; // input table, empty = 1

int toint(int x,int y){return x*n+y;}
std::pair<int,int> topair(int z){return {z/n,z%n};}

struct DSU{
	std::vector<int> par;
	DSU(int n):par(n){
		while(n--)par[n]=n;
	}
	int root(int x){return par[x]!=x?par[x]=root(par[x]):x;}
	void join(int u,int v){
		u=root(u);
		v=root(v);
		par[u]=v;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>k;

	s.resize(n);
	for(auto& r:s){
		r.reserve(n);std::cin>>r;
		for(char& c:r)c=(c=='.');
	}

	DSU dd(n*n);

	for(int r=1;r<n;++r)
	for(int c=0;c<n;++c)
		if(s[r-1][c] and s[r][c])
			dd.join(toint(r-1,c),toint(r,c));

	for(int r=0;r<n;++r)
	for(int c=1;c<n;++c)
		if(s[r][c-1] and s[r][c])
			dd.join(toint(r,c-1),toint(r,c));

	struct comp{
		int sz,xl,xr,yl,yr;
	};
	std::vector<comp> cs(n*n,{0,INT_MAX,0,INT_MAX,0});

	for(int r=0;r<n;++r)
	for(int c=0;c<n;++c)
		if(s[r][c]){
			comp& cp=cs[dd.root(toint(r,c))];
			cp={cp.sz+1,
				std::min(cp.xl,r),std::max(cp.xr,r),
				std::min(cp.yl,c),std::max(cp.yr,c)};
		}

	std::vector<std::vector<int>> sum_inner(n+1,std::vector<int>(n+1)); // placeholder 1 row x 1 col
	for(comp const cp:cs){
		auto [sz,xl,xr,yl,yr]=cp;
		if(sz==0)continue;
		int nr=xr-xl+1;
		int nc=yr-yl+1;
		if(nr<=k&&nc<=k){
			auto x1=std::max(0,xr+1-k);
			auto x2=xl+1;
			auto y1=std::max(0,yr+1-k);
			auto y2=yl+1;

			sum_inner[x1][y1]+=sz;
			sum_inner[x1][y2]-=sz;
			sum_inner[x2][y1]-=sz;
			sum_inner[x2][y2]+=sz;
		}
	}

	for(int r=0;r<n;++r)
		sum_inner[r].resize(n);
	sum_inner.resize(n);

	for(int r=1;r<n;++r)
	for(int c=0;c<n;++c)
		sum_inner[r][c]+=sum_inner[r-1][c];

	for(int r=0;r<n;++r)
	for(int c=1;c<n;++c)
		sum_inner[r][c]+=sum_inner[r][c-1];

	std::vector<char> mark(n*n);
	int ans=0;
	for(int r=0;r<n-k+1;++r){
		int c=0;

		int nblack=0;
		for(int r1=r;r1<r+k;++r1) // note that s counts white so it's necessary to compute compl.
			nblack+=k-std::accumulate(begin(s[r1]),begin(s[r1])+k,0);

		while(c<n-k+1){
			// foreach_adjacent_outer (r,c)
			int total_outer_white=0;

			auto const foreach_adjacent_outer=[&](auto f){
				for(int r1=r;r1<r+k;++r1){
					if(c)
						f(r1,c-1);
					if(c+k<n)
						f(r1,c+k);
				}
				for(int c1=c;c1<c+k;++c1){
					if(r)
						f(r-1,c1);
					if(r+k<n)
						f(r+k,c1);
				}
			};

			foreach_adjacent_outer([&](int r1,int c1){
				auto rt=dd.root(toint(r1,c1));
				if(!mark[rt]){
					mark[rt]=true;
					total_outer_white+=cs[rt].sz;
				}
			});

			ans=std::max(ans,total_outer_white+nblack+sum_inner[r][c]);

			foreach_adjacent_outer([&](int r1,int c1){
				auto rt=dd.root(toint(r1,c1));
				mark[rt]=false;
			});




			for(int r1=r;r1<r+k;++r1){
				nblack-=!s[r1][c];
				nblack+=!s[r1][c+k];
			}
			++c;
		}
	}
	std::cout<<ans<<'\n';
}