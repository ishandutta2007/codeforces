#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>

std::vector<std::vector<int>> ad;

int n;
int thres; // all st of centroid must be <= this value
std::vector<int> sts_;
std::vector<int> par_;

int find(int x,int par){ // return stsize
	par_[x]=par;
	int& sts=sts_[x];
	sts=1;
	bool ok=true;
	for(int y:ad[x])if(y!=par){
		int sub=find(y,x);
		sts+=sub;
		ok&=sub<=thres;
	}
	if(ok&&(n-sts)<=thres)
		throw x;
	return sts;
}

int const max_val=1000000;

std::vector<char> filled;

int fill(int x,int par,int d_par,int d_last,int mul){
	// assume d_x is not added
	// return new d_last
	int const d_x=d_last+mul;
	int const edge_len=d_x-d_par;
	assert(edge_len>=0);
	if(edge_len>max_val)
		return d_last;

	d_last+=mul;
	assert(!filled[x]);
	std::cout<<par+1<<' '<<x+1<<' '<<edge_len<<'\n';
	filled[x]=true;
	for(int y:ad[x])if(y!=par){
		d_last=fill(y,x,d_x,d_last,mul);
	}
	return d_last;
}

void dfs2(int x,int par){
	if(!filled[x]){
		filled[x]=true;
		std::cout<<par+1<<' '<<x+1<<" 1\n";
	}
	for(int y:ad[x])if(y!=par){
		dfs2(y,x);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;
	if(n==1)return 0;
	ad.resize(n);
	for(int i=n-1;i--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	thres=n/2;
	int x=-1;
	sts_.resize(n);
	par_.resize(n);
	try{
		find(0,-1);
	}catch(int centroid){
		x=centroid;
	}

	int const req=2*n*n/9;

	if(par_[x]>=0)
		sts_[par_[x]]=n-sts_[x]-1;
	std::sort(begin(ad[x]),end(ad[x]),[](int a,int b){
			return sts_[a]>sts_[b];
			});

	filled.resize(n);

	// try to divide fairly ad[x] into two buckets
	int nleft=(n-1)/2;
	std::vector<int> b1,b2;
	for(int y:ad[x])
		if(sts_[y]<=nleft){
			nleft-=sts_[y];
			b1.push_back(y);
		}else
			b2.push_back(y);

// int fill(int x,int par,int d_par,int d_last,int mul){
	int d_last=0;
	for(int y:b1)
		d_last=fill(y,x,0,d_last,1);
	int const mul=d_last+1;
	d_last=0;
	for(int y:b2)
		d_last=fill(y,x,0,d_last,mul);

	for(int y:ad[x])
		dfs2(y,x);


	std::cout<<std::flush;
	assert(d_last+mul-1>=req);
}