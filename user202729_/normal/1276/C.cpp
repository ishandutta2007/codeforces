#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<numeric>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;
	std::sort(begin(a),end(a));

	struct num{
		int cnt,val;
	};
	std::vector<num> ns;ns.reserve(n);

	for(int i=1,lastend=0;i<=n;++i){
		if(i==n or a[i]!=a[i-1]){
			ns.push_back({i-lastend,a[i-1]});
			lastend=i;
		}
	}

	std::sort(begin(ns),end(ns),[](num a,num b){return a.cnt>b.cnt;});

	std::vector<int> nval(n+2);
	// assumes nrow <= ncol
	// nval[nrow] = sum {n in ns} min(n.cnt, nrow)
	for(auto [cnt,val]:ns){
		++nval[1];
		--nval[cnt+1];
	}
	for(unsigned i=1;i<nval.size();++i) nval[i]+=nval[i-1];
	for(unsigned i=1;i<nval.size();++i) nval[i]+=nval[i-1];

	std::pair<int,int> maxarea_nrow={0,0};
	for(int nrow=1;nrow<=n;++nrow){
		int ncol=nval[nrow]/nrow;
		if(nrow<=ncol and nrow*ncol>maxarea_nrow.first)
			maxarea_nrow={nrow*ncol,nrow};
	}

	int const nrow=maxarea_nrow.second;
	int const ncol=maxarea_nrow.first/nrow;

	std::cout<<nrow*ncol<<'\n'<<nrow <<' '<<ncol <<'\n';
	std::vector<std::vector<int>> t(nrow,std::vector<int>(ncol));

	for(auto& [cnt,val]:ns)
		cnt=std::min(cnt,nrow);

	auto iter=begin(ns);
	for(int group=0,g=std::gcd(nrow,ncol);group<g;++group){
		int r=0,c=group;

		do{
			if(iter->cnt==0)
				++iter;
			--iter->cnt;
			assert(t[r][c]==0);
			t[r][c]=iter->val;

			++r;++c;
			if(r==nrow)r=0;
			if(c==ncol)c=0;
		}while(r!=0 or c!=group);
	}

	for(auto const& row:t){
		for(int x:row)
			std::cout<<x<<' ';
		std::cout<<'\n';
	}

#ifdef _GLIBCXX_DEBUG
	std::cout<<std::flush;

	std::vector<std::vector<int>> tt(ncol,std::vector<int>(nrow));
	for(int r=0;r<nrow;++r)
	for(int c=0;c<ncol;++c)
		tt[c][r]=t[r][c];

	for(auto& row:t){
		std::sort(begin(row),end(row));
		assert(std::unique(begin(row),end(row))==end(row));
	}
	for(auto& col:tt){
		std::sort(begin(col),end(col));
		assert(std::unique(begin(col),end(col))==end(col));
	}
#endif
}